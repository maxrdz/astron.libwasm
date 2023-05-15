/*
 * Copyright (c) 2014, Astron Contributors. All rights reserved.
 * Copyright (c) 2023, Max Rodriguez. All rights reserved.
 *
 * All use of this software is subject to the terms of the revised BSD
 * license. You should have received a copy of this license along
 * with this source code in a file named "COPYING".
 *
 * @file Logger.hxx
 * @author Astron Contributors
 * @date 2023-04-30
 */

#ifndef ASTRON_LIBWASM_LOGGER_HXX
#define ASTRON_LIBWASM_LOGGER_HXX

#include <stdarg.h>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <memory>
#include <mutex>

// The LogSeverity represents the importance and usage of a log message.
// LogSeverities advance numerically such that a more important severity is
// always greater than less important severities.
enum LogSeverity {
    // Packet log messages containing a dump (sometimes human-readable) of
    // a Datagram or packet sent between one or more daemons, daemon components, or clients.
    LSEVERITY_PACKET,
    // Trace log messages provide output that tracks the execution flow of the daemon.
    LSEVERITY_TRACE,
    // Debug log messages provide output that tends to print out local value for debugging,
    // or may be like trace output in execution paths that tend not to run (but are also not errors).
    LSEVERITY_DEBUG,
    // Info log messages provide status output for single-time or rarely occurring events.
    // Typically, this means setup/initialization as well as destruction/exit messages.
    LSEVERITY_INFO,
    // Warning log messages occur when the daemon detects a circumstance which should probably not
    // occur but is also not strictly erroneous.  Typically, these messages are indicative of a
    // larger problem which may need to be fixed either in the Application logic or in Astron.
    // Within a production environment, proper application-logic should not output any warnings.
    LSEVERITY_WARNING,
    // Security log messages occur when the ClientAgent (or --much less often-- another role),
    // detects that an event has occurred that is suspicious or indicative of hacking behavior.
    // Typically, this means an attacker has sent a custom packet that would not have come from
    // normal game logic. In production, a client that is behaving as expected should never yield
    // a security warning.
    LSEVERITY_SECURITY,
    // Error log messages occur when the daemon detects a circumstance that should never occur
    // during normal operation. This almost always indicates a bug that needs to be fixed
    // within the application's logic.  Error log messages are caught and handled, and do not
    // cause the Daemon to stop.
    LSEVERITY_ERROR,
    // Fatal log messages occur when the daemon detects an error and cannot continue operation.
    LSEVERITY_FATAL
};

// Forward declarations
class NullStream;
class NullBuffer;
class Logger;

// Extern variables
extern std::unique_ptr<Logger> g_logger; // forward declaration from "global.h"
extern NullStream null_stream;
extern NullBuffer null_buffer;

// A LoggerBuf is a stream buffer that outputs to either a file or the console (std::cout).
class LoggerBuf : public std::streambuf {
public:
    LoggerBuf();
    LoggerBuf(const std::string &file_name, bool output_to_console = true);

protected:
    int overflow(int c = EOF);
    std::streamsize xsputn(const char* s, std::streamsize n);
private:
#ifdef __EMSCRIPTEN__
    std::string m_output;
#endif // __EMSCRIPTEN__
    std::ofstream m_file;
    bool m_has_file;
    bool m_output_to_console;
};

class LockedLogOutput {
public:
#ifndef __EMSCRIPTEN__
    LockedLogOutput(std::ostream *stream, std::recursive_mutex *lock) : m_stream(stream), m_lock(lock) {
        if (m_lock) {
            m_lock->lock();
        }
    }
#else
    LockedLogOutput(std::string *output, std::recursive_mutex *lock) : m_output(output), m_lock(lock) {
        if (m_lock) {
            m_lock->lock();
        }
    }
#endif // __EMSCRIPTEN__

#ifndef __EMSCRIPTEN__
    LockedLogOutput(const LockedLogOutput& other) : m_stream(other.m_stream), m_lock(other.m_lock) {
        if (m_lock) {
            m_lock->lock();
        }
    }
#else
    LockedLogOutput(const LockedLogOutput& other) : m_output(other.m_output), m_lock(other.m_lock) {
        if (m_lock) {
            m_lock->lock();
        }
    }
#endif // __EMSCRIPTEN__

    LockedLogOutput& operator=(const LockedLogOutput&) = delete;   // non copyable

    ~LockedLogOutput() {
        if(m_lock) {
            m_lock->unlock();
        }
    }

    template <typename T>
    LockedLogOutput &operator<<(const T &x) {
#ifndef __EMSCRIPTEN__
        if (m_stream) {
            *m_stream << x;
        }
#else
        if (m_output) {
            m_output->append(x);
        }
#endif // __EMSCRIPTEN__
        return *this;
    }

    LockedLogOutput& operator<<(std::ostream & (*pf)(std::ostream&)) {
#ifndef __EMSCRIPTEN__
        if (m_stream) {
            *m_stream << pf;
        }
#else
        if (m_output) {
            std::ostringstream ss;
            ss << pf;
            std::string temp = ss.str();
            m_output->append(temp);
        }
#endif // __EMSCRIPTEN__
        return *this;
    }

    LockedLogOutput& operator<<(std::basic_ios<char>& (*pf)(std::basic_ios<char>&)) {
#ifndef __EMSCRIPTEN__
        if (m_stream) {
            *m_stream << pf;
        }
#endif // __EMSCRIPTEN__
        return *this;
    }

private:
#ifndef __EMSCRIPTEN__
    std::ostream *m_stream;
#else
    std::string *m_output;
#endif // __EMSCRIPTEN__
    std::recursive_mutex *m_lock;
};

// A Logger is an object that allows configuration of the output destination of log messages.
// It provides a stream as an output mechanism.
class Logger {
public:
    Logger(const std::string &log_file, LogSeverity sev, bool console_output = true);
    Logger();

    // log returns an output stream for C++ style stream operations.
    LockedLogOutput log(LogSeverity sev);

    // set_color_enabled turns ANSI colorized output on or off.
    void set_color_enabled(bool enabled);

    // set_min_serverity sets the lowest severity that will be output to the log.
    // Messages with lower severity levels will be discarded.
    void set_min_severity(LogSeverity sev);

    // get_min_severity returns the current minimum severity that will be logged by the logger.
    LogSeverity get_min_severity();

#ifdef __EMSCRIPTEN__
    void js_console_log();
#endif // __EMSCRIPTEN__

private:
    const char* get_severity_color(LogSeverity sev);

    LoggerBuf m_buf;
    LogSeverity m_severity;
#ifndef __EMSCRIPTEN__
    std::ostream m_output;
#else
    std::string m_output;
#endif // __EMSCRIPTEN__
    std::recursive_mutex m_lock;
    bool m_color_enabled;
};

// A LogCategory is a wrapper for a Logger object that specially formats the output
// for consistency, parsability, and ease of convenience with LogSeverities.
class LogCategory {
public:
    LogCategory(const std::string &id, const std::string &name) : m_id(id), m_name(name) {
    }

    LogCategory(const char* id, const std::string &name) : m_id(id), m_name(name) {
    }

    LogCategory(const char* id, const char* name) : m_id(id), m_name(name) {
    }

    void set_name(const std::string &name) {
        m_name = name;
    }

#define F(level, severity) \
	LockedLogOutput level() \
	{ \
		LockedLogOutput out = g_logger->log(severity); \
		out << m_name << ": "; \
		return out; \
	}

#ifndef NDEBUG
    // packet() provides a stream with the time and "PACKET" severity preprended to the message.
    // packet messages are only output when compiled with -DCMAKE_BUILD_TYPE=Debug.
    F(packet, LSEVERITY_PACKET)
    // trace() provides a stream with the time and "TRACE" severity preprended to the message.
    // trace messages are only output when compiled with -DCMAKE_BUILD_TYPE=Debug.
    F(trace, LSEVERITY_TRACE)
    // debug() provides a stream with the time and "DEBUG" severity preprended to the message.
    // trace messages are only output when compiled with -DCMAKE_BUILD_TYPE=Debug.
    F(debug, LSEVERITY_DEBUG)
#else
    // packet() provides a stream with the time and "PACKET" severity preprended to the message.
    // packet messages are only output when compiled with -DCMAKE_BUILD_TYPE=Debug.
    inline NullStream &packet() {
        return null_stream;
    }
    // trace() provides a stream with the time and "TRACE" severity preprended to the message.
    // trace messages are only output when compiled with -DCMAKE_BUILD_TYPE=Debug.
    inline NullStream &trace() {
        return null_stream;
    }
    // debug() provides a stream with the time and "DEBUG" severity preprended to the message.
    // debug messages are only output when compiled with -DCMAKE_BUILD_TYPE=Debug.
    inline NullStream &debug() {
        return null_stream;
    }

#endif
    // info() provides a stream with the time and "INFO" severity preprended to the message.
    // info messages are filtered with severity LSEVERITY_INFO.
    F(info, LSEVERITY_INFO)
    // warning() provides a stream with the time and "WARNING" severity preprended to the message.
    // warning messages are filtered with severity LSEVERITY_WARNING.
    F(warning, LSEVERITY_WARNING)
    // security() provides a stream with the time and "SECURITY" severity preprended to the message.
    // secutity messages are filtered with severity LSEVERITY_SECURITY.
    F(security, LSEVERITY_SECURITY)
    // error() provides a stream with the time and "ERROR" severity preprended to the message.
    // error messages are filtered with severity LSEVERITY_ERROR.
    F(error, LSEVERITY_ERROR)
    // fatal() provides a stream with the time and "FATAL" severity preprended to the message.
    // fatal messages are filtered with severity LSEVERITY_FATAL.
    F(fatal, LSEVERITY_FATAL)

#undef F

private:
    std::string m_id;
    std::string m_name;
};



/* ========================== *
 *       HELPER CLASSES       *
 * ========================== */
// NullBuffer is used to make streams that log in cases when we do not
// want to compile the message out (for example, when the LogSeverity is configurable)
class NullBuffer : public std::streambuf {
public:
    int overflow(int c) {
        return c;
    }
};

// NullStream is used with pre-processor definitions to define a stream that when
// logged to, will be reduced to a no-op and compiled out.
class NullStream {
public:
    void setFile() {
        /* no-op */
    }
    template<typename TPrintable>
    inline NullStream& operator<<(TPrintable const&) {
        return null_stream;
    }
    inline NullStream& operator<<(std::ostream & (std::ostream&)) {
        return null_stream;
    }
};
#endif //ASTRON_LIBWASM_LOGGER_HXX
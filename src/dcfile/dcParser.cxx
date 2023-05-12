/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 6 "dcParser.yxx"

#include "dcLexerDefs.h"
#include "dcParserDefs.h"
#include "dcFile.h"
#include "dcClass.h"
#include "dcSwitch.h"
#include "dcAtomicField.h"
#include "dcMolecularField.h"
#include "dcClassParameter.h"
#include "dcSwitchParameter.h"
#include "dcArrayParameter.h"
#include "dcSimpleParameter.h"
#include "dcTypedef.h"
#include "dcKeyword.h"
#include "dcPacker.h"
#include "dcNumericRange.h"

// Because our token type contains objects of type string, which
// require correct copy construction (and not simply memcpying), we
// cannot use bison's built-in auto-stack-grow feature.  As an easy
// solution, we ensure here that we have enough yacc stack to start
// with, and that it doesn't ever try to grow.
#define YYINITDEPTH 1000
#define YYMAXDEPTH 1000

DCFile *dc_file = (DCFile *)NULL;
static DCClass *current_class = (DCClass *)NULL;
static DCSwitch *current_switch = (DCSwitch *)NULL;
static DCAtomicField *current_atomic = (DCAtomicField *)NULL;
static DCMolecularField *current_molecular = (DCMolecularField *)NULL;
static DCParameter *current_parameter = (DCParameter *)NULL;
static DCKeywordList current_keyword_list;
static DCPacker default_packer;
static DCPacker *current_packer;
static DCDoubleRange double_range;
static DCUnsignedIntRange uint_range;
static DCField *parameter_description = (DCField *)NULL;

////////////////////////////////////////////////////////////////////
// Defining the interface to the parser.
////////////////////////////////////////////////////////////////////

void
dc_init_parser(istream &in, const string &filename, DCFile &file) {
  dc_file = &file;
  dc_init_lexer(in, filename);
}

void
dc_init_parser_parameter_value(istream &in, const string &filename,
                               DCPacker &packer) {
  dc_file = NULL;
  current_packer = &packer;
  dc_init_lexer(in, filename);
  dc_start_parameter_value();
}

void
dc_init_parser_parameter_description(istream &in, const string &filename,
                                     DCFile *file) {
  dc_file = file;
  dc_init_lexer(in, filename);
  parameter_description = NULL;
  dc_start_parameter_description();
}

DCField *
dc_get_parameter_description() {
  return parameter_description;
}

void
dc_cleanup_parser() {
  dc_file = (DCFile *)NULL;
}


#line 149 "dcParser.cxx"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "dcParser.hxx"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_UNSIGNED_INTEGER = 3,           /* UNSIGNED_INTEGER  */
  YYSYMBOL_SIGNED_INTEGER = 4,             /* SIGNED_INTEGER  */
  YYSYMBOL_REAL = 5,                       /* REAL  */
  YYSYMBOL_STRING = 6,                     /* STRING  */
  YYSYMBOL_HEX_STRING = 7,                 /* HEX_STRING  */
  YYSYMBOL_IDENTIFIER = 8,                 /* IDENTIFIER  */
  YYSYMBOL_KEYWORD = 9,                    /* KEYWORD  */
  YYSYMBOL_KW_DCLASS = 10,                 /* KW_DCLASS  */
  YYSYMBOL_KW_STRUCT = 11,                 /* KW_STRUCT  */
  YYSYMBOL_KW_FROM = 12,                   /* KW_FROM  */
  YYSYMBOL_KW_IMPORT = 13,                 /* KW_IMPORT  */
  YYSYMBOL_KW_TYPEDEF = 14,                /* KW_TYPEDEF  */
  YYSYMBOL_KW_KEYWORD = 15,                /* KW_KEYWORD  */
  YYSYMBOL_KW_SWITCH = 16,                 /* KW_SWITCH  */
  YYSYMBOL_KW_CASE = 17,                   /* KW_CASE  */
  YYSYMBOL_KW_DEFAULT = 18,                /* KW_DEFAULT  */
  YYSYMBOL_KW_BREAK = 19,                  /* KW_BREAK  */
  YYSYMBOL_KW_INT8 = 20,                   /* KW_INT8  */
  YYSYMBOL_KW_INT16 = 21,                  /* KW_INT16  */
  YYSYMBOL_KW_INT32 = 22,                  /* KW_INT32  */
  YYSYMBOL_KW_INT64 = 23,                  /* KW_INT64  */
  YYSYMBOL_KW_UINT8 = 24,                  /* KW_UINT8  */
  YYSYMBOL_KW_UINT16 = 25,                 /* KW_UINT16  */
  YYSYMBOL_KW_UINT32 = 26,                 /* KW_UINT32  */
  YYSYMBOL_KW_UINT64 = 27,                 /* KW_UINT64  */
  YYSYMBOL_KW_FLOAT64 = 28,                /* KW_FLOAT64  */
  YYSYMBOL_KW_STRING = 29,                 /* KW_STRING  */
  YYSYMBOL_KW_BLOB = 30,                   /* KW_BLOB  */
  YYSYMBOL_KW_BLOB32 = 31,                 /* KW_BLOB32  */
  YYSYMBOL_KW_INT8ARRAY = 32,              /* KW_INT8ARRAY  */
  YYSYMBOL_KW_INT16ARRAY = 33,             /* KW_INT16ARRAY  */
  YYSYMBOL_KW_INT32ARRAY = 34,             /* KW_INT32ARRAY  */
  YYSYMBOL_KW_UINT8ARRAY = 35,             /* KW_UINT8ARRAY  */
  YYSYMBOL_KW_UINT16ARRAY = 36,            /* KW_UINT16ARRAY  */
  YYSYMBOL_KW_UINT32ARRAY = 37,            /* KW_UINT32ARRAY  */
  YYSYMBOL_KW_UINT32UINT8ARRAY = 38,       /* KW_UINT32UINT8ARRAY  */
  YYSYMBOL_KW_CHAR = 39,                   /* KW_CHAR  */
  YYSYMBOL_START_DC = 40,                  /* START_DC  */
  YYSYMBOL_START_PARAMETER_VALUE = 41,     /* START_PARAMETER_VALUE  */
  YYSYMBOL_START_PARAMETER_DESCRIPTION = 42, /* START_PARAMETER_DESCRIPTION  */
  YYSYMBOL_43_ = 43,                       /* ';'  */
  YYSYMBOL_44_ = 44,                       /* '/'  */
  YYSYMBOL_45_ = 45,                       /* '.'  */
  YYSYMBOL_46_ = 46,                       /* '*'  */
  YYSYMBOL_47_ = 47,                       /* ','  */
  YYSYMBOL_48_ = 48,                       /* '{'  */
  YYSYMBOL_49_ = 49,                       /* '}'  */
  YYSYMBOL_50_ = 50,                       /* ':'  */
  YYSYMBOL_51_ = 51,                       /* '('  */
  YYSYMBOL_52_ = 52,                       /* ')'  */
  YYSYMBOL_53_ = 53,                       /* '='  */
  YYSYMBOL_54_ = 54,                       /* '%'  */
  YYSYMBOL_55_ = 55,                       /* '-'  */
  YYSYMBOL_56_ = 56,                       /* '['  */
  YYSYMBOL_57_ = 57,                       /* ']'  */
  YYSYMBOL_YYACCEPT = 58,                  /* $accept  */
  YYSYMBOL_grammar = 59,                   /* grammar  */
  YYSYMBOL_dc = 60,                        /* dc  */
  YYSYMBOL_slash_identifier = 61,          /* slash_identifier  */
  YYSYMBOL_import_identifier = 62,         /* import_identifier  */
  YYSYMBOL_import = 63,                    /* import  */
  YYSYMBOL_64_1 = 64,                      /* $@1  */
  YYSYMBOL_import_symbol_list_or_star = 65, /* import_symbol_list_or_star  */
  YYSYMBOL_import_symbol_list = 66,        /* import_symbol_list  */
  YYSYMBOL_typedef_decl = 67,              /* typedef_decl  */
  YYSYMBOL_keyword_decl = 68,              /* keyword_decl  */
  YYSYMBOL_keyword_decl_list = 69,         /* keyword_decl_list  */
  YYSYMBOL_dclass_or_struct = 70,          /* dclass_or_struct  */
  YYSYMBOL_dclass = 71,                    /* dclass  */
  YYSYMBOL_72_2 = 72,                      /* @2  */
  YYSYMBOL_dclass_name = 73,               /* dclass_name  */
  YYSYMBOL_dclass_derivation = 74,         /* dclass_derivation  */
  YYSYMBOL_dclass_base_list = 75,          /* dclass_base_list  */
  YYSYMBOL_dclass_fields = 76,             /* dclass_fields  */
  YYSYMBOL_dclass_field = 77,              /* dclass_field  */
  YYSYMBOL_struct = 78,                    /* struct  */
  YYSYMBOL_79_3 = 79,                      /* @3  */
  YYSYMBOL_struct_name = 80,               /* struct_name  */
  YYSYMBOL_struct_derivation = 81,         /* struct_derivation  */
  YYSYMBOL_struct_base_list = 82,          /* struct_base_list  */
  YYSYMBOL_struct_fields = 83,             /* struct_fields  */
  YYSYMBOL_struct_field = 84,              /* struct_field  */
  YYSYMBOL_atomic_field = 85,              /* atomic_field  */
  YYSYMBOL_86_4 = 86,                      /* @4  */
  YYSYMBOL_parameter_list = 87,            /* parameter_list  */
  YYSYMBOL_nonempty_parameter_list = 88,   /* nonempty_parameter_list  */
  YYSYMBOL_atomic_element = 89,            /* atomic_element  */
  YYSYMBOL_named_parameter = 90,           /* named_parameter  */
  YYSYMBOL_91_5 = 91,                      /* $@5  */
  YYSYMBOL_unnamed_parameter = 92,         /* unnamed_parameter  */
  YYSYMBOL_named_parameter_with_default = 93, /* named_parameter_with_default  */
  YYSYMBOL_94_6 = 94,                      /* $@6  */
  YYSYMBOL_unnamed_parameter_with_default = 95, /* unnamed_parameter_with_default  */
  YYSYMBOL_96_7 = 96,                      /* $@7  */
  YYSYMBOL_parameter = 97,                 /* parameter  */
  YYSYMBOL_parameter_with_default = 98,    /* parameter_with_default  */
  YYSYMBOL_parameter_or_atomic = 99,       /* parameter_or_atomic  */
  YYSYMBOL_parameter_description = 100,    /* parameter_description  */
  YYSYMBOL_simple_type_name = 101,         /* simple_type_name  */
  YYSYMBOL_type_name = 102,                /* type_name  */
  YYSYMBOL_double_range = 103,             /* double_range  */
  YYSYMBOL_uint_range = 104,               /* uint_range  */
  YYSYMBOL_type_definition = 105,          /* type_definition  */
  YYSYMBOL_parameter_definition = 106,     /* parameter_definition  */
  YYSYMBOL_char_or_uint = 107,             /* char_or_uint  */
  YYSYMBOL_small_unsigned_integer = 108,   /* small_unsigned_integer  */
  YYSYMBOL_small_negative_integer = 109,   /* small_negative_integer  */
  YYSYMBOL_signed_integer = 110,           /* signed_integer  */
  YYSYMBOL_unsigned_integer = 111,         /* unsigned_integer  */
  YYSYMBOL_number = 112,                   /* number  */
  YYSYMBOL_char_or_number = 113,           /* char_or_number  */
  YYSYMBOL_parameter_value = 114,          /* parameter_value  */
  YYSYMBOL_115_8 = 115,                    /* $@8  */
  YYSYMBOL_parameter_actual_value = 116,   /* parameter_actual_value  */
  YYSYMBOL_117_9 = 117,                    /* $@9  */
  YYSYMBOL_118_10 = 118,                   /* $@10  */
  YYSYMBOL_119_11 = 119,                   /* $@11  */
  YYSYMBOL_array = 120,                    /* array  */
  YYSYMBOL_maybe_comma = 121,              /* maybe_comma  */
  YYSYMBOL_array_def = 122,                /* array_def  */
  YYSYMBOL_type_token = 123,               /* type_token  */
  YYSYMBOL_keyword_list = 124,             /* keyword_list  */
  YYSYMBOL_no_keyword_list = 125,          /* no_keyword_list  */
  YYSYMBOL_molecular_field = 126,          /* molecular_field  */
  YYSYMBOL_127_12 = 127,                   /* $@12  */
  YYSYMBOL_atomic_name = 128,              /* atomic_name  */
  YYSYMBOL_molecular_atom_list = 129,      /* molecular_atom_list  */
  YYSYMBOL_optional_name = 130,            /* optional_name  */
  YYSYMBOL_switch = 131,                   /* switch  */
  YYSYMBOL_132_13 = 132,                   /* @13  */
  YYSYMBOL_switch_fields = 133,            /* switch_fields  */
  YYSYMBOL_switch_case = 134,              /* switch_case  */
  YYSYMBOL_135_14 = 135,                   /* $@14  */
  YYSYMBOL_switch_default = 136,           /* switch_default  */
  YYSYMBOL_switch_break = 137,             /* switch_break  */
  YYSYMBOL_switch_field = 138,             /* switch_field  */
  YYSYMBOL_empty = 139                     /* empty  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  57
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   430

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  58
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  82
/* YYNRULES -- Number of rules.  */
#define YYNRULES  190
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  282

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   297


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    54,     2,     2,
      51,    52,    46,     2,    47,    55,    45,    44,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    50,    43,
       2,    53,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    56,     2,    57,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    48,     2,    49,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   168,   168,   169,   170,   177,   178,   179,   190,   196,
     197,   198,   202,   203,   210,   211,   218,   223,   222,   230,
     231,   238,   242,   249,   267,   271,   272,   276,   287,   288,
     293,   292,   304,   327,   328,   332,   338,   352,   353,   354,
     367,   377,   378,   386,   397,   396,   408,   431,   432,   436,
     442,   451,   452,   453,   464,   471,   472,   476,   484,   483,
     501,   502,   506,   507,   511,   521,   520,   531,   535,   537,
     536,   565,   567,   566,   595,   596,   600,   601,   605,   609,
     616,   620,   624,   631,   635,   644,   660,   675,   676,   708,
     724,   743,   747,   754,   761,   770,   776,   782,   793,   797,
     804,   811,   818,   824,   830,   839,   840,   851,   856,   871,
     886,   893,   902,   906,   917,   931,   935,   939,   943,   947,
     951,   960,   965,   969,   968,   983,   987,   991,   995,   999,
    1004,  1003,  1012,  1011,  1020,  1019,  1027,  1033,  1039,  1045,
    1054,  1055,  1059,  1060,  1064,  1065,  1069,  1073,  1077,  1081,
    1085,  1089,  1093,  1097,  1101,  1105,  1109,  1113,  1117,  1121,
    1125,  1129,  1133,  1137,  1141,  1145,  1152,  1156,  1163,  1173,
    1172,  1183,  1210,  1216,  1230,  1234,  1239,  1238,  1251,  1252,
    1253,  1254,  1255,  1256,  1270,  1269,  1290,  1299,  1306,  1310,
    1316
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "UNSIGNED_INTEGER",
  "SIGNED_INTEGER", "REAL", "STRING", "HEX_STRING", "IDENTIFIER",
  "KEYWORD", "KW_DCLASS", "KW_STRUCT", "KW_FROM", "KW_IMPORT",
  "KW_TYPEDEF", "KW_KEYWORD", "KW_SWITCH", "KW_CASE", "KW_DEFAULT",
  "KW_BREAK", "KW_INT8", "KW_INT16", "KW_INT32", "KW_INT64", "KW_UINT8",
  "KW_UINT16", "KW_UINT32", "KW_UINT64", "KW_FLOAT64", "KW_STRING",
  "KW_BLOB", "KW_BLOB32", "KW_INT8ARRAY", "KW_INT16ARRAY", "KW_INT32ARRAY",
  "KW_UINT8ARRAY", "KW_UINT16ARRAY", "KW_UINT32ARRAY",
  "KW_UINT32UINT8ARRAY", "KW_CHAR", "START_DC", "START_PARAMETER_VALUE",
  "START_PARAMETER_DESCRIPTION", "';'", "'/'", "'.'", "'*'", "','", "'{'",
  "'}'", "':'", "'('", "')'", "'='", "'%'", "'-'", "'['", "']'", "$accept",
  "grammar", "dc", "slash_identifier", "import_identifier", "import",
  "$@1", "import_symbol_list_or_star", "import_symbol_list",
  "typedef_decl", "keyword_decl", "keyword_decl_list", "dclass_or_struct",
  "dclass", "@2", "dclass_name", "dclass_derivation", "dclass_base_list",
  "dclass_fields", "dclass_field", "struct", "@3", "struct_name",
  "struct_derivation", "struct_base_list", "struct_fields", "struct_field",
  "atomic_field", "@4", "parameter_list", "nonempty_parameter_list",
  "atomic_element", "named_parameter", "$@5", "unnamed_parameter",
  "named_parameter_with_default", "$@6", "unnamed_parameter_with_default",
  "$@7", "parameter", "parameter_with_default", "parameter_or_atomic",
  "parameter_description", "simple_type_name", "type_name", "double_range",
  "uint_range", "type_definition", "parameter_definition", "char_or_uint",
  "small_unsigned_integer", "small_negative_integer", "signed_integer",
  "unsigned_integer", "number", "char_or_number", "parameter_value", "$@8",
  "parameter_actual_value", "$@9", "$@10", "$@11", "array", "maybe_comma",
  "array_def", "type_token", "keyword_list", "no_keyword_list",
  "molecular_field", "$@12", "atomic_name", "molecular_atom_list",
  "optional_name", "switch", "@13", "switch_fields", "switch_case", "$@14",
  "switch_default", "switch_break", "switch_field", "empty", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-127)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-176)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       8,  -127,   104,   359,    35,   128,  -127,  -127,  -127,    20,
    -127,    22,    28,  -127,  -127,  -127,    37,    53,  -127,  -127,
      54,   139,   139,  -127,  -127,  -127,  -127,  -127,  -127,  -127,
    -127,  -127,  -127,  -127,  -127,  -127,  -127,  -127,  -127,  -127,
    -127,  -127,  -127,  -127,  -127,    95,    97,  -127,  -127,  -127,
       2,  -127,    26,  -127,   100,  -127,  -127,  -127,   139,   145,
     145,   391,  -127,  -127,  -127,  -127,  -127,  -127,  -127,  -127,
    -127,   151,   151,  -127,    24,    24,    24,   151,   151,  -127,
    -127,   108,   152,  -127,  -127,  -127,  -127,  -127,  -127,   151,
     127,    98,    64,   154,  -127,  -127,  -127,   119,    13,   120,
    -127,  -127,  -127,  -127,   106,  -127,  -127,  -127,  -127,   122,
    -127,  -127,   115,  -127,   121,  -127,   114,   110,  -127,  -127,
     124,   359,  -127,   104,   104,  -127,  -127,  -127,    12,  -127,
    -127,  -127,    14,  -127,  -127,  -127,    16,     7,  -127,  -127,
    -127,     1,   391,   125,   161,  -127,   145,  -127,  -127,  -127,
    -127,   104,  -127,  -127,  -127,   164,   129,  -127,  -127,  -127,
    -127,  -127,   130,  -127,  -127,   127,  -127,   127,  -127,    64,
    -127,  -127,    64,  -127,   151,    98,    64,   131,   133,  -127,
    -127,  -127,   168,   136,  -127,  -127,     6,   119,  -127,  -127,
    -127,   134,  -127,   137,    33,  -127,    19,  -127,  -127,  -127,
      43,  -127,   391,  -127,  -127,   140,  -127,  -127,   119,  -127,
     141,   164,   291,  -127,  -127,   127,  -127,    64,  -127,  -127,
    -127,   168,   325,  -127,   145,  -127,    69,  -127,  -127,   143,
    -127,  -127,  -127,  -127,  -127,  -127,  -127,  -127,  -127,  -127,
     146,  -127,  -127,  -127,  -127,   119,  -127,  -127,  -127,  -127,
    -127,  -127,   257,  -127,  -127,   152,   152,   152,  -127,   186,
    -127,   147,  -127,  -127,  -127,  -127,  -127,  -127,  -127,   153,
     155,  -127,  -127,   156,   104,  -127,  -127,  -127,   186,   149,
    -127,  -127
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,   190,     0,   190,     0,     2,     5,   116,   115,   127,
     128,   129,     0,   130,   134,   132,   125,   126,     3,   122,
      88,   190,   190,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,   159,   160,   161,   162,
     163,   164,   165,    89,   190,    68,    71,   190,   190,     4,
      87,   105,    67,    83,     0,    90,   174,     1,   190,     0,
       0,     0,   190,     6,     9,    10,    11,     7,    28,    29,
       8,     0,     0,   123,   190,   190,   190,     0,     0,   175,
      44,     0,   168,    80,   166,    69,    72,    82,    81,     0,
     190,     0,   190,     0,    58,    30,    12,    14,     0,    16,
      88,    76,    77,    23,    24,    25,   113,   138,   139,     0,
     143,   144,     0,   140,   190,   142,     0,     0,   136,   137,
     190,   190,   167,     0,     0,    85,   119,   120,     0,   118,
     117,   121,    92,    91,    86,   111,     0,    99,   112,    98,
     107,    66,   190,   190,     0,    17,     0,    26,    27,   124,
     131,   143,   141,   135,   133,     0,     0,    47,    79,    74,
      75,    78,     0,    70,    73,     0,    84,     0,    94,     0,
     106,   114,     0,   101,     0,     0,   190,     0,    61,    62,
      64,    60,     0,     0,    33,    13,     0,    15,   145,    46,
      49,    48,   190,     0,    95,    93,   102,   100,   108,   109,
       0,    59,     0,    32,    35,    34,   190,    20,    21,    18,
      19,     0,   190,    51,   176,     0,    97,     0,   104,   110,
      63,     0,   190,    37,     0,    50,    88,    52,    45,     0,
     190,   190,   190,   190,   190,    96,   103,    36,    38,    31,
       0,   190,   190,   190,   190,    22,   169,    53,    54,    57,
      56,    55,     0,   178,    39,    40,    43,    42,    41,     0,
     184,     0,   187,   179,   177,   189,   188,   180,   181,     0,
       0,   171,   172,   170,     0,   186,   182,   183,     0,     0,
     173,   185
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -127,  -127,  -127,  -126,   142,  -127,  -127,  -127,  -127,  -127,
    -127,  -127,  -127,  -127,  -127,   -21,  -127,  -127,  -127,  -127,
     196,  -127,    -6,  -127,  -127,  -127,  -127,  -116,  -127,  -127,
    -127,     4,    86,  -127,    87,    -1,  -127,     0,  -127,  -127,
     157,  -127,  -127,  -127,  -127,  -127,    34,  -127,  -127,  -125,
     -56,    17,   -81,   -78,   -90,  -124,    -2,  -127,   105,  -127,
    -127,  -127,    60,   102,  -127,  -127,   -85,   -40,    -5,  -127,
     -59,  -127,    18,   215,  -127,  -127,  -127,  -127,  -127,  -127,
    -127,     3
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     4,     5,    97,    98,    64,   186,   209,   210,    65,
      66,   104,    67,    68,   143,   204,   183,   205,   222,   240,
      43,   120,   190,   156,   191,   212,   229,    44,   142,   177,
     178,   179,    45,    93,    46,   101,   123,   102,   124,   161,
     180,   162,    49,    50,    51,   128,   136,    52,   141,   137,
     138,   173,    16,    17,   131,   132,   111,   109,    19,    74,
      76,    75,   112,   113,   114,    53,    82,    83,   233,   259,
     272,   273,    54,    55,   234,   252,   267,   274,   268,   269,
     270,    84
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      18,   134,    47,    48,     6,   158,    56,    87,    88,   129,
     129,   171,   130,   130,    96,   107,   108,     7,     8,   126,
     187,   118,   119,   171,    56,    56,   145,     7,     8,     9,
      10,    11,    12,   125,   -65,    57,     7,     8,   126,    80,
      81,   194,   168,   195,   196,   174,    89,   197,     1,     2,
       3,   129,   207,    90,   130,   175,    91,   176,   146,   165,
     208,    56,   172,   169,   166,   105,    71,   106,    72,   167,
     135,   110,    13,   170,   217,    14,    95,   115,   115,   115,
      15,    73,    92,    77,   129,   199,   129,   130,   215,   130,
     169,   235,   236,   133,   129,   139,   230,   130,   245,    78,
     219,     7,     8,   126,   216,  -175,   241,     7,     8,     9,
      10,    11,    12,   129,   147,   148,   130,   115,   198,   246,
    -175,   163,   164,   157,    56,     7,     8,     9,    10,    11,
       7,     8,   126,   127,   129,   116,   117,   130,    58,    21,
      59,    60,    61,    62,    22,   181,   184,    79,    85,   188,
      86,    94,    13,    96,   106,    14,   255,   256,   257,   121,
      15,   122,   140,   144,   150,   146,   153,   154,   151,   185,
      13,    63,   189,    14,   155,   182,   203,   192,    15,   139,
     202,   211,   193,   201,   206,   214,   247,   221,   224,   254,
     248,   249,   250,   251,   271,   213,   276,   275,   277,   281,
     237,    69,    99,   278,   258,   225,   220,   159,   160,   223,
     200,   231,   232,   218,   149,    56,   152,   244,   103,   280,
      70,   242,   243,     0,     0,    56,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   253,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   265,   266,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   100,     0,     0,    21,     0,
       0,     0,   279,    22,   260,   261,   262,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,     0,     0,   226,
     263,     0,    21,     0,     0,     0,   264,    22,     0,     0,
       0,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,     0,     0,   226,   227,     0,    21,     0,     0,     0,
     228,    22,     0,     0,     0,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,     0,     0,    20,   238,     0,
      21,     0,     0,     0,   239,    22,     0,     0,     0,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,   100,
       0,     0,    21,     0,     0,     0,     0,    22,     0,     0,
       0,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42
};

static const yytype_int16 yycheck[] =
{
       2,    91,     3,     3,     1,   121,     3,    47,    48,    90,
      91,     4,    90,    91,     8,    71,    72,     3,     4,     5,
     146,    77,    78,     4,    21,    22,    13,     3,     4,     5,
       6,     7,     8,    89,     8,     0,     3,     4,     5,    21,
      22,   165,   132,   167,   169,    44,    44,   172,    40,    41,
      42,   132,    46,    51,   132,    54,    54,    56,    45,    47,
     186,    58,    55,    47,    52,    62,    46,     3,    46,    55,
       6,    47,    48,    57,    55,    51,    58,    74,    75,    76,
      56,    53,    56,    46,   165,   175,   167,   165,    55,   167,
      47,   215,   217,    90,   175,    92,   212,   175,   224,    46,
      57,     3,     4,     5,   194,    51,   222,     3,     4,     5,
       6,     7,     8,   194,     8,     9,   194,   114,   174,    50,
      51,   123,   124,   120,   121,     3,     4,     5,     6,     7,
       3,     4,     5,     6,   215,    75,    76,   215,    10,    11,
      12,    13,    14,    15,    16,   142,   143,     8,    53,   151,
      53,    51,    48,     8,     3,    51,   241,   242,   243,    51,
      56,     9,     8,    44,    49,    45,    52,    57,    47,     8,
      48,    43,     8,    51,    50,    50,     8,    48,    56,   176,
      47,    47,    52,    52,    48,    48,    43,    47,    47,    43,
     230,   231,   232,   233,     8,   192,    43,    50,    43,    50,
     221,     5,    60,    47,   244,   211,   202,   121,   121,   206,
     176,   212,   212,   196,   109,   212,   114,   222,    61,   278,
       5,   222,   222,    -1,    -1,   222,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   234,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   252,   252,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     8,    -1,    -1,    11,    -1,
      -1,    -1,   274,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    -1,    -1,     8,
      43,    -1,    11,    -1,    -1,    -1,    49,    16,    -1,    -1,
      -1,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    -1,    -1,     8,    43,    -1,    11,    -1,    -1,    -1,
      49,    16,    -1,    -1,    -1,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    -1,    -1,     8,    43,    -1,
      11,    -1,    -1,    -1,    49,    16,    -1,    -1,    -1,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,     8,
      -1,    -1,    11,    -1,    -1,    -1,    -1,    16,    -1,    -1,
      -1,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    40,    41,    42,    59,    60,   139,     3,     4,     5,
       6,     7,     8,    48,    51,    56,   110,   111,   114,   116,
       8,    11,    16,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    78,    85,    90,    92,    93,    95,   100,
     101,   102,   105,   123,   130,   131,   139,     0,    10,    12,
      13,    14,    15,    43,    63,    67,    68,    70,    71,    78,
     131,    46,    46,    53,   117,   119,   118,    46,    46,     8,
     130,   130,   124,   125,   139,    53,    53,   125,   125,    44,
      51,    54,    56,    91,    51,   130,     8,    61,    62,    62,
       8,    93,    95,    98,    69,   139,     3,   108,   108,   115,
      47,   114,   120,   121,   122,   139,   120,   120,   108,   108,
      79,    51,     9,    94,    96,   108,     5,     6,   103,   110,
     111,   112,   113,   139,   112,     6,   104,   107,   108,   139,
       8,   106,    86,    72,    44,    13,    45,     8,     9,   116,
      49,    47,   121,    52,    57,    50,    81,   139,    85,    90,
      92,    97,    99,   114,   114,    47,    52,    55,   112,    47,
      57,     4,    55,   109,    44,    54,    56,    87,    88,    89,
      98,   139,    50,    74,   139,     8,    64,    61,   114,     8,
      80,    82,    48,    52,   113,   113,   107,   107,   108,   112,
     104,    52,    47,     8,    73,    75,    48,    46,    61,    65,
      66,    47,    83,   139,    48,    55,   112,    55,   109,    57,
      89,    47,    76,   139,    47,    80,     8,    43,    49,    84,
      85,    93,    95,   126,   132,   113,   107,    73,    43,    49,
      77,    85,    93,    95,   126,    61,    50,    43,   125,   125,
     125,   125,   133,   139,    43,   124,   124,   124,   125,   127,
      17,    18,    19,    43,    49,    93,    95,   134,   136,   137,
     138,     8,   128,   129,   135,    50,    43,    43,    47,   114,
     128,    50
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    58,    59,    59,    59,    60,    60,    60,    60,    60,
      60,    60,    61,    61,    62,    62,    63,    64,    63,    65,
      65,    66,    66,    67,    68,    69,    69,    69,    70,    70,
      72,    71,    73,    74,    74,    75,    75,    76,    76,    76,
      77,    77,    77,    77,    79,    78,    80,    81,    81,    82,
      82,    83,    83,    83,    84,    84,    84,    84,    86,    85,
      87,    87,    88,    88,    89,    91,    90,    92,    93,    94,
      93,    95,    96,    95,    97,    97,    98,    98,    99,    99,
     100,   100,   100,   101,   101,   101,   101,   102,   102,   102,
     102,   103,   103,   103,   103,   103,   103,   103,   104,   104,
     104,   104,   104,   104,   104,   105,   105,   106,   106,   106,
     106,   107,   107,   108,   109,   110,   111,   112,   112,   112,
     113,   113,   114,   115,   114,   116,   116,   116,   116,   116,
     117,   116,   118,   116,   119,   116,   116,   116,   116,   116,
     120,   120,   121,   121,   122,   122,   123,   123,   123,   123,
     123,   123,   123,   123,   123,   123,   123,   123,   123,   123,
     123,   123,   123,   123,   123,   123,   124,   124,   125,   127,
     126,   128,   129,   129,   130,   130,   132,   131,   133,   133,
     133,   133,   133,   133,   135,   134,   136,   137,   138,   138,
     139
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     2,     2,     1,     2,     2,     2,     2,
       2,     2,     1,     3,     1,     3,     2,     0,     5,     1,
       1,     1,     3,     2,     2,     1,     2,     2,     1,     1,
       0,     7,     1,     1,     2,     1,     3,     1,     2,     3,
       2,     2,     2,     2,     0,     7,     1,     1,     2,     1,
       3,     1,     2,     3,     2,     2,     2,     2,     0,     5,
       1,     1,     1,     3,     1,     0,     3,     1,     1,     0,
       4,     1,     0,     4,     1,     1,     1,     1,     1,     1,
       2,     2,     2,     1,     4,     3,     3,     1,     1,     1,
       1,     1,     1,     3,     2,     3,     5,     4,     1,     1,
       3,     2,     3,     5,     4,     1,     4,     1,     3,     3,
       4,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     0,     4,     1,     1,     1,     1,     1,
       0,     4,     0,     4,     0,     4,     3,     3,     3,     3,
       1,     2,     1,     1,     1,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     1,     0,
       4,     1,     1,     3,     1,     1,     0,     9,     1,     2,
       2,     2,     3,     3,     0,     4,     2,     1,     1,     1,
       0
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 4: /* grammar: START_PARAMETER_DESCRIPTION parameter_description  */
#line 171 "dcParser.yxx"
{
  parameter_description = (yyvsp[0].u.field);
}
#line 1538 "dcParser.cxx"
    break;

  case 7: /* dc: dc dclass_or_struct  */
#line 180 "dcParser.yxx"
{
  if (!dc_file->add_class((yyvsp[0].u.dclass))) {
    DCClass *old_class = dc_file->get_class_by_name((yyvsp[0].u.dclass)->get_name());
    if (old_class != (DCClass *)NULL && old_class->is_bogus_class()) {
      yyerror("Base class defined after its first reference: " + (yyvsp[0].u.dclass)->get_name());
    } else {
      yyerror("Duplicate class name: " + (yyvsp[0].u.dclass)->get_name());
    }
  }
}
#line 1553 "dcParser.cxx"
    break;

  case 8: /* dc: dc switch  */
#line 191 "dcParser.yxx"
{
  if (!dc_file->add_switch((yyvsp[0].u.dswitch))) {
    yyerror("Duplicate class name: " + (yyvsp[0].u.dswitch)->get_name());
  }
}
#line 1563 "dcParser.cxx"
    break;

  case 13: /* slash_identifier: slash_identifier '/' IDENTIFIER  */
#line 204 "dcParser.yxx"
{
  (yyval.str) = (yyvsp[-2].str) + string("/") + (yyvsp[0].str);
}
#line 1571 "dcParser.cxx"
    break;

  case 15: /* import_identifier: import_identifier '.' slash_identifier  */
#line 212 "dcParser.yxx"
{
  (yyval.str) = (yyvsp[-2].str) + string(".") + (yyvsp[0].str);
}
#line 1579 "dcParser.cxx"
    break;

  case 16: /* import: KW_IMPORT import_identifier  */
#line 219 "dcParser.yxx"
{
  dc_file->add_import_module((yyvsp[0].str));
}
#line 1587 "dcParser.cxx"
    break;

  case 17: /* $@1: %empty  */
#line 223 "dcParser.yxx"
{
  dc_file->add_import_module((yyvsp[-1].str));
}
#line 1595 "dcParser.cxx"
    break;

  case 20: /* import_symbol_list_or_star: '*'  */
#line 232 "dcParser.yxx"
{
  dc_file->add_import_symbol("*");
}
#line 1603 "dcParser.cxx"
    break;

  case 21: /* import_symbol_list: slash_identifier  */
#line 239 "dcParser.yxx"
{
  dc_file->add_import_symbol((yyvsp[0].str));
}
#line 1611 "dcParser.cxx"
    break;

  case 22: /* import_symbol_list: import_symbol_list ',' slash_identifier  */
#line 243 "dcParser.yxx"
{
  dc_file->add_import_symbol((yyvsp[0].str));
}
#line 1619 "dcParser.cxx"
    break;

  case 23: /* typedef_decl: KW_TYPEDEF parameter_with_default  */
#line 250 "dcParser.yxx"
{
  if ((yyvsp[0].u.parameter) != (DCParameter *)NULL) {
    DCTypedef *dtypedef = new DCTypedef((yyvsp[0].u.parameter));

    if (!dc_file->add_typedef(dtypedef)) {
      DCTypedef *old_typedef = dc_file->get_typedef_by_name(dtypedef->get_name());
      if (old_typedef->is_bogus_typedef()) {
        yyerror("typedef defined after its first reference: " + dtypedef->get_name());
      } else {
        yyerror("Duplicate typedef name: " + dtypedef->get_name());
      }
    }
  }
}
#line 1638 "dcParser.cxx"
    break;

  case 26: /* keyword_decl_list: keyword_decl_list IDENTIFIER  */
#line 273 "dcParser.yxx"
{
  dc_file->add_keyword((yyvsp[0].str));
}
#line 1646 "dcParser.cxx"
    break;

  case 27: /* keyword_decl_list: keyword_decl_list KEYWORD  */
#line 277 "dcParser.yxx"
{
  // This keyword has already been defined.  But since we are now
  // explicitly defining it, clear its bitmask, so that we will have a
  // new hash code--doing this will allow us to phase out the
  // historical hash code support later.
  ((DCKeyword *)(yyvsp[0].u.keyword))->clear_historical_flag();
}
#line 1658 "dcParser.cxx"
    break;

  case 30: /* @2: %empty  */
#line 293 "dcParser.yxx"
{
  current_class = new DCClass(dc_file, (yyvsp[0].str), false, false);
}
#line 1666 "dcParser.cxx"
    break;

  case 31: /* dclass: KW_DCLASS optional_name @2 dclass_derivation '{' dclass_fields '}'  */
#line 297 "dcParser.yxx"
{
  (yyval.u.dclass) = current_class;
  current_class = (yyvsp[-4].u.dclass);
}
#line 1675 "dcParser.cxx"
    break;

  case 32: /* dclass_name: IDENTIFIER  */
#line 305 "dcParser.yxx"
{
  if (dc_file == (DCFile *)NULL) {
    yyerror("No DCFile available, so no class names are predefined.");
    (yyval.u.dclass) = NULL;

  } else {
    DCClass *dclass = dc_file->get_class_by_name((yyvsp[0].str));
    if (dclass == (DCClass *)NULL) {
      // Create a bogus class as a forward reference.
      dclass = new DCClass(dc_file, (yyvsp[0].str), false, true);
      dc_file->add_class(dclass);
    }
    if (dclass->is_struct()) {
      yyerror("struct name not allowed");
    }

    (yyval.u.dclass) = dclass;
  }
}
#line 1699 "dcParser.cxx"
    break;

  case 35: /* dclass_base_list: dclass_name  */
#line 333 "dcParser.yxx"
{
  if ((yyvsp[0].u.dclass) != (DCClass *)NULL) {
    current_class->add_parent((yyvsp[0].u.dclass));
  }
}
#line 1709 "dcParser.cxx"
    break;

  case 36: /* dclass_base_list: dclass_base_list ',' dclass_name  */
#line 339 "dcParser.yxx"
{
  if (!dc_multiple_inheritance) {
    yyerror("Multiple inheritance is not supported without \"dc-multiple-inheritance 1\" in your Config.prc file.");

  } else {
    if ((yyvsp[0].u.dclass) != (DCClass *)NULL) {
      current_class->add_parent((yyvsp[0].u.dclass));
    }
  }
}
#line 1724 "dcParser.cxx"
    break;

  case 39: /* dclass_fields: dclass_fields dclass_field ';'  */
#line 355 "dcParser.yxx"
{
  if ((yyvsp[-1].u.field) == (DCField *)NULL) {
    // Pass this error up.
  } else if (!current_class->add_field((yyvsp[-1].u.field))) {
    yyerror("Duplicate field name: " + (yyvsp[-1].u.field)->get_name());
  } else if ((yyvsp[-1].u.field)->get_number() < 0) {
    yyerror("A non-network field cannot be stored on a dclass");
  }
}
#line 1738 "dcParser.cxx"
    break;

  case 40: /* dclass_field: atomic_field keyword_list  */
#line 368 "dcParser.yxx"
{
  if ((yyvsp[-1].u.field) != (DCField *)NULL) {
    if ((yyvsp[-1].u.field)->get_name().empty()) {
      yyerror("Field name required.");
    }
    (yyvsp[-1].u.field)->copy_keywords(current_keyword_list);
  }
  (yyval.u.field) = (yyvsp[-1].u.field);
}
#line 1752 "dcParser.cxx"
    break;

  case 42: /* dclass_field: unnamed_parameter_with_default keyword_list  */
#line 379 "dcParser.yxx"
{
  yyerror("Unnamed parameters are not allowed on a dclass");
  if ((yyvsp[-1].u.parameter) != (DCField *)NULL) {
    (yyvsp[-1].u.parameter)->copy_keywords(current_keyword_list);
  }
  (yyval.u.field) = (yyvsp[-1].u.parameter);
}
#line 1764 "dcParser.cxx"
    break;

  case 43: /* dclass_field: named_parameter_with_default keyword_list  */
#line 387 "dcParser.yxx"
{
  if ((yyvsp[-1].u.parameter) != (DCField *)NULL) {
    (yyvsp[-1].u.parameter)->copy_keywords(current_keyword_list);
  }
  (yyval.u.field) = (yyvsp[-1].u.parameter);
}
#line 1775 "dcParser.cxx"
    break;

  case 44: /* @3: %empty  */
#line 397 "dcParser.yxx"
{
  current_class = new DCClass(dc_file, (yyvsp[0].str), true, false);
}
#line 1783 "dcParser.cxx"
    break;

  case 45: /* struct: KW_STRUCT optional_name @3 struct_derivation '{' struct_fields '}'  */
#line 401 "dcParser.yxx"
{
  (yyval.u.dclass) = current_class;
  current_class = (yyvsp[-4].u.dclass);
}
#line 1792 "dcParser.cxx"
    break;

  case 46: /* struct_name: IDENTIFIER  */
#line 409 "dcParser.yxx"
{
  if (dc_file == (DCFile *)NULL) {
    yyerror("No DCFile available, so no struct names are predefined.");
    (yyval.u.dclass) = NULL;

  } else {
    DCClass *dstruct = dc_file->get_class_by_name((yyvsp[0].str));
    if (dstruct == (DCClass *)NULL) {
      // Create a bogus class as a forward reference.
      dstruct = new DCClass(dc_file, (yyvsp[0].str), false, true);
      dc_file->add_class(dstruct);
    }
    if (!dstruct->is_struct()) {
      yyerror("struct name required");
    }

    (yyval.u.dclass) = dstruct;
  }
}
#line 1816 "dcParser.cxx"
    break;

  case 49: /* struct_base_list: struct_name  */
#line 437 "dcParser.yxx"
{
  if ((yyvsp[0].u.dclass) != (DCClass *)NULL) {
    current_class->add_parent((yyvsp[0].u.dclass));
  }
}
#line 1826 "dcParser.cxx"
    break;

  case 50: /* struct_base_list: struct_base_list ',' struct_name  */
#line 443 "dcParser.yxx"
{
  if ((yyvsp[0].u.dclass) != (DCClass *)NULL) {
    current_class->add_parent((yyvsp[0].u.dclass));
  }
}
#line 1836 "dcParser.cxx"
    break;

  case 53: /* struct_fields: struct_fields struct_field ';'  */
#line 454 "dcParser.yxx"
{
  if ((yyvsp[-1].u.field) == (DCField *)NULL) {
    // Pass this error up.
  } else if (!current_class->add_field((yyvsp[-1].u.field))) {
    yyerror("Duplicate field name: " + (yyvsp[-1].u.field)->get_name());
  }
}
#line 1848 "dcParser.cxx"
    break;

  case 54: /* struct_field: atomic_field no_keyword_list  */
#line 465 "dcParser.yxx"
{
  if ((yyvsp[-1].u.field)->get_name().empty()) {
    yyerror("Field name required.");
  }
  (yyval.u.field) = (yyvsp[-1].u.field);
}
#line 1859 "dcParser.cxx"
    break;

  case 56: /* struct_field: unnamed_parameter_with_default no_keyword_list  */
#line 473 "dcParser.yxx"
{
  (yyval.u.field) = (yyvsp[-1].u.parameter);
}
#line 1867 "dcParser.cxx"
    break;

  case 57: /* struct_field: named_parameter_with_default no_keyword_list  */
#line 477 "dcParser.yxx"
{
  (yyval.u.field) = (yyvsp[-1].u.parameter);
}
#line 1875 "dcParser.cxx"
    break;

  case 58: /* @4: %empty  */
#line 484 "dcParser.yxx"
{
  if (current_class == (DCClass *)NULL) {
    yyerror("Cannot define a method outside of a struct or class.");
    DCClass *temp_class = new DCClass(dc_file, "temp", false, false);  // memory leak.
    current_atomic = new DCAtomicField((yyvsp[-1].str), temp_class, false);
  } else {
    current_atomic = new DCAtomicField((yyvsp[-1].str), current_class, false);
  }
}
#line 1889 "dcParser.cxx"
    break;

  case 59: /* atomic_field: optional_name '(' @4 parameter_list ')'  */
#line 494 "dcParser.yxx"
{
  (yyval.u.field) = current_atomic;
  current_atomic = (yyvsp[-2].u.atomic);
}
#line 1898 "dcParser.cxx"
    break;

  case 64: /* atomic_element: parameter_with_default  */
#line 512 "dcParser.yxx"
{
  if ((yyvsp[0].u.parameter) != (DCParameter *)NULL) {
    current_atomic->add_element((yyvsp[0].u.parameter));
  }
}
#line 1908 "dcParser.cxx"
    break;

  case 65: /* $@5: %empty  */
#line 521 "dcParser.yxx"
{
  current_parameter = (yyvsp[0].u.parameter);
}
#line 1916 "dcParser.cxx"
    break;

  case 66: /* named_parameter: type_definition $@5 parameter_definition  */
#line 525 "dcParser.yxx"
{
  (yyval.u.parameter) = (yyvsp[0].u.parameter);
}
#line 1924 "dcParser.cxx"
    break;

  case 69: /* $@6: %empty  */
#line 537 "dcParser.yxx"
{
  current_packer = &default_packer;
  current_packer->clear_data();
  if ((yyvsp[-1].u.parameter) != (DCField *)NULL) {
    current_packer->begin_pack((yyvsp[-1].u.parameter));
  }
}
#line 1936 "dcParser.cxx"
    break;

  case 70: /* named_parameter_with_default: named_parameter '=' $@6 parameter_value  */
#line 545 "dcParser.yxx"
{
  bool is_valid = false;
  if ((yyvsp[-3].u.parameter) != (DCField *)NULL) {
    is_valid = (yyvsp[-3].u.parameter)->is_valid();
  }
  if (current_packer->end_pack()) {
    (yyvsp[-3].u.parameter)->set_default_value(current_packer->get_string());

  } else {
    if (is_valid) {
      yyerror("Invalid default value for type");
    }
    // If the current parameter isn't valid, we don't mind a pack
    // error (there's no way for us to validate the syntax).  So we'll
    // just ignore the default value in this case.
  }
}
#line 1958 "dcParser.cxx"
    break;

  case 72: /* $@7: %empty  */
#line 567 "dcParser.yxx"
{
  current_packer = &default_packer;
  current_packer->clear_data();
  if ((yyvsp[-1].u.parameter) != (DCField *)NULL) {
    current_packer->begin_pack((yyvsp[-1].u.parameter));
  }
}
#line 1970 "dcParser.cxx"
    break;

  case 73: /* unnamed_parameter_with_default: unnamed_parameter '=' $@7 parameter_value  */
#line 575 "dcParser.yxx"
{
  bool is_valid = false;
  if ((yyvsp[-3].u.parameter) != (DCField *)NULL) {
    is_valid = (yyvsp[-3].u.parameter)->is_valid();
  }
  if (current_packer->end_pack()) {
    (yyvsp[-3].u.parameter)->set_default_value(current_packer->get_string());

  } else {
    if (is_valid) {
      yyerror("Invalid default value for type");
    }
    // If the current parameter isn't valid, we don't mind a pack
    // error (there's no way for us to validate the syntax).  So we'll
    // just ignore the default value in this case.
  }
}
#line 1992 "dcParser.cxx"
    break;

  case 78: /* parameter_or_atomic: parameter  */
#line 606 "dcParser.yxx"
{
  (yyval.u.field) = (yyvsp[0].u.parameter);
}
#line 2000 "dcParser.cxx"
    break;

  case 79: /* parameter_or_atomic: atomic_field  */
#line 610 "dcParser.yxx"
{
  (yyval.u.field) = (yyvsp[0].u.field);
}
#line 2008 "dcParser.cxx"
    break;

  case 80: /* parameter_description: atomic_field no_keyword_list  */
#line 617 "dcParser.yxx"
{
  (yyval.u.field) = (yyvsp[-1].u.field);
}
#line 2016 "dcParser.cxx"
    break;

  case 81: /* parameter_description: unnamed_parameter_with_default no_keyword_list  */
#line 621 "dcParser.yxx"
{
  (yyval.u.field) = (yyvsp[-1].u.parameter);
}
#line 2024 "dcParser.cxx"
    break;

  case 82: /* parameter_description: named_parameter_with_default no_keyword_list  */
#line 625 "dcParser.yxx"
{
  (yyval.u.field) = (yyvsp[-1].u.parameter);
}
#line 2032 "dcParser.cxx"
    break;

  case 83: /* simple_type_name: type_token  */
#line 632 "dcParser.yxx"
{
  (yyval.u.parameter) = new DCSimpleParameter((yyvsp[0].u.subatomic));
}
#line 2040 "dcParser.cxx"
    break;

  case 84: /* simple_type_name: simple_type_name '(' double_range ')'  */
#line 636 "dcParser.yxx"
{
  DCSimpleParameter *simple_param = (yyvsp[-3].u.parameter)->as_simple_parameter();
  nassertr(simple_param != (DCSimpleParameter *)NULL, 0);
  if (!simple_param->set_range(double_range)) {
    yyerror("Inappropriate range for type");
  }
  (yyval.u.parameter) = simple_param;
}
#line 2053 "dcParser.cxx"
    break;

  case 85: /* simple_type_name: simple_type_name '/' small_unsigned_integer  */
#line 645 "dcParser.yxx"
{
  DCSimpleParameter *simple_param = (yyvsp[-2].u.parameter)->as_simple_parameter();
  nassertr(simple_param != (DCSimpleParameter *)NULL, 0);
  if (!simple_param->is_numeric_type()) {
    yyerror("A divisor is only valid on a numeric type.");

  } else if (!simple_param->set_divisor((yyvsp[0].u.s_uint))) {
    yyerror("Invalid divisor.");

  } else if (simple_param->has_modulus() && !simple_param->set_modulus(simple_param->get_modulus())) {
    // Changing the divisor may change the valid range for the modulus.
    yyerror("Invalid modulus.");
  }
  (yyval.u.parameter) = simple_param;
}
#line 2073 "dcParser.cxx"
    break;

  case 86: /* simple_type_name: simple_type_name '%' number  */
#line 661 "dcParser.yxx"
{
  DCSimpleParameter *simple_param = (yyvsp[-2].u.parameter)->as_simple_parameter();
  nassertr(simple_param != (DCSimpleParameter *)NULL, 0);
  if (!simple_param->is_numeric_type()) {
    yyerror("A divisor is only valid on a numeric type.");

  } else if (!simple_param->set_modulus((yyvsp[0].u.real))) {
    yyerror("Invalid modulus.");
  }
  (yyval.u.parameter) = simple_param;
}
#line 2089 "dcParser.cxx"
    break;

  case 88: /* type_name: IDENTIFIER  */
#line 677 "dcParser.yxx"
{
  if (dc_file == (DCFile *)NULL) {
    yyerror("Invalid type.");
    (yyval.u.parameter) = NULL;

  } else {
    DCTypedef *dtypedef = dc_file->get_typedef_by_name((yyvsp[0].str));
    if (dtypedef == (DCTypedef *)NULL) {
      // Maybe it's a class name.
      DCClass *dclass = dc_file->get_class_by_name((yyvsp[0].str));
      if (dclass != (DCClass *)NULL) {
        // Create an implicit typedef for this.
        dtypedef = new DCTypedef(new DCClassParameter(dclass), true);
      } else {
        // Maybe it's a switch name.
        DCSwitch *dswitch = dc_file->get_switch_by_name((yyvsp[0].str));
        if (dswitch != (DCSwitch *)NULL) {
          // This also gets an implicit typedef.
          dtypedef = new DCTypedef(new DCSwitchParameter(dswitch), true);
        } else {
          // It's an undefined typedef.  Create a bogus forward reference.
          dtypedef = new DCTypedef((yyvsp[0].str));
        }
      }

      dc_file->add_typedef(dtypedef);
    }

    (yyval.u.parameter) = dtypedef->make_new_parameter();
  }
}
#line 2125 "dcParser.cxx"
    break;

  case 89: /* type_name: struct  */
#line 709 "dcParser.yxx"
{
  // This is an inline struct definition.
  if ((yyvsp[0].u.dclass) == (DCClass *)NULL) {
    (yyval.u.parameter) = NULL;
  } else {
    if (dc_file != (DCFile *)NULL) {
      dc_file->add_thing_to_delete((yyvsp[0].u.dclass));
    } else {
      // This is a memory leak--this happens when we put an anonymous
      // struct reference within the string passed to
      // DCPackerInterface::check_match().  Maybe it doesn't really matter.
    }
    (yyval.u.parameter) = new DCClassParameter((yyvsp[0].u.dclass));
  }
}
#line 2145 "dcParser.cxx"
    break;

  case 90: /* type_name: switch  */
#line 725 "dcParser.yxx"
{
  // This is an inline switch definition.
  if ((yyvsp[0].u.dswitch) == (DCSwitch *)NULL) {
    (yyval.u.parameter) = NULL;
  } else {
    if (dc_file != (DCFile *)NULL) {
      dc_file->add_thing_to_delete((yyvsp[0].u.dswitch));
    } else {
      // This is a memory leak--this happens when we put an anonymous
      // switch reference within the string passed to
      // DCPackerInterface::check_match().  Maybe it doesn't really matter.
    }
    (yyval.u.parameter) = new DCSwitchParameter((yyvsp[0].u.dswitch));
  }
}
#line 2165 "dcParser.cxx"
    break;

  case 91: /* double_range: empty  */
#line 744 "dcParser.yxx"
{
  double_range.clear();
}
#line 2173 "dcParser.cxx"
    break;

  case 92: /* double_range: char_or_number  */
#line 748 "dcParser.yxx"
{
  double_range.clear();
  if (!double_range.add_range((yyvsp[0].u.real), (yyvsp[0].u.real))) {
    yyerror("Overlapping range");
  }
}
#line 2184 "dcParser.cxx"
    break;

  case 93: /* double_range: char_or_number '-' char_or_number  */
#line 755 "dcParser.yxx"
{
  double_range.clear();
  if (!double_range.add_range((yyvsp[-2].u.real), (yyvsp[0].u.real))) {
    yyerror("Overlapping range");
  }
}
#line 2195 "dcParser.cxx"
    break;

  case 94: /* double_range: char_or_number number  */
#line 762 "dcParser.yxx"
{
  double_range.clear();
  if ((yyvsp[0].u.real) >= 0) {
    yyerror("Syntax error");
  } else if (!double_range.add_range((yyvsp[-1].u.real), -(yyvsp[0].u.real))) {
    yyerror("Overlapping range");
  }
}
#line 2208 "dcParser.cxx"
    break;

  case 95: /* double_range: double_range ',' char_or_number  */
#line 771 "dcParser.yxx"
{
  if (!double_range.add_range((yyvsp[0].u.real), (yyvsp[0].u.real))) {
    yyerror("Overlapping range");
  }
}
#line 2218 "dcParser.cxx"
    break;

  case 96: /* double_range: double_range ',' char_or_number '-' char_or_number  */
#line 777 "dcParser.yxx"
{
  if (!double_range.add_range((yyvsp[-2].u.real), (yyvsp[0].u.real))) {
    yyerror("Overlapping range");
  }
}
#line 2228 "dcParser.cxx"
    break;

  case 97: /* double_range: double_range ',' char_or_number number  */
#line 783 "dcParser.yxx"
{
  if ((yyvsp[0].u.real) >= 0) {
    yyerror("Syntax error");
  } else if (!double_range.add_range((yyvsp[-1].u.real), -(yyvsp[0].u.real))) {
    yyerror("Overlapping range");
  }
}
#line 2240 "dcParser.cxx"
    break;

  case 98: /* uint_range: empty  */
#line 794 "dcParser.yxx"
{
  uint_range.clear();
}
#line 2248 "dcParser.cxx"
    break;

  case 99: /* uint_range: char_or_uint  */
#line 798 "dcParser.yxx"
{
  uint_range.clear();
  if (!uint_range.add_range((yyvsp[0].u.s_uint), (yyvsp[0].u.s_uint))) {
    yyerror("Overlapping range");
  }
}
#line 2259 "dcParser.cxx"
    break;

  case 100: /* uint_range: char_or_uint '-' char_or_uint  */
#line 805 "dcParser.yxx"
{
  uint_range.clear();
  if (!uint_range.add_range((yyvsp[-2].u.s_uint), (yyvsp[0].u.s_uint))) {
    yyerror("Overlapping range");
  }
}
#line 2270 "dcParser.cxx"
    break;

  case 101: /* uint_range: char_or_uint small_negative_integer  */
#line 812 "dcParser.yxx"
{
  uint_range.clear();
  if (!uint_range.add_range((yyvsp[-1].u.s_uint), (yyvsp[0].u.s_uint))) {
    yyerror("Overlapping range");
  }
}
#line 2281 "dcParser.cxx"
    break;

  case 102: /* uint_range: uint_range ',' char_or_uint  */
#line 819 "dcParser.yxx"
{
  if (!uint_range.add_range((yyvsp[0].u.s_uint), (yyvsp[0].u.s_uint))) {
    yyerror("Overlapping range");
  }
}
#line 2291 "dcParser.cxx"
    break;

  case 103: /* uint_range: uint_range ',' char_or_uint '-' char_or_uint  */
#line 825 "dcParser.yxx"
{
  if (!uint_range.add_range((yyvsp[-2].u.s_uint), (yyvsp[0].u.s_uint))) {
    yyerror("Overlapping range");
  }
}
#line 2301 "dcParser.cxx"
    break;

  case 104: /* uint_range: uint_range ',' char_or_uint small_negative_integer  */
#line 831 "dcParser.yxx"
{
  if (!uint_range.add_range((yyvsp[-1].u.s_uint), (yyvsp[0].u.s_uint))) {
    yyerror("Overlapping range");
  }
}
#line 2311 "dcParser.cxx"
    break;

  case 106: /* type_definition: type_definition '[' uint_range ']'  */
#line 841 "dcParser.yxx"
{
  if ((yyvsp[-3].u.parameter) == (DCParameter *)NULL) {
    (yyval.u.parameter) = NULL;
  } else {
    (yyval.u.parameter) = (yyvsp[-3].u.parameter)->append_array_specification(uint_range);
  }
}
#line 2323 "dcParser.cxx"
    break;

  case 107: /* parameter_definition: IDENTIFIER  */
#line 852 "dcParser.yxx"
{
  current_parameter->set_name((yyvsp[0].str));
  (yyval.u.parameter) = current_parameter;
}
#line 2332 "dcParser.cxx"
    break;

  case 108: /* parameter_definition: parameter_definition '/' small_unsigned_integer  */
#line 857 "dcParser.yxx"
{
  DCSimpleParameter *simple_param = (yyvsp[-2].u.parameter)->as_simple_parameter();
  if (simple_param == NULL || simple_param->get_typedef() != (DCTypedef *)NULL) {
    yyerror("A divisor is only allowed on a primitive type.");

  } else if (!simple_param->is_numeric_type()) {
      yyerror("A divisor is only valid on a numeric type.");

  } else {
    if (!simple_param->set_divisor((yyvsp[0].u.s_uint))) {
      yyerror("Invalid divisor.");
    }
  }
}
#line 2351 "dcParser.cxx"
    break;

  case 109: /* parameter_definition: parameter_definition '%' number  */
#line 872 "dcParser.yxx"
{
  DCSimpleParameter *simple_param = (yyvsp[-2].u.parameter)->as_simple_parameter();
  if (simple_param == NULL || simple_param->get_typedef() != (DCTypedef *)NULL) {
    yyerror("A modulus is only allowed on a primitive type.");

  } else if (!simple_param->is_numeric_type()) {
      yyerror("A modulus is only valid on a numeric type.");

  } else {
    if (!simple_param->set_modulus((yyvsp[0].u.real))) {
      yyerror("Invalid modulus.");
    }
  }
}
#line 2370 "dcParser.cxx"
    break;

  case 110: /* parameter_definition: parameter_definition '[' uint_range ']'  */
#line 887 "dcParser.yxx"
{
  (yyval.u.parameter) = (yyvsp[-3].u.parameter)->append_array_specification(uint_range);
}
#line 2378 "dcParser.cxx"
    break;

  case 111: /* char_or_uint: STRING  */
#line 894 "dcParser.yxx"
{
  if ((yyvsp[0].str).length() != 1) {
    yyerror("Single character required.");
    (yyval.u.s_uint) = 0;
  } else {
    (yyval.u.s_uint) = (unsigned char)(yyvsp[0].str)[0];
  }
}
#line 2391 "dcParser.cxx"
    break;

  case 113: /* small_unsigned_integer: UNSIGNED_INTEGER  */
#line 907 "dcParser.yxx"
{
  (yyval.u.s_uint) = (unsigned int)(yyvsp[0].u.uint64);
  if ((yyval.u.s_uint) != (yyvsp[0].u.uint64)) {
    yyerror("Number out of range.");
    (yyval.u.s_uint) = 1;
  }
}
#line 2403 "dcParser.cxx"
    break;

  case 114: /* small_negative_integer: SIGNED_INTEGER  */
#line 918 "dcParser.yxx"
{
  (yyval.u.s_uint) = (unsigned int)-(yyvsp[0].u.int64);
  if ((yyvsp[0].u.int64) >= 0) {
    yyerror("Syntax error.");

  } else if ((yyval.u.s_uint) != -(yyvsp[0].u.int64)) {
    yyerror("Number out of range.");
    (yyval.u.s_uint) = 1;
  }
}
#line 2418 "dcParser.cxx"
    break;

  case 117: /* number: unsigned_integer  */
#line 940 "dcParser.yxx"
{
  (yyval.u.real) = (double)(yyvsp[0].u.uint64);
}
#line 2426 "dcParser.cxx"
    break;

  case 118: /* number: signed_integer  */
#line 944 "dcParser.yxx"
{
  (yyval.u.real) = (double)(yyvsp[0].u.int64);
}
#line 2434 "dcParser.cxx"
    break;

  case 120: /* char_or_number: STRING  */
#line 952 "dcParser.yxx"
{
  if ((yyvsp[0].str).length() != 1) {
    yyerror("Single character required.");
    (yyval.u.real) = 0;
  } else {
    (yyval.u.real) = (double)(unsigned char)(yyvsp[0].str)[0];
  }
}
#line 2447 "dcParser.cxx"
    break;

  case 122: /* parameter_value: parameter_actual_value  */
#line 966 "dcParser.yxx"
{
}
#line 2454 "dcParser.cxx"
    break;

  case 123: /* $@8: %empty  */
#line 969 "dcParser.yxx"
{
  if ((yyvsp[-1].str) != current_packer->get_current_field_name()) {
    ostringstream strm;
    strm << "Got '" << (yyvsp[-1].str) << "', expected '"
         << current_packer->get_current_field_name() << "'";
    yyerror(strm.str());
  }
}
#line 2467 "dcParser.cxx"
    break;

  case 124: /* parameter_value: IDENTIFIER '=' $@8 parameter_actual_value  */
#line 978 "dcParser.yxx"
{
}
#line 2474 "dcParser.cxx"
    break;

  case 125: /* parameter_actual_value: signed_integer  */
#line 984 "dcParser.yxx"
{
  current_packer->pack_int64((yyvsp[0].u.int64));
}
#line 2482 "dcParser.cxx"
    break;

  case 126: /* parameter_actual_value: unsigned_integer  */
#line 988 "dcParser.yxx"
{
  current_packer->pack_uint64((yyvsp[0].u.uint64));
}
#line 2490 "dcParser.cxx"
    break;

  case 127: /* parameter_actual_value: REAL  */
#line 992 "dcParser.yxx"
{
  current_packer->pack_double((yyvsp[0].u.real));
}
#line 2498 "dcParser.cxx"
    break;

  case 128: /* parameter_actual_value: STRING  */
#line 996 "dcParser.yxx"
{
  current_packer->pack_string((yyvsp[0].str));
}
#line 2506 "dcParser.cxx"
    break;

  case 129: /* parameter_actual_value: HEX_STRING  */
#line 1000 "dcParser.yxx"
{
  current_packer->pack_literal_value((yyvsp[0].str));
}
#line 2514 "dcParser.cxx"
    break;

  case 130: /* $@9: %empty  */
#line 1004 "dcParser.yxx"
{
  current_packer->push();
}
#line 2522 "dcParser.cxx"
    break;

  case 131: /* parameter_actual_value: '{' $@9 array '}'  */
#line 1008 "dcParser.yxx"
{
  current_packer->pop();
}
#line 2530 "dcParser.cxx"
    break;

  case 132: /* $@10: %empty  */
#line 1012 "dcParser.yxx"
{
  current_packer->push();
}
#line 2538 "dcParser.cxx"
    break;

  case 133: /* parameter_actual_value: '[' $@10 array ']'  */
#line 1016 "dcParser.yxx"
{
  current_packer->pop();
}
#line 2546 "dcParser.cxx"
    break;

  case 134: /* $@11: %empty  */
#line 1020 "dcParser.yxx"
{
  current_packer->push();
}
#line 2554 "dcParser.cxx"
    break;

  case 135: /* parameter_actual_value: '(' $@11 array ')'  */
#line 1024 "dcParser.yxx"
{
  current_packer->pop();
}
#line 2562 "dcParser.cxx"
    break;

  case 136: /* parameter_actual_value: signed_integer '*' small_unsigned_integer  */
#line 1028 "dcParser.yxx"
{
  for (unsigned int i = 0; i < (yyvsp[0].u.s_uint); i++) {
    current_packer->pack_int64((yyvsp[-2].u.int64));
  }
}
#line 2572 "dcParser.cxx"
    break;

  case 137: /* parameter_actual_value: unsigned_integer '*' small_unsigned_integer  */
#line 1034 "dcParser.yxx"
{
  for (unsigned int i = 0; i < (yyvsp[0].u.s_uint); i++) {
    current_packer->pack_uint64((yyvsp[-2].u.uint64));
  }
}
#line 2582 "dcParser.cxx"
    break;

  case 138: /* parameter_actual_value: REAL '*' small_unsigned_integer  */
#line 1040 "dcParser.yxx"
{
  for (unsigned int i = 0; i < (yyvsp[0].u.s_uint); i++) {
    current_packer->pack_double((yyvsp[-2].u.real));
  }
}
#line 2592 "dcParser.cxx"
    break;

  case 139: /* parameter_actual_value: HEX_STRING '*' small_unsigned_integer  */
#line 1046 "dcParser.yxx"
{
  for (unsigned int i = 0; i < (yyvsp[0].u.s_uint); i++) {
    current_packer->pack_literal_value((yyvsp[-2].str));
  }
}
#line 2602 "dcParser.cxx"
    break;

  case 146: /* type_token: KW_INT8  */
#line 1070 "dcParser.yxx"
{
  (yyval.u.subatomic) = ST_int8;
}
#line 2610 "dcParser.cxx"
    break;

  case 147: /* type_token: KW_INT16  */
#line 1074 "dcParser.yxx"
{
  (yyval.u.subatomic) = ST_int16;
}
#line 2618 "dcParser.cxx"
    break;

  case 148: /* type_token: KW_INT32  */
#line 1078 "dcParser.yxx"
{
  (yyval.u.subatomic) = ST_int32;
}
#line 2626 "dcParser.cxx"
    break;

  case 149: /* type_token: KW_INT64  */
#line 1082 "dcParser.yxx"
{
  (yyval.u.subatomic) = ST_int64;
}
#line 2634 "dcParser.cxx"
    break;

  case 150: /* type_token: KW_UINT8  */
#line 1086 "dcParser.yxx"
{
  (yyval.u.subatomic) = ST_uint8;
}
#line 2642 "dcParser.cxx"
    break;

  case 151: /* type_token: KW_UINT16  */
#line 1090 "dcParser.yxx"
{
  (yyval.u.subatomic) = ST_uint16;
}
#line 2650 "dcParser.cxx"
    break;

  case 152: /* type_token: KW_UINT32  */
#line 1094 "dcParser.yxx"
{
  (yyval.u.subatomic) = ST_uint32;
}
#line 2658 "dcParser.cxx"
    break;

  case 153: /* type_token: KW_UINT64  */
#line 1098 "dcParser.yxx"
{
  (yyval.u.subatomic) = ST_uint64;
}
#line 2666 "dcParser.cxx"
    break;

  case 154: /* type_token: KW_FLOAT64  */
#line 1102 "dcParser.yxx"
{
  (yyval.u.subatomic) = ST_float64;
}
#line 2674 "dcParser.cxx"
    break;

  case 155: /* type_token: KW_STRING  */
#line 1106 "dcParser.yxx"
{
  (yyval.u.subatomic) = ST_string;
}
#line 2682 "dcParser.cxx"
    break;

  case 156: /* type_token: KW_BLOB  */
#line 1110 "dcParser.yxx"
{
  (yyval.u.subatomic) = ST_blob;
}
#line 2690 "dcParser.cxx"
    break;

  case 157: /* type_token: KW_BLOB32  */
#line 1114 "dcParser.yxx"
{
  (yyval.u.subatomic) = ST_blob32;
}
#line 2698 "dcParser.cxx"
    break;

  case 158: /* type_token: KW_INT8ARRAY  */
#line 1118 "dcParser.yxx"
{
  (yyval.u.subatomic) = ST_int8array;
}
#line 2706 "dcParser.cxx"
    break;

  case 159: /* type_token: KW_INT16ARRAY  */
#line 1122 "dcParser.yxx"
{
  (yyval.u.subatomic) = ST_int16array;
}
#line 2714 "dcParser.cxx"
    break;

  case 160: /* type_token: KW_INT32ARRAY  */
#line 1126 "dcParser.yxx"
{
  (yyval.u.subatomic) = ST_int32array;
}
#line 2722 "dcParser.cxx"
    break;

  case 161: /* type_token: KW_UINT8ARRAY  */
#line 1130 "dcParser.yxx"
{
  (yyval.u.subatomic) = ST_uint8array;
}
#line 2730 "dcParser.cxx"
    break;

  case 162: /* type_token: KW_UINT16ARRAY  */
#line 1134 "dcParser.yxx"
{
  (yyval.u.subatomic) = ST_uint16array;
}
#line 2738 "dcParser.cxx"
    break;

  case 163: /* type_token: KW_UINT32ARRAY  */
#line 1138 "dcParser.yxx"
{
  (yyval.u.subatomic) = ST_uint32array;
}
#line 2746 "dcParser.cxx"
    break;

  case 164: /* type_token: KW_UINT32UINT8ARRAY  */
#line 1142 "dcParser.yxx"
{
  (yyval.u.subatomic) = ST_uint32uint8array;
}
#line 2754 "dcParser.cxx"
    break;

  case 165: /* type_token: KW_CHAR  */
#line 1146 "dcParser.yxx"
{
  (yyval.u.subatomic) = ST_char;
}
#line 2762 "dcParser.cxx"
    break;

  case 166: /* keyword_list: empty  */
#line 1153 "dcParser.yxx"
{
  current_keyword_list.clear_keywords();
}
#line 2770 "dcParser.cxx"
    break;

  case 167: /* keyword_list: keyword_list KEYWORD  */
#line 1157 "dcParser.yxx"
{
  current_keyword_list.add_keyword((yyvsp[0].u.keyword));
}
#line 2778 "dcParser.cxx"
    break;

  case 168: /* no_keyword_list: keyword_list  */
#line 1164 "dcParser.yxx"
{
  if (current_keyword_list.get_num_keywords() != 0) {
    yyerror("Communication keywords are not allowed here.");
  }
}
#line 2788 "dcParser.cxx"
    break;

  case 169: /* $@12: %empty  */
#line 1173 "dcParser.yxx"
{
  current_molecular = new DCMolecularField((yyvsp[-1].str), current_class);
}
#line 2796 "dcParser.cxx"
    break;

  case 170: /* molecular_field: IDENTIFIER ':' $@12 molecular_atom_list  */
#line 1177 "dcParser.yxx"
{
  (yyval.u.field) = current_molecular;
}
#line 2804 "dcParser.cxx"
    break;

  case 171: /* atomic_name: IDENTIFIER  */
#line 1184 "dcParser.yxx"
{
  DCField *field = current_class->get_field_by_name((yyvsp[0].str));
  (yyval.u.atomic) = (DCAtomicField *)NULL;
  if (field == (DCField *)NULL) {
    // Maybe the field is unknown because the class is partially
    // bogus.  In that case, allow it for now; create a bogus field as
    // a placeholder.
    if (current_class->inherits_from_bogus_class()) {
      (yyval.u.atomic) = new DCAtomicField((yyvsp[0].str), current_class, true);
      current_class->add_field((yyval.u.atomic));

    } else {
      // Nope, it's a fully-defined class, so this is a real error.
      yyerror("Unknown field: " + (yyvsp[0].str));
    }

  } else {
    (yyval.u.atomic) = field->as_atomic_field();
    if ((yyval.u.atomic) == (DCAtomicField *)NULL) {
      yyerror("Not an atomic field: " + (yyvsp[0].str));
    }
  }
}
#line 2832 "dcParser.cxx"
    break;

  case 172: /* molecular_atom_list: atomic_name  */
#line 1211 "dcParser.yxx"
{
  if ((yyvsp[0].u.atomic) != (DCAtomicField *)NULL) {
    current_molecular->add_atomic((yyvsp[0].u.atomic));
  }
}
#line 2842 "dcParser.cxx"
    break;

  case 173: /* molecular_atom_list: molecular_atom_list ',' atomic_name  */
#line 1217 "dcParser.yxx"
{
  if ((yyvsp[0].u.atomic) != (DCAtomicField *)NULL) {
    current_molecular->add_atomic((yyvsp[0].u.atomic));
    if (!(yyvsp[0].u.atomic)->is_bogus_field() && !current_molecular->compare_keywords(*(yyvsp[0].u.atomic))) {
      yyerror("Mismatched keywords in molecule between " +
              current_molecular->get_atomic(0)->get_name() + " and " +
              (yyvsp[0].u.atomic)->get_name());
    }
  }
}
#line 2857 "dcParser.cxx"
    break;

  case 174: /* optional_name: empty  */
#line 1231 "dcParser.yxx"
{
  (yyval.str) = "";
}
#line 2865 "dcParser.cxx"
    break;

  case 176: /* @13: %empty  */
#line 1239 "dcParser.yxx"
{
  current_switch = new DCSwitch((yyvsp[-4].str), (yyvsp[-2].u.field));
}
#line 2873 "dcParser.cxx"
    break;

  case 177: /* switch: KW_SWITCH optional_name '(' parameter_or_atomic ')' '{' @13 switch_fields '}'  */
#line 1243 "dcParser.yxx"
{
  (yyval.u.dswitch) = current_switch;
  current_switch = (DCSwitch *)(yyvsp[-2].u.parameter);
}
#line 2882 "dcParser.cxx"
    break;

  case 183: /* switch_fields: switch_fields switch_field ';'  */
#line 1257 "dcParser.yxx"
{
  if (!current_switch->is_field_valid()) {
    yyerror("case declaration required before first element");
  } else if ((yyvsp[-1].u.field) != (DCField *)NULL) {
    if (!current_switch->add_field((yyvsp[-1].u.field))) {
      yyerror("Duplicate field name: " + (yyvsp[-1].u.field)->get_name());
    }
  }
}
#line 2896 "dcParser.cxx"
    break;

  case 184: /* $@14: %empty  */
#line 1270 "dcParser.yxx"
{
  current_packer = &default_packer;
  current_packer->clear_data();
  current_packer->begin_pack(current_switch->get_key_parameter());
}
#line 2906 "dcParser.cxx"
    break;

  case 185: /* switch_case: KW_CASE $@14 parameter_value ':'  */
#line 1276 "dcParser.yxx"
{
  if (!current_packer->end_pack()) {
    yyerror("Invalid value for switch parameter");
    current_switch->add_invalid_case();
  } else {
    int case_index = current_switch->add_case(current_packer->get_string());
    if (case_index == -1) {
      yyerror("Duplicate case value");
    }
  }
}
#line 2922 "dcParser.cxx"
    break;

  case 186: /* switch_default: KW_DEFAULT ':'  */
#line 1291 "dcParser.yxx"
{
  if (!current_switch->add_default()) {
    yyerror("Default case already defined");
  }
}
#line 2932 "dcParser.cxx"
    break;

  case 187: /* switch_break: KW_BREAK  */
#line 1300 "dcParser.yxx"
{
  current_switch->add_break();
}
#line 2940 "dcParser.cxx"
    break;

  case 188: /* switch_field: unnamed_parameter_with_default  */
#line 1307 "dcParser.yxx"
{
  (yyval.u.field) = (yyvsp[0].u.parameter);
}
#line 2948 "dcParser.cxx"
    break;

  case 189: /* switch_field: named_parameter_with_default  */
#line 1311 "dcParser.yxx"
{
  (yyval.u.field) = (yyvsp[0].u.parameter);
}
#line 2956 "dcParser.cxx"
    break;


#line 2960 "dcParser.cxx"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}


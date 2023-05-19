/*
 * Copyright (c) 2023, Max Rodriguez. All rights reserved.
 *
 * All use of this software is subject to the terms of the revised BSD
 * license. You should have received a copy of this license along
 * with this source code in a file named "COPYING".
 *
 * @file DistributedObject.hxx
 * @author Max Rodriguez
 * @date 2023-05-18
 */

#ifndef ASTRON_LIBWASM_DISTRIBUTEDOBJECT_HXX
#define ASTRON_LIBWASM_DISTRIBUTEDOBJECT_HXX

#include <string>

namespace astron { // open namespace

    class DistributedObject {
    public:
        ~DistributedObject();

        inline std::string get_dclass_name() {
            return m_dclass_name;
        }

    protected:
        DistributedObject(std::string dclass_name);

    private:
        std::string m_dclass_name;
    };
} // close namespace

#endif //ASTRON_LIBWASM_DISTRIBUTEDOBJECT_HXX
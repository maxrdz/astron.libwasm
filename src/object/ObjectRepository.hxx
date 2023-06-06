/*
 * Copyright (c) 2023, Max Rodriguez. All rights reserved.
 *
 * All use of this software is subject to the terms of the revised BSD
 * license. You should have received a copy of this license along
 * with this source code in a file named "COPYING".
 *
 * @file ObjectRepository.hxx
 * @author Max Rodriguez
 * @date 2023-05-18
 */

#ifndef ASTRON_LIBWASM_OBJECTREPOSITORY_HXX
#define ASTRON_LIBWASM_OBJECTREPOSITORY_HXX

#include "../network/Connection.hxx"

namespace astron { // open namespace

    class ObjectRepository : public Connection {
    public:
        ObjectRepository();
        ~ObjectRepository();
    };
} // close namespace

#endif //ASTRON_LIBWASM_OBJECTREPOSITORY_HXX
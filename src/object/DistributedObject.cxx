/*
 * Copyright (c) 2023, Max Rodriguez. All rights reserved.
 *
 * All use of this software is subject to the terms of the revised BSD
 * license. You should have received a copy of this license along
 * with this source code in a file named "COPYING".
 *
 * @file DistributedObject.cxx
 * @author Max Rodriguez
 * @date 2023-05-18
 */

#include "DistributedObject.hxx"

namespace astron { // open namespace

    DistributedObject::DistributedObject(std::string dclass_name) : m_dclass_name(dclass_name) {
    }

    DistributedObject::~DistributedObject() {
    }

} // close namespace astron
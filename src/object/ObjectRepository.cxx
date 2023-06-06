/*
 * Copyright (c) 2023, Max Rodriguez. All rights reserved.
 *
 * All use of this software is subject to the terms of the revised BSD
 * license. You should have received a copy of this license along
 * with this source code in a file named "COPYING".
 *
 * @file ObjectRepository.cxx
 * @author Max Rodriguez
 * @date 2023-05-18
 */

#include "ObjectRepository.hxx"
#include "ObjectFactory.hxx"
#include "DistributedObject.hxx"
#include "../network/Datagram.hxx"
#include "../network/DatagramIterator.hxx"

namespace astron { // open namespace

    ObjectRepository::ObjectRepository() {
    }

    ObjectRepository::~ObjectRepository() {
    }

} // close namespace astron
/*
 * Copyright (c) 2013, kestred. All rights reserved.
 * Copyright (c) 2023, Max Rodriguez. All rights reserved.
 *
 * All use of this software is subject to the terms of the revised BSD
 * license. You should have received a copy of this license along
 * with this source code in a file named "COPYING".
 *
 * @file ObjectFactory.cxx
 * @author kestred, Max Rodriguez
 * @date 2023-05-18
 */

#include "ObjectFactory.hxx"

namespace astron { // open namespace

    ObjectFactory ObjectFactory::singleton;

    BaseObjectType::BaseObjectType(const std::string &name)
    {
        ObjectFactory::singleton.add_object_type(name, this);
    }

    void ObjectFactory::add_object_type(const std::string &name, BaseObjectType *factory)
    {
        m_factories[name] = factory;
    }

    DistributedObject* ObjectFactory::instantiate_object(const std::string &dclass_name)
    {
        if(m_factories.find(dclass_name) != m_factories.end())
        {
            return m_factories[dclass_name]->instantiate(dclass_name);
        }
        return NULL;
    }
} // close namespace
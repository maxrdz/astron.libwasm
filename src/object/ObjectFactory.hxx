/*
 * Copyright (c) 2013, kestred. All rights reserved.
 * Copyright (c) 2023, Max Rodriguez. All rights reserved.
 *
 * All use of this software is subject to the terms of the revised BSD
 * license. You should have received a copy of this license along
 * with this source code in a file named "COPYING".
 *
 * @file ObjectFactory.hxx
 * @author kestred, Max Rodriguez
 * @date 2023-05-18
 */

#ifndef ASTRON_LIBWASM_OBJECTFACTORY_HXX
#define ASTRON_LIBWASM_OBJECTFACTORY_HXX

#include "DistributedObject.hxx"
#include <unordered_map>

namespace astron { // open namespace

    class BaseObjectType {
    public:
        virtual DistributedObject* instantiate(std::string name) = 0;
    protected:
        BaseObjectType(const std::string &name);
    };

    template <class T>
    class ObjectType : public BaseObjectType {
    public:
        ObjectType(const std::string &name) : BaseObjectType(name) {
        }

        virtual DistributedObject* instantiate(std::string name) {
            return new T(name);
        }
    };

    class ObjectFactory {
    public:
        DistributedObject* instantiate_object(const std::string &dclass_name);
        static ObjectFactory singleton;

        void add_object_type(const std::string &name, BaseObjectType *factory);
    private:
        std::unordered_map<std::string, BaseObjectType*> m_factories;
    };

} // close namespace

#endif //ASTRON_LIBWASM_OBJECTFACTORY_HXX

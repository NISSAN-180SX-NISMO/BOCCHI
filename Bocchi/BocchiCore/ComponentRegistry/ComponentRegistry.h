#pragma once
#ifndef BOCCHI_COMPONENTREGISTRY_H
#define BOCCHI_COMPONENTREGISTRY_H
#include <unordered_map>
#include <string>
#include <functional>
#include <memory>
#include <iostream>
#include <any>
#include "ComponentRegistryException.h"
#include "Object.h"

#define COMPONENT(className) \
class className; \
class className##ComponentFactory { \
public: \
    className##ComponentFactory() { \
        ComponentRegistry::registerComponent<className>(#className); \
    } \
}; \
inline className##ComponentFactory className##Factory; \
class className

typedef std::unordered_map<std::string, std::function<Object*()>> RegistryMap;

namespace ComponentRegistry {
    inline RegistryMap registryMap;

    template <class ComponentType>
    inline void registerComponent(const std::string& componentName) {
        registryMap[componentName] = []() -> Object*  {
            return reinterpret_cast<Object*>(new ComponentType());
        };
#ifdef DEBUG
        std::cout << componentName << " with sizeof = " << sizeof(ComponentType) << " registered" << std::endl;
#endif
    }

    template <class ComponentType>
    inline ComponentType* initComponent(const std::string& componentName){
#ifdef DEBUG
        std::cout << componentName << "ComponentRegistry::initComponent: " << std::endl;
#endif
        if (registryMap.find(componentName) == registryMap.end()) throw ComponentRegistryExceptionTypeNotFound("Component not found!");
        return reinterpret_cast<ComponentType*>(registryMap[componentName]());
    }
};

#endif //BOCCHI_COMPONENTREGISTRY_H

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

typedef std::unordered_map<std::string, std::function<std::any()>> RegistryMap;

namespace ComponentRegistry {
    inline RegistryMap registryMap;

    template <class ComponentType>
    inline void registerComponent(const std::string& componentName) {
        registryMap[componentName] = []() -> std::shared_ptr<ComponentType>  {
            return std::make_shared<ComponentType>();
        };
#ifdef DEBUG
        std::cout << componentName << " with sizeof = " << sizeof(ComponentType) << " registered" << std::endl;
#endif
    }

    template <class ComponentType>
    inline std::shared_ptr<ComponentType> initComponent(const std::string& componentName){
        std::cout << componentName << "ComponentRegistry::initComponent: " << std::endl;
        if (registryMap.find(componentName) == registryMap.end()) throw ComponentRegistryExceptionTypeNotFound("Component not found!");
        return std::any_cast<std::shared_ptr<ComponentType>>(registryMap[componentName]());
    }
};

#endif //BOCCHI_COMPONENTREGISTRY_H

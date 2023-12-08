#pragma once
#ifndef BOCCHI_CONTEXT_H
#define BOCCHI_CONTEXT_H
#include <memory>
#include "../ComponentRegistry/ComponentRegistry.h"

typedef std::unordered_map<std::string, Object*> ContextMap;

class Context {
private:
    static std::shared_ptr<Context> context;
    ContextMap contextMap;
    Context();
public:
    Context(const Context&) = delete;
    Context(Context&&) = delete;

    template<class ComponentType>
    ComponentType* getComponent(const std::string& componentName) {
        std::cout << "Context::getComponent: " << std::endl;
        return reinterpret_cast<ComponentType*>(this->contextMap[componentName]);
    }
    ContextMap getContextMap();
    static std::shared_ptr<Context>& getContext();
};


#endif //BOCCHI_CONTEXT_H

#pragma once
#ifndef BOCCHI_CONTEXT_H
#define BOCCHI_CONTEXT_H
#include <memory>
#include "../ComponentRegistry/ComponentRegistry.h"

typedef std::unordered_map<std::string, std::any> ContextMap;

class Context {
private:
    static std::shared_ptr<Context> context;
    ContextMap contextMap;
    Context();
public:
    Context(const Context&) = delete;
    Context(Context&&) = delete;

    template<class ComponentType>
    std::shared_ptr<BaseComponentType> getComponent(const std::string& componentName) {
        std::cout << "Context::getComponent: " << std::endl;

        return std::any_cast<std::shared_ptr<ComponentType>>(this->contextMap[componentName]);
    }
    ContextMap getContextMap();
    static std::shared_ptr<Context>& getContext();
};


#endif //BOCCHI_CONTEXT_H

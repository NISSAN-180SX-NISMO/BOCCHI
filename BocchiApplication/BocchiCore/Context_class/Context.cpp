//
// Created by user on 07.12.2023.
//

#include "Context.h"

std::shared_ptr<Context> Context::context = nullptr;

Context::Context() {
    for (auto& declaration : ComponentRegistry::registryMap)
        this->contextMap[declaration.first] = declaration.second();

}

std::shared_ptr<Context> &Context::getContext() {
    if (context == nullptr) context = std::unique_ptr<Context>(new Context());
    return context;
}
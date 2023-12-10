#pragma once
#ifndef BOCCHI_COMPONENTREGISTRYEXCEPTION_H
#define BOCCHI_COMPONENTREGISTRYEXCEPTION_H
#ifndef LISING
#include <exception>
#endif

class ComponentRegistryException : public std::exception {
private:
    const char *message;
public:
    explicit ComponentRegistryException(const char* message) : message(message) {}
    [[nodiscard]] const char* what() const noexcept override {
        return message;
    }

};

class ComponentRegistryExceptionTypeNotFound : public ComponentRegistryException {
public:
    explicit ComponentRegistryExceptionTypeNotFound(const char* message) : ComponentRegistryException(message) {}
};

#endif //BOCCHI_COMPONENTREGISTRYEXCEPTION_H

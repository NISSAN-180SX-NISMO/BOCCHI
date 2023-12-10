#pragma once
#ifndef BOCCHI_MENUCASE_H
#define BOCCHI_MENUCASE_H

#include <string>
#include <memory>
#define NONE_PARENT "none_parent"
#define NONE_TITLE ""

#define SUBMENU(name, title, parentName) \
class name : public MenuCase { \
public: \
std::string getTitle() override { \
return title; \
} \
 \
void exec() override { \
 \
} \
std::string getParent() override { \
return parentName; \
} \
}

class MenuCase {
private:
public:
    MenuCase() = default;
    virtual ~MenuCase() = default;
    virtual std::string getTitle() = 0;
    virtual void exec() = 0;
    virtual std::string getParent() = 0;
};

#endif //BOCCHI_MENUCASE_H

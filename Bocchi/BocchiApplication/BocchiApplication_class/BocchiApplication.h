#pragma once
#ifndef BOCCHI_BOCCHIAPPLICATION_H
#define BOCCHI_BOCCHIAPPLICATION_H
#include <memory>
#include "map"
#include "../../BocchiCore/Context_class/Context.h"
#include "../MenuCase.h"

class BocchiApplication {
private:
    std::shared_ptr<Context> context;
    static std::multimap<MenuCase*, MenuCase*> menuMap;
    std::vector<MenuCase*> buildMenuCaseVector();
    void buildMenuMap(const std::vector<MenuCase*>&);
    struct Statement {
        MenuCase* menuCase;
        size_t lvl;
    } currentStatement;
    void show();
public:
    BocchiApplication(MenuCase* mainCase);
    int run();


};

#endif //BOCCHI_BOCCHIAPPLICATION_H

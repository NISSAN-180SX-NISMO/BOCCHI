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
    static std::multimap<std::shared_ptr<MenuCase>, std::shared_ptr<MenuCase>> menuMap;
    std::vector<std::shared_ptr<MenuCase>> buildMenuCaseVector();
    void buildMenuMap(const std::vector<std::shared_ptr<MenuCase>>&);
    struct Statement {
        std::shared_ptr<MenuCase> menuCase;
        size_t lvl;
    } currentStatement;
    void show();
public:
    BocchiApplication(std::shared_ptr<MenuCase> mainCase);
    int run();


};

#endif //BOCCHI_BOCCHIAPPLICATION_H

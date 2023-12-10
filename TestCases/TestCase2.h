//
// Created by user on 08.12.2023.
//

#ifndef BOCCHI_TESTCASE2_H
#define BOCCHI_TESTCASE2_H

#include "../Bocchi/BocchiCore/ComponentRegistry/ComponentRegistry.h"
#include "../Bocchi/BocchiApplication/MenuCase.h"


COMPONENT(TestMenu2);
class TestMenu2 : public MenuCase {
public:
    std::string getTitle() override {
        return "2) Second menu case";
    }

    void exec() override {

    }

    std::string getParent() override {
        return "MainMenuCase";
    }
};


COMPONENT(TestCase4);
SUBMENU(TestCase4, "4) Fourth menu case", "MainMenuCase");

COMPONENT(TestCase5);
SUBMENU(TestCase5, "5) Fifth menu case", "TestMenu2");

COMPONENT(TestCase6);
SUBMENU(TestCase6, "6) Sixth menu case", "TestMenu2");

COMPONENT(TestCase7);
SUBMENU(TestCase7, "7) Seventh menu case", "TestCase6");

COMPONENT(TestCase8);
SUBMENU(TestCase8, "8) Eighth menu case", "TestCase6");

#endif //BOCCHI_TESTCASE2_H

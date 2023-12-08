//
// Created by user on 08.12.2023.
//

#ifndef BOCCHI_TESTCASE1_H
#define BOCCHI_TESTCASE1_H

#include "../Bocchi/BocchiCore/ComponentRegistry/ComponentRegistry.h"
#include "../Bocchi/BocchiApplication/MenuCase.h"

COMPONENT(TestMenu1);
class TestMenu1 : public MenuCase {
public:
    std::string getTitle() override {
        return "1) First menu case";
    }

    void exec() override {

    }

    std::string getParent() override {
        return "MainMenuCase";
    }
};

#endif //BOCCHI_TESTCASE1_H

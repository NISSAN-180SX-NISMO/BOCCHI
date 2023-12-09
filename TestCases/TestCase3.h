//
// Created by user on 08.12.2023.
//

#ifndef BOCCHI_TESTCASE3_H
#define BOCCHI_TESTCASE3_H

#include "../Bocchi/BocchiCore/ComponentRegistry/ComponentRegistry.h"
#include "../Bocchi/BocchiApplication/MenuCase.h"

COMPONENT(TestMenu3);
class TestMenu3 : public MenuCase {
public:
    std::string getTitle() override {
        return "3) Third menu case";
    }

    void exec() override {

    }

    std::string getParent() override {
        return "MainMenuCase";
    }
};

#endif //BOCCHI_TESTCASE3_H

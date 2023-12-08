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

#endif //BOCCHI_TESTCASE2_H

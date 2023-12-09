//
// Created by user on 09.12.2023.
//

#ifndef BOCCHI_TESTCASE2_1_H
#define BOCCHI_TESTCASE2_1_H

#include "../Bocchi/BocchiApplication/MenuCase.h"
#include "../Bocchi/BocchiCore/ComponentRegistry/ComponentRegistry.h"

COMPONENT(TestMenu2_1);
class TestMenu2_1 : public MenuCase {
public:
    std::string getTitle() override {
        return "2.1) Sub second menu case 1";
    }

    void exec() override {

    }

    std::string getParent() override {
        return "TestMenu2";
    }
};

#endif //BOCCHI_TESTCASE2_1_H

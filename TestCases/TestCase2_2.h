//
// Created by user on 09.12.2023.
//

#ifndef BOCCHI_TESTCASE2_2_H
#define BOCCHI_TESTCASE2_2_H

#include "../Bocchi/BocchiApplication/MenuCase.h"
#include "../Bocchi/BocchiCore/ComponentRegistry/ComponentRegistry.h"

COMPONENT(TestMenu2_2);
class TestMenu2_2 : public MenuCase {
public:
    std::string getTitle() override {
        return "2.2) Sub second menu case 2";
    }

    void exec() override {

    }

    std::string getParent() override {
        return "TestMenu2";
    }
};

#endif //BOCCHI_TESTCASE2_2_H

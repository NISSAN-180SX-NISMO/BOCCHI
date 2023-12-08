#pragma once
#ifndef BOCCHI_MAINMENUCASE_H
#define BOCCHI_MAINMENUCASE_H
#include "Bocchi/BocchiApplication/MenuCase.h"
#include "Bocchi/BocchiCore/ComponentRegistry/ComponentRegistry.h"

COMPONENT(MainMenuCase);
class MainMenuCase : public MenuCase {
public:
    std::string getTitle() override {
        return NONE_TITLE;
    }

    void exec() override {

    }

    std::string getParent() override {
        return NONE_PARENT;
    }
};

#endif //BOCCHI_MAINMENUCASE_H

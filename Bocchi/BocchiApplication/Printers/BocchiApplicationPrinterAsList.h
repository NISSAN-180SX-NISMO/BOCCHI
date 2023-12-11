//
// Created by user on 11.12.2023.
//

#ifndef BOCCHI_BOCCHIAPPLICATIONPRINTERASLIST_H
#define BOCCHI_BOCCHIAPPLICATIONPRINTERASLIST_H
#ifndef LISING
#include <map>
#include <stack>
#endif
#include "BocchiApplicationPrinterInterface.h"
#include "../../BocchiCore/Context_class/Context.h"
#include "../MenuState.h"
#include "../../EventSystem/ObserverInterface.h"
#include "../BocchiApplicationStateUpdater.h"
#include "../../../MainMenuCase.h"

class BocchiApplicationPrinterAsList : public BocchiApplicationPrinterInterface {
private:
    std::shared_ptr<std::multimap<MenuCase*, MenuCase*>> menuMap;
    std::shared_ptr<MenuState> currentState;
public:
    explicit BocchiApplicationPrinterAsList()
            :
            BocchiApplicationPrinterInterface(),
            currentState(std::make_shared<MenuState>()),
            menuMap(std::make_shared<std::multimap<MenuCase*, MenuCase*>>()) { }

    void init(std::vector<MenuCase*> menuCaseVector) override {
        for (auto& menuCase : menuCaseVector){
            auto parent = Context::getContext()->getComponent<MenuCase>(menuCase->getParent());
            menuMap->insert(std::pair<MenuCase*, MenuCase*>(parent, menuCase));
        }
        std::vector<std::pair<MenuCase*, MenuCase*>> tempVector(menuMap->begin(), menuMap->end());
        std::sort(tempVector.begin(), tempVector.end(), [](const auto &a, const auto &b) {
            return b.first ?  a.second->getTitle() <= b.second->getTitle() : true;
        });
        menuMap->clear();
        menuMap->insert(tempVector.begin(), tempVector.end());

        this->currentState->rootMenuCase = Context::getContext()->getComponent<MainMenuCase>("MainMenuCase");
        this->currentState->choosedMenuCase = menuMap->find(this->currentState->rootMenuCase)->second;
        this->currentState->lvl = 0;
        this->currentState->currentMenuCases = std::make_shared<Carousel<MenuCase*>>(menuMap->equal_range(this->currentState->rootMenuCase));
    }

    ~BocchiApplicationPrinterAsList() override = default;

    void show() override {
        system("cls");
        std::stack<MenuCase*> currentMenuCasePath;
        auto current = this->currentState->rootMenuCase;
        while(current->getTitle() != Context::getContext()->getComponent<MainMenuCase>("MainMenuCase")->getTitle()) {
            currentMenuCasePath.push(current);
            current = std::find_if(menuMap->begin(), menuMap->end(), [current](const auto& pair) {
                return pair.second == current;
            })->first;
        }


            auto submenmu = menuMap->equal_range(this->currentState->rootMenuCase);
    for (auto jt = submenmu.first; jt != submenmu.second; ++jt) {
        if (jt->second->getTitle() == this->currentState->choosedMenuCase->getTitle()) {
            greenPrint(jt->second->getTitle());
        } else  Print(jt->second->getTitle());
    }
    }

    void input() override {

    }

    void print() override {

    }

    std::shared_ptr<MenuState> getState() override {
        return this->currentState;
    }

    std::shared_ptr<std::multimap<MenuCase *, MenuCase *>> getMap() override {
        return this->menuMap;
    }

};

#endif //BOCCHI_BOCCHIAPPLICATIONPRINTERASLIST_H

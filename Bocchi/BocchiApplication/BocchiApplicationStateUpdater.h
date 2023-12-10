#ifndef BOCCHI_BOCCHIAPPLICATIONSTATEUPDATER_H
#define BOCCHI_BOCCHIAPPLICATIONSTATEUPDATER_H

#ifndef LISING
#include <utility>
#include <map>
#include <stack>
#include "memory"
#endif

#include "../EventSystem/ObserverInterface.h"
#include "MenuState.h"

class BocchiApplicationStateUpdater : public ObserverInterface {
    std::shared_ptr<MenuState> state;
    std::shared_ptr<std::multimap<MenuCase*, MenuCase*>> menuMap;
    std::stack<size_t> lastInPoint;

public:
    explicit BocchiApplicationStateUpdater(std::shared_ptr<MenuState> state,  std::shared_ptr<std::multimap<MenuCase*, MenuCase*>> menuMap)
    : ObserverInterface() {
        this->state = std::move(state);
        this->menuMap = menuMap;
    }
    void update(KEY key) override {
        switch (key) {
            case UP:
                this->state->choosedMenuCase = this->state->currentMenuCases->getPrevious();
                break;
            case DOWN:
                this->state->choosedMenuCase = this->state->currentMenuCases->getNext();
                break;
            case ENTER:
                this->state->choosedMenuCase->exec();
                if (std::make_shared<Carousel<MenuCase*>>(menuMap->equal_range(this->state->choosedMenuCase))->empty())
                    break;
                this->state->rootMenuCase = this->state->choosedMenuCase;
                this->state->choosedMenuCase = this->menuMap->find(this->state->rootMenuCase)->second;
                this->state->lvl++;
                this->lastInPoint.push(this->state->currentMenuCases->getCurrentIndex());
                this->state->currentMenuCases = std::make_shared<Carousel<MenuCase*>>(menuMap->equal_range(this->state->rootMenuCase));
                break;
            case ESCAPE:
                if (this->state->lvl == 0)
                    break;
                this->state->choosedMenuCase = this->state->rootMenuCase;
                this->state->rootMenuCase = (std::find_if(menuMap->begin(), menuMap->end(), [this](const auto& pair) {
                    return pair.second == this->state->choosedMenuCase;
                }))->first;
                this->state->lvl--;
                this->state->currentMenuCases = std::make_shared<Carousel<MenuCase*>>(menuMap->equal_range(this->state->rootMenuCase), this->lastInPoint.top());
                this->lastInPoint.pop();
                break;
        }
    }
} ;


#endif //BOCCHI_BOCCHIAPPLICATIONSTATEUPDATER_H

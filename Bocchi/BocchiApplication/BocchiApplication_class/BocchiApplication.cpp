#include "BocchiApplication.h"
#include "../../EventSystem/ConsoleHandler.h"
#include <memory>
#include <utility>
#include <algorithm>

std::shared_ptr<std::multimap<MenuCase*, MenuCase*>> BocchiApplication::menuMap = std::make_shared<std::multimap<MenuCase*, MenuCase*>>();

BocchiApplication::BocchiApplication(MenuCase* mainCase) {
    this->consoleHandler = std::make_shared<ConsoleHandler>(this->menuStateUpdater);
#ifdef DEBUG
    std::cout  << "BocchiApplication::constructor: " << std::endl;
#endif
    buildMenuMap(buildMenuCaseVector());
    std::vector<std::pair<MenuCase*, MenuCase*>> tempVector(menuMap->begin(), menuMap->end());
    std::sort(tempVector.begin(), tempVector.end(), [](const auto &a, const auto &b) {
        return b.first ?  a.second->getTitle() <= b.second->getTitle() : true;
    });
    BocchiApplication::menuMap->clear();
    BocchiApplication::menuMap->insert(tempVector.begin(), tempVector.end());

    this->currentState->rootMenuCase = std::move(mainCase);
    this->currentState->choosedMenuCase = this->menuMap->find(this->currentState->rootMenuCase)->second;
    this->currentState->lvl = 0;
    this->currentState->currentMenuCases = std::make_shared<Carousel<MenuCase*>>(BocchiApplication::menuMap->equal_range(this->currentState->rootMenuCase));
}

int BocchiApplication::run() {
   while (true){
       show();
       this->consoleHandler->listen();
   }
}

std::vector<MenuCase*> BocchiApplication::buildMenuCaseVector() {
#ifdef DEBUG
    std::cout << "BocchiApplication::buildMenuCaseVector()" << std::endl;
#endif
    this->context = Context::getContext();
    std::vector<MenuCase*> menuCaseVector;
    for (auto& menuCase : this->context->getContextMap())
        menuCaseVector.push_back(reinterpret_cast<MenuCase*>(menuCase.second));

    return menuCaseVector;
}

void BocchiApplication::buildMenuMap(const std::vector<MenuCase*>& menuCaseVector) {
    for (auto& menuCase : menuCaseVector){
#ifdef DEBUG
        std::cout << "BocchiApplication::buildMenuMap: " << std::endl;
#endif
        auto parent = this->context->getComponent<MenuCase>(menuCase->getParent());
        BocchiApplication::menuMap->insert(std::pair<MenuCase*, MenuCase*>(parent, menuCase));
    }
}

void BocchiApplication::show() {
    system("cls");
#ifdef DEBUG
    std::cout << this->currentState.menuCase->getTitle() << std::endl;
#endif
    auto childs = BocchiApplication::menuMap->equal_range(this->currentState->rootMenuCase);
    for (auto it = childs.first; it != childs.second; ++it) {
        for (int i = 0; i < currentState->lvl; ++i) std::cout << "\t";
        if (it->second->getTitle() == this->currentState->choosedMenuCase->getTitle()) {
            green_print(it->second->getTitle());
        } else print(it->second->getTitle());

    }
}

std::shared_ptr<BocchiApplication> BocchiApplication::instance = nullptr;

std::shared_ptr<BocchiApplication> BocchiApplication::getInstance(MenuCase *mainCase) {
    if (!BocchiApplication::instance) BocchiApplication::instance = std::shared_ptr<BocchiApplication>(new BocchiApplication(mainCase));
    return BocchiApplication::instance;
}

std::shared_ptr<BocchiApplication> BocchiApplication::getInstance() {
    return BocchiApplication::instance;
}

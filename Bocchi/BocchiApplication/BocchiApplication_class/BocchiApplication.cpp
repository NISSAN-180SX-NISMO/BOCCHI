#include "BocchiApplication.h"
#include <utility>
#include <conio.h>

std::multimap<MenuCase*, MenuCase*> BocchiApplication::menuMap;

BocchiApplication::BocchiApplication(MenuCase* mainCase) {
#ifdef DEBUG
    std::cout  << "BocchiApplication::constructor: " << std::endl;
#endif
    this->currentStatement.menuCase = std::move(mainCase);
    this->currentStatement.lvl = 0;
    buildMenuMap(buildMenuCaseVector());
}

int BocchiApplication::run() {
   while (true){
       show();
       _getch();
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
        BocchiApplication::menuMap.insert(std::make_pair(parent, menuCase));
    }
}

void BocchiApplication::show() {
#ifdef DEBUG
    std::cout << this->currentStatement.menuCase->getTitle() << std::endl;
#endif
    auto childs = BocchiApplication::menuMap.equal_range(this->currentStatement.menuCase);
    for (auto it = childs.first; it != childs.second; ++it) {
        for (int i = 0; i < currentStatement.lvl; ++i)
            std::cout << " ";
        std::cout << it->second->getTitle() << std::endl;
    }
}

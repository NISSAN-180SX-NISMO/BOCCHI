//
// Created by user on 08.12.2023.
//

#ifndef BOCCHI_MENUSTATE_H
#define BOCCHI_MENUSTATE_H

#include "MenuCase.h"
#include "../Utils/Carousel.h"


struct MenuState {
    std::shared_ptr<Carousel<MenuCase*>> currentMenuCases;
    MenuCase* rootMenuCase;
    MenuCase* choosedMenuCase;
    size_t lvl;
};

#endif //BOCCHI_MENUSTATE_H

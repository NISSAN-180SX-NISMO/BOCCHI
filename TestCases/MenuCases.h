
#ifndef BOCCHI_MENUCASES_H
#define BOCCHI_MENUCASES_H

// объявим и свяжем те пункты меню, которые не несут никакой фцункциональности кроме вызова других пунктов меню

#include "../Bocchi/BocchiCore/ComponentRegistry/ComponentRegistry.h"
#include "../Bocchi/BocchiApplication/MenuCase.h"
#include "../MainMenuCase.h"

COMPONENT(MenuCase1);
SUBMENU(MenuCase1, "1) Simple math operations", MainMenuCase);

    COMPONENT(MenuCase1_1);
    PAYLOADSUBMENU(MenuCase1_1, "1) Sum", MenuCase1);

    COMPONENT(MenuCase1_2);
    PAYLOADSUBMENU(MenuCase1_2, "2) Diff", MenuCase1);

    COMPONENT(MenuCase1_3);
    PAYLOADSUBMENU(MenuCase1_3, "3) Mult", MenuCase1);

    COMPONENT(MenuCase1_4);
    PAYLOADSUBMENU(MenuCase1_4, "4) Pow", MenuCase1);

COMPONENT(MenuCase2);
SUBMENU(MenuCase2, "2) Something more difficult", MainMenuCase);

    COMPONENT(MenuCase2_1);
    SUBMENU(MenuCase2_1, "1) Precisely calculate sin", MenuCase2);

        COMPONENT(MenuCase2_1_1);
        PAYLOADSUBMENU(MenuCase2_1_1, "1) Makloren", MenuCase2_1);

        COMPONENT(MenuCase2_1_2);
        PAYLOADSUBMENU(MenuCase2_1_2, "2) Bhaskara", MenuCase2_1);

        COMPONENT(MenuCase2_1_3);
        PAYLOADSUBMENU(MenuCase2_1_3, "3) CORDIC", MenuCase2_1);

    COMPONENT(MenuCase2_2);
    SUBMENU(MenuCase2_2, "2) Calculate difficult math expression", MenuCase2);

COMPONENT(MenuCase3);
SUBMENU(MenuCase3, "3) Run my COOL PIRATE SHIP game", MainMenuCase);






#endif //BOCCHI_MENUCASES_H

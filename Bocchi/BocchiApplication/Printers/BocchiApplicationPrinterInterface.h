//
// Created by user on 11.12.2023.
//

#ifndef BOCCHI_BOCCHIAPPLICATIONPRINTERINTERFACE_H
#define BOCCHI_BOCCHIAPPLICATIONPRINTERINTERFACE_H
#ifndef LISING
#include <vector>
#include <Windows.h>
#include <map>

#endif
#include "../MenuCase.h"
#include "../MenuState.h"

#define Print(x) printf((x + "\n").c_str())
#define greenPrint(x) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_INTENSITY); Print(x); SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN)


class BocchiApplicationPrinterInterface {
public:
    BocchiApplicationPrinterInterface() = default;
    virtual ~BocchiApplicationPrinterInterface() = default;
    virtual std::shared_ptr<MenuState> getState() = 0;
    virtual std::shared_ptr<std::multimap<MenuCase*, MenuCase*>>  getMap() = 0;
    virtual void init (std::vector<MenuCase*> menuCaseVector) = 0;
    virtual void show() = 0;
    virtual void input() = 0;
    virtual void print() = 0;
};

#endif //BOCCHI_BOCCHIAPPLICATIONPRINTERINTERFACE_H

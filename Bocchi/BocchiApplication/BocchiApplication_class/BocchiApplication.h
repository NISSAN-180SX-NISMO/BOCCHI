#pragma once
#ifndef BOCCHI_BOCCHIAPPLICATION_H
#define BOCCHI_BOCCHIAPPLICATION_H
#include <memory>
#include "map"
#include "../../BocchiCore/Context_class/Context.h"
#include "../MenuCase.h"
#include "../IncludeComponents.h"
#include "../../EventSystem/ObserverInterface.h"
#include "../MenuState.h"
#include "../../EventSystem/ObservedInterface.h"
#include "../BocchiApplicationStateUpdater.h"
#include "../../EventSystem/ConsoleHandler.h"
#include <Windows.h>

#define print(x) printf((x + "\n").c_str())
#define green_print(x) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_INTENSITY); print(x); SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN)

class BocchiApplication {
private:
    std::shared_ptr<Context> context;
    static std::shared_ptr<std::multimap<MenuCase*, MenuCase*>> menuMap;
    std::vector<MenuCase*> buildMenuCaseVector();
    void buildMenuMap(const std::vector<MenuCase*>&);
    std::shared_ptr<MenuState> currentState = std::make_shared<MenuState>();
    std::shared_ptr<ObserverInterface> menuStateUpdater = std::make_shared<BocchiApplicationStateUpdater>(this->currentState, BocchiApplication::menuMap);
    std::shared_ptr<ConsoleHandler> consoleHandler;
    void show();
    explicit BocchiApplication(MenuCase* mainCase);
    static std::shared_ptr<BocchiApplication> instance;
public:
    static std::shared_ptr<BocchiApplication> getInstance(MenuCase* mainCase);
    static std::shared_ptr<BocchiApplication> getInstance();
    int run();


};

#endif //BOCCHI_BOCCHIAPPLICATION_H

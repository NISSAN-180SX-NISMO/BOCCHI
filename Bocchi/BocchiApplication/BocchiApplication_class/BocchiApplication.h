#pragma once
#ifndef BOCCHI_BOCCHIAPPLICATION_H
#define BOCCHI_BOCCHIAPPLICATION_H
#ifndef LISING
#include <memory>
#include "map"
#include <Windows.h>
#include <memory>
#include <utility>
#include <algorithm>
#include <queue>
#endif
#include "../../BocchiCore/Context_class/Context.h"
#include "../MenuCase.h"
#include "../IncludeComponents.h"
#include "../../EventSystem/ObserverInterface.h"
#include "../MenuState.h"
#include "../../EventSystem/ObservedInterface.h"
#include "../BocchiApplicationStateUpdater.h"
#include "../../EventSystem/ConsoleHandler.h"
#include "../Printers/BocchiApplicationPrinterInterface.h"


class BocchiApplication {
private:
    static std::shared_ptr<BocchiApplication> instance;
private:
    std::shared_ptr<BocchiApplicationPrinterInterface> printer;
    std::shared_ptr<ConsoleHandler> consoleHandler;
    std::shared_ptr<ObserverInterface> menuStateUpdater;
    std::vector<MenuCase*> buildMenuCaseVector();
    explicit BocchiApplication(const std::shared_ptr<BocchiApplicationPrinterInterface>& printer);
public:
    static std::shared_ptr<BocchiApplication> getInstance(const std::shared_ptr<BocchiApplicationPrinterInterface>&);
    int run();


};

#endif //BOCCHI_BOCCHIAPPLICATION_H

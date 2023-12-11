#include "BocchiApplication.h"
#include "../../EventSystem/ConsoleHandler.h"




BocchiApplication::BocchiApplication(const std::shared_ptr<BocchiApplicationPrinterInterface>& specificPrinter)
:
        printer(specificPrinter)
{
    printer->init(buildMenuCaseVector());
    this->menuStateUpdater = std::make_shared<BocchiApplicationStateUpdater>(printer->getState(), printer->getMap());
    this->consoleHandler = std::make_shared<ConsoleHandler>(menuStateUpdater);
}

int BocchiApplication::run() {
   while (true){
       printer->show();
       this->consoleHandler->listen();
   }
   return 1;
}

std::vector<MenuCase*> BocchiApplication::buildMenuCaseVector() {
    std::vector<MenuCase*> menuCaseVector;
    for (auto& menuCase : Context::getContext()->getContextMap())
        menuCaseVector.push_back(reinterpret_cast<MenuCase*>(menuCase.second));

    return menuCaseVector;
}


std::shared_ptr<BocchiApplication> BocchiApplication::instance = nullptr;

std::shared_ptr<BocchiApplication> BocchiApplication::getInstance(const std::shared_ptr<BocchiApplicationPrinterInterface>& specificPrinter) {
    std::cout << "BocchiApplication::getInstance: " << std::endl;
    if (!BocchiApplication::instance)
        BocchiApplication::instance =
                std::shared_ptr<BocchiApplication>(
                        new BocchiApplication(specificPrinter)
                        );
    return BocchiApplication::instance;
}


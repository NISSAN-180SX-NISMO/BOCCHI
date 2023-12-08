#define DEBUG
#include "Bocchi/BocchiApplication/BocchiApplication_class/BocchiApplication.h"
//#include "MainMenuCase.h"



int main() {
    std::cout << "main: " << std::endl;
    BocchiApplication bocchiApplication(Context::getContext()->getComponent<MainMenuCase>("MainMenuCase"));
    return bocchiApplication.run();
}

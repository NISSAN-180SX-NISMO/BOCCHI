//#define DEBUG
//#define LISING
#include "Bocchi/BocchiApplication/BocchiApplication_class/BocchiApplication.h"





int main() {
    BocchiApplication bocchiApplication = *BocchiApplication::getInstance(Context::getContext()->getComponent<MainMenuCase>("MainMenuCase"));
    return bocchiApplication.run();
}

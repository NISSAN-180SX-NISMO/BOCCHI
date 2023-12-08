#define DEBUG
#include "Bocchi/BocchiApplication/BocchiApplication_class/BocchiApplication.h"
#include "MainMenuCase.h"

COMPONENT(TestMenu1);
class TestMenu1 : public MenuCase {
public:
    std::string getTitle() override {
        return "1) First menu case";
    }

    void exec() override {

    }

    std::string getParent() override {
        return "MainMenuCase";
    }
};

COMPONENT(TestMenu2);
class TestMenu2 : public MenuCase {
public:
    std::string getTitle() override {
        return "2) Second menu case";
    }

    void exec() override {

    }

    std::string getParent() override {
        return "MainMenuCase";
    }
};

int main() {
    std::cout << "main: " << std::endl;
    BocchiApplication bocchiApplication(Context::getContext()->getComponent<MainMenuCase>("MainMenuCase"));
    return bocchiApplication.run();
}

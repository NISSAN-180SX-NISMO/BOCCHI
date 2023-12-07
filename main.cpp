#define DEBUG
#include "BocchiApplication/BocchiCore/Context_class/Context.h"
#include "TestClass.h"

int main() {
    std::cout << "\nDefault definition" << std::endl;
    std::shared_ptr<TestClass> testClass = ComponentRegistry::initComponent<TestClass>("TestClass");
    std::shared_ptr<TestClass> testClass2 = ComponentRegistry::initComponent<TestClass>("TestClass");
    std::shared_ptr<TestClass> testClass3 = ComponentRegistry::initComponent<TestClass>("TestClass");

    std::cout << "\nSingleton definition" << std::endl;
    auto context = Context::getContext();
    std::shared_ptr<TestClass> testClass4 = context->getComponent<TestClass>("TestClass");
    std::shared_ptr<TestClass> testClass5 = context->getComponent<TestClass>("TestClass");
    std::shared_ptr<TestClass> testClass6 = context->getComponent<TestClass>("TestClass");

    return 0;
}

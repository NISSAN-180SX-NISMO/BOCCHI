#pragma once
#ifndef BOCCHI_TESTCLASS_H
#define BOCCHI_TESTCLASS_H

#include "BocchiApplication/BocchiCore/ComponentRegistry/ComponentRegistry.h"

COMPONENT(TestClass);
class TestClass : public ParentComponent {
    static int id;
public:
    TestClass() {
        std::cout << "TestClass with id = " << TestClass::id++ << " constructed" << std::endl;
    }
};

#endif //BOCCHI_TESTCLASS_H

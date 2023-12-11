//#define DEBUG
//#define LISING
#include "Bocchi/BocchiApplication/BocchiApplication_class/BocchiApplication.h"
#include "Bocchi/BocchiApplication/Printers/BocchiApplicationPrinterAsTree.h"
#include "Bocchi/BocchiApplication/Printers/BocchiApplicationPrinterAsList.h"


int main() {
    //auto printer = std::make_shared<BocchiApplicationPrinterAsTree>();
    auto printer = std::make_shared<BocchiApplicationPrinterAsList>();
    BocchiApplication bocchiApplication = *BocchiApplication::getInstance(printer);
    return bocchiApplication.run();
}

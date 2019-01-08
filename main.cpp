#include <cstdlib>
#include <iostream>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/ui/text/TextTestRunner.h>
#include <cppunit/extensions/HelperMacros.h>
#include "Printer.h"
#include <cstring>

using namespace std;

class PrinterTest : public CppUnit::TestCase
{
public:
    void checkPrinter() {
        Printer printer("print something");
        CPPUNIT_ASSERT_EQUAL_MESSAGE("Printer::constructor: выводимое сообщение должно соответствовать введённым параметрам!", printer.PrintMessage(), (string)"print something");
    };

    CPPUNIT_TEST_SUITE( PrinterTest );
    CPPUNIT_TEST( checkPrinter );
    CPPUNIT_TEST_SUITE_END();
};

CPPUNIT_TEST_SUITE_REGISTRATION( PrinterTest );

int main(int argc, char* argv[]) {
    if (argc >= 2) {
        if ( (strcmp(argv[1], "-t") == 0) || (strcmp(argv[1], "--test") == 0) )
        {
            CppUnit::Test *test = CppUnit::TestFactoryRegistry::getRegistry().makeTest();
            CppUnit::TextTestRunner runner;
            runner.addTest(test);

            runner.run();

            exit(0);
        }

        Printer printer(argv[1]);
        std::cout << printer.PrintMessage() << std::endl;
    }
    else if (argc == 1){
        Printer printer("");
        std::cout << printer.PrintMessage() << std::endl;
    }
}

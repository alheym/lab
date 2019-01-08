#include <iostream>

using namespace std;

class Printer {
public:
    Printer(const string& aText);
    string PrintMessage();
private:
    string Message;
};
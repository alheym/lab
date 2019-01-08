#include "Printer.h"

Printer::Printer(const string& aMessage)
{
    Message = aMessage;
}

string Printer::PrintMessage()
{
    return (string) Message;
}
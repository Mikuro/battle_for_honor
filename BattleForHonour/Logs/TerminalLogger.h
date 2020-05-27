#ifndef BATTLEFORHONOUR_TERMINALLOGGER_H
#define BATTLEFORHONOUR_TERMINALLOGGER_H


#include <iostream>
#include "Logger.h"

class TerminalLogger: public Logger {

public:

    void log(std::string &s) override{

        std::cout << s;

    }


};


#endif //BATTLEFORHONOUR_TERMINALLOGGER_H

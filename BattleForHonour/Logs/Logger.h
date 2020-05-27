#ifndef BATTLEFORHONOUR_LOGGER_H
#define BATTLEFORHONOUR_LOGGER_H


#include <string>
#include "Logend.h"

class Logger {

public:

    virtual void log(std::string &s)=0;
    virtual void log(game::Logend &l){}
    virtual ~Logger(){}

};


#endif //BATTLEFORHONOUR_LOGGER_H

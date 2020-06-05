#ifndef BATTLEFORHONOUR_LOGPROXY_H
#define BATTLEFORHONOUR_LOGPROXY_H

#include "NoLogger.h"
#include "NoFormat.h"
#include <string>
#include <iostream>

class LogProxy {

private:

    Logger *logger;
    LogFormat *logFormat;
    bool firstLine = true;

    void log(std::string s){
        if (firstLine) {
            std::string formatted = logFormat->getFormatted(s);
            logger->log(formatted);
            firstLine = false;
        } else{
            logger->log(s);
        }
    }

public:

    LogProxy():
    logger(new NoLogger()),
    logFormat(new NoFormat()){}

    ~LogProxy(){
        delete logger;
        delete logFormat;
    }

    friend LogProxy& operator<< (LogProxy &logger, const std::string &s){
        logger.log(s);
        return logger;
    }

    friend LogProxy& operator<< (LogProxy &logger, const int i){
        logger.log(std::to_string(i));
        return logger;
    }

    friend LogProxy& operator<< (LogProxy &logger, const game::Logend &l){
        logger.log("\n");
        logger.firstLine = true;
        return logger;
    }

    void setLogger(Logger *tmp){

        delete logger;
        logger = tmp;
    }

    void setLogFormat(LogFormat *tmp){

        delete logFormat;
        logFormat = tmp;

    }

};


#endif //BATTLEFORHONOUR_LOGPROXY_H

#ifndef BATTLEFORHONOUR_FILELOGGER_H
#define BATTLEFORHONOUR_FILELOGGER_H


#include <fstream>
#include "Logger.h"

class FileLogger: public Logger {

private:

    std::ofstream fileStream;

public:

    explicit FileLogger(std::string filePath): fileStream(filePath){}

    ~FileLogger() override {
        fileStream.close();
    }

    void log(std::string &s) override{

        fileStream << s;

    }

    void log(game::Logend &l) override{

        fileStream.flush();

    }

};


#endif //BATTLEFORHONOUR_FILELOGGER_H
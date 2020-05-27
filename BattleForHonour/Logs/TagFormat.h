#ifndef BATTLEFORHONOUR_TAGFORMAT_H
#define BATTLEFORHONOUR_TAGFORMAT_H


#include <utility>

#include "LogFormat.h"

class TagFormat: public LogFormat {

private:

    std::string tag;

public:

    explicit TagFormat(std::string tag): tag(std::move(tag)){}

    std::string getFormatted(std::string &notFormatted) override{

        return "["+tag+"] "+notFormatted;

    }

};


#endif //BATTLEFORHONOUR_TAGFORMAT_H

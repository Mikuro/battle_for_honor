#ifndef BATTLEFORHONOUR_SPECS_H
#define BATTLEFORHONOUR_SPECS_H


#include <string>
#include "Logs/log.h"

namespace Specs {
    unsigned long int StrToInt(std::string s) {

        try {
            return std::stoull(s);
        } catch (std::invalid_argument) {
            game::log << "Wrong format. No numbers." << game::logend;
            return 0;
        } catch (std::out_of_range) {
            game::log << "Wrong format. Range overflow." << game::logend;
            return 0;
        } catch (...) {
            game::log << "Wrong format. Anything goes wrong..." << game::logend;
            return 0;
        }

    }
}


#endif //BATTLEFORHONOUR_SPECS_H

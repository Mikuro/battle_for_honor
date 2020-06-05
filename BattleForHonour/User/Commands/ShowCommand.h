#ifndef BATTLEFORHONOUR_SHOWCOMMAND_H
#define BATTLEFORHONOUR_SHOWCOMMAND_H


#include "Command.h"

#include <memory>
#include "ShowBaseCommand.h"
#include "ShowUnitCommand.h"

class ShowCommandHandler: public CommandHandler{

public:

    bool canHandle(std::vector<std::string> &terminal) override{

        return terminal.size() > 1 && terminal[0] == "show";

    }

    std::unique_ptr<Command> handle(std::vector<std::string> &terminal) override{

        if (canHandle(terminal)){

            terminal.erase(terminal.begin());

            auto handlerUnit = new ShowUnitCommandHandler;
            auto handlerBase = new ShowBaseCommandHandler;

            handlerUnit->setNext(handlerBase);

            return handlerUnit->handle(terminal);
        }

        if (next)
            return next->handle(terminal);

        return std::make_unique<Command>();
    }

};


#endif //BATTLEFORHONOUR_SHOWCOMMAND_H

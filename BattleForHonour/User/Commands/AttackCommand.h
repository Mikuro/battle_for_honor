#ifndef BATTLEFORHONOUR_ATTACKCOMMAND_H
#define BATTLEFORHONOUR_ATTACKCOMMAND_H


#include "Command.h"
#include "AttackUnitCommand.h"

class AttackCommandHandler: public CommandHandler {

public:

    bool canHandle(std::vector<std::string> &terminal) override{

        return terminal.size() > 1 && terminal[0] == "attack";

    }

    std::unique_ptr<Command> handle(std::vector<std::string> &terminal) override{

        if (canHandle(terminal)) {

            terminal.erase(terminal.begin());

            auto handle1 = new AttackUnitCommandHandler();
            return handle1->handle(terminal);

        }

        if (next)
            return next->handle(terminal);
        return std::make_unique<Command>();

    }

};


#endif //BATTLEFORHONOUR_ATTACKCOMMAND_H

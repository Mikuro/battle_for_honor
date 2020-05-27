#ifndef BATTLEFORHONOUR_SHOWBASECOMMAND_H
#define BATTLEFORHONOUR_SHOWBASECOMMAND_H


#include "Command.h"
#include "../../Point.h"
#include "../../Specs.h"

class ShowBaseCommand: public Command {

private:

    Point basePosition;

public:

    explicit ShowBaseCommand(Point p): basePosition(p){}
    void execute(GameInfo &gameInfo) override{

        auto object = gameInfo.getField().getCell(basePosition)->getObject();
        if (object && object->getType() == ObjectType::BASE){

            auto base = dynamic_cast<Base*>(object);
            std::cout << "Base info: " << std::endl
                      << "\tHP: " << base->getHealth() << std::endl
                      << "\tArmor: " << base->getArmor() << std::endl
                      << "\tMax Objects Count: " << base->getMaxObjectsCount() << std::endl;
            game::log << "Show base command" << game::logend;

        } else{
            game::log << "Empty cell" << game::logend;
        }

    }

};

class ShowBaseCommandHandler: public CommandHandler {

public:

    bool canHandle(std::vector<std::string> &cmd) override{

        return cmd.size() == 3 && cmd[0] == "base";

    }

    CommandPtr handle(std::vector<std::string> &cmd) override{

        if (canHandle(cmd)){
            int x = Specs::StrToInt(cmd[1]);
            int y = Specs::StrToInt(cmd[2]);
            Point basePosition(x, y);
            return CommandPtr(new ShowBaseCommand(basePosition));
        }

        if (next) return next->handle(cmd);
        return std::make_unique<Command>();

    }

};


#endif //BATTLEFORHONOUR_SHOWBASECOMMAND_H
#ifndef BATTLEFORHONOUR_SHOWBASECOMMAND_H
#define BATTLEFORHONOUR_SHOWBASECOMMAND_H


#include "Command.h"
#include "../../Point.h"

class ShowBaseCommand: public Command {

private:

    Point basePosition;

public:

    explicit ShowBaseCommand(Point p): basePosition(p){}
    void execute(GameState &gameInfo) override{

        auto object = gameInfo.getField().getCell(basePosition)->getObject();
        if (object && object->getType() == ObjectType::BASE){

            auto base = dynamic_cast<Base*>(object);
            std::cout << "Base: " << std::endl
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

    bool canHandle(std::vector<std::string> &terminal) override{

        return terminal.size() == 3 && terminal[0] == "base";

    }

    std::unique_ptr<Command> handle(std::vector<std::string> &terminal) override{

        if (canHandle(terminal)){
            int x = convertStr(terminal[1]);
            int y = convertStr(terminal[2]);
            Point basePosition(x, y);
            return std::unique_ptr<Command>(new ShowBaseCommand(basePosition));
        }

        if (next)
            return next->handle(terminal);

        return std::make_unique<Command>();
    }

};


#endif //BATTLEFORHONOUR_SHOWBASECOMMAND_H

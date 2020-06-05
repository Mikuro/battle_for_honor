#ifndef BATTLEFORHONOUR_ATTACKUNITCOMMAND_H
#define BATTLEFORHONOUR_ATTACKUNITCOMMAND_H


#include "Command.h"

class AttackUnitCommand: public Command{

private:

    Point from;
    Point to;

public:

    AttackUnitCommand(Point from, Point to): from(from), to(to){}
    void execute(GameState &gameState) override{

        auto object1 = gameState.getField().getCell(from)->getObject();
        auto object2 = gameState.getField().getCell(to)->getObject();
        if (object1 && object1->getType() == ObjectType::UNIT && object1 && object1->getType() == ObjectType::UNIT) {
            auto unit1 = dynamic_cast<Unit *>(object1);
            auto unit2 = dynamic_cast<Unit *>(object2);
            unit1->attack(*unit2);
            game::log << "Gotten command attack" << game::logend;
        } else
            game::log << "Impossible attack" << game::logend;

    }

    [[nodiscard]] CommandSnapshot * getSnapshot() const override{
        std::stringstream stream;
        stream << "attack unit " << from.x << " " << from.y << " " << to.x << " " << to.y << std::endl;
        return new CommandSnapshot(stream.str());
    }

};

class AttackUnitCommandHandler: public CommandHandler {

public:

    bool canHandle(std::vector<std::string> &terminal) override{
        return terminal.size() == 5 && terminal[0] == "unit";
    }

    std::unique_ptr<Command> handle(std::vector<std::string> &terminal) override{

        if (canHandle(terminal)){
            int x1 = convertStr(terminal[1]);
            int y1 = convertStr(terminal[2]);
            int x2 = convertStr(terminal[3]);
            int y2 = convertStr(terminal[4]);
            Point from((int)x1, (int)y1);
            Point to((int)x2, (int)y2);
            return std::unique_ptr<Command>(new AttackUnitCommand(from, to));
        }

        if (next)
            return next->handle(terminal);
        return std::make_unique<Command>();

    }

};

#endif //BATTLEFORHONOUR_ATTACKUNITCOMMAND_H

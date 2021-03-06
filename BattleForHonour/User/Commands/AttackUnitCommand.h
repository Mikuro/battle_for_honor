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

        auto objFrom = gameState.getField().getCell(from)->getObject();
        auto objTo = gameState.getField().getCell(to)->getObject();
        if (objFrom && objFrom->getType() == ObjectType::UNIT && objFrom && objFrom->getType() == ObjectType::UNIT) {
            auto unitFrom = dynamic_cast<Unit *>(objFrom);
            auto unitTo = dynamic_cast<Unit *>(objTo);
            unitFrom->attack(*unitTo);
            Log::log << "Gotten command attack" << Log::logend;
        } else
            Log::log << "No wat to attack" << Log::logend;

    }

    [[nodiscard]] CommandSnapshot * getSnapshot() const override{
        std::stringstream stream;
        stream << "attack unit " << from.x << " " << from.y << " " << to.x << " " << to.y << std::endl;
        return new CommandSnapshot(stream.str());
    }

};

class AttackUnitCommandHandler: public CommandHandler {

public:

    bool isHandle(std::vector<std::string> &terminal) override{
        return terminal.size() == 5 && terminal[0] == "unit";
    }

    std::unique_ptr<Command> handle(std::vector<std::string> &terminal) override{

        if (isHandle(terminal)){
            int x1 = convertStr(terminal[1]);
            int y1 = convertStr(terminal[2]);
            int x2 = convertStr(terminal[3]);
            int y2 = convertStr(terminal[4]);
            Point from(x1,y1);
            Point to(x2,y2);
            return std::unique_ptr<Command>(new AttackUnitCommand(from, to));
        }

        if (next)
            return next->handle(terminal);
        return std::make_unique<Command>();

    }

};

#endif //BATTLEFORHONOUR_ATTACKUNITCOMMAND_H

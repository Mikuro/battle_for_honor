#ifndef BATTLEFORHONOUR_SHOWUNITCOMMAND_H
#define BATTLEFORHONOUR_SHOWUNITCOMMAND_H


#include "Command.h"

class ShowUnitCommand: public Command {

private:

    Point unitPosition;

public:

    explicit ShowUnitCommand(Point p): unitPosition(p){}
    void execute(GameState &gameInfo) override{

        auto object = gameInfo.getField().getCell(unitPosition)->getObject();
        if (object && object->getType() == ObjectType::UNIT){

            auto unit = dynamic_cast<Unit*>(object);
            std::cout << "Unit: " << std::endl
                      << "\nHP: " << unit->getHealth() << std::endl
                      << "\nArmor: " << unit->getArmor() << std::endl
                      << "\nWeapon: " << unit->getWeapon() << std::endl
                      << "\nUnit class: ";
            switch(unit->getUnitType()){
                case UnitType::ARCHER:
                    std::cout << "Archer" << std::endl;
                    break;
                case UnitType::DRUID:
                    std::cout << "Druid" << std::endl;
                    break;
                case UnitType::INFANTRY:
                    std::cout << "Infantry" << std::endl;
                    break;
            }

            game::log << "Command show unit" << game::logend;

        } else{
            game::log << "Empty cell" << game::logend;
        }

    }

};

class ShowUnitCommandHandler: public CommandHandler{

public:

    bool canHandle(std::vector<std::string> &terminal) override{

        return terminal.size() == 3 && terminal[0] == "unit";

    }

    virtual std::unique_ptr<Command> handle(std::vector<std::string> &terminal){

        if (canHandle(terminal)){
            int x = convertStr(terminal[1]);
            int y = convertStr(terminal[2]);
            Point unitPosition(x, y);
            return std::unique_ptr<Command>(new ShowUnitCommand(unitPosition));
        }

        if (next)
            return next->handle(terminal);

        return std::make_unique<Command>();
    }

};



#endif //BATTLEFORHONOUR_SHOWUNITCOMMAND_H

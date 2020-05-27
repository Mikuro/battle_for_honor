#ifndef BATTLEFORHONOUR_GAMEFACADE_H
#define BATTLEFORHONOUR_GAMEFACADE_H


#include <sstream>
#include "GameInfo.h"
#include "User/CommandInterpreter.h"


template<typename Rule, int playersCount>
class GameFacade: public GameInfo {

private:

    CommandInterpreter interpreter;
    GameFacade(int fieldWidth, int fieldHeight): GameInfo(playersCount, fieldWidth, fieldWidth, new Rule){}
    Rule rule;

public:

    static GameFacade& instance(){
        Rule rule;
        static GameFacade singleInstance(rule.fieldWidth, rule.fieldHeight);
        return singleInstance;
    }

    void nextTurn(){

        std::string commandString;
        std::getline(std::cin, commandString);

        CommandPtr command = interpreter.handle(commandString);
        try {
            command->execute(*this);
        } catch(DoubleBasePlacingExc &exception) {
            std::cout << "Player " << exception.playerIndex << " trying to place base second time." << std::endl;
        } catch (DoublePlacingExc &exception){
            std::cout << "This cell is busy by other object." << std::endl;
        } catch (OutOfRangeExc &exception){
            std::cout << "Out of range. Cell " << exception.x << " " << exception.y << " is not exist." << std::endl;
        } catch (ImpossibleMoveExc &exception){
            std::cout << "Can't move to this cell. They busy by other object." << std::endl;
        } catch (InvalidFileLoadExc &exception){
            std::cout << "Wrong file." << std::endl;
        } catch (...){
            std::cout << "Undefined error." << std::endl;
        }
        history.push_back(command->getMemento());

        nextUser();

    }

    friend std::ostream &operator<<(std::ostream &stream, const GameFacade &game){

        stream << "Now player: " << game.nowPlayerIndex << std::endl;
        stream << game.gameField << std::endl;
        return stream;

    }

    bool isOver(){

        return rule.isOver(*this);

    }

};


#endif //BATTLEFORHONOUR_GAMEFACADE_H

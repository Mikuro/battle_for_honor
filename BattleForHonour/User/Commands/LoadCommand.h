#ifndef BATTLEFORHONOUR_LOADCOMMAND_H
#define BATTLEFORHONOUR_LOADCOMMAND_H


#include "../ConnectCI.h"
#include "../../Specs.h"


class LoadCommand: public Command {

private:

    std::ifstream fs;
    ConnectCI interpreter;

public:

    explicit LoadCommand(std::string &filename): fs(filename){}
    void execute(GameInfo &gameInfo) override{

        gameInfo.newGame();

        std::string cmd;

        std::hash<std::string> hashFunc;
        unsigned long int calculatedHash = 0;
        unsigned long int fileHash = 0;

        std::string fileHashStr;
        std::getline(fs, fileHashStr);

        fileHash = Specs::StrToInt(fileHashStr);

        while (std::getline(fs, cmd)){

            CommandPtr command = interpreter.handle(cmd);
            try {
                command->execute(gameInfo);
            } catch(DoubleBasePlacingExc &exception) {
                game::log << "[FileLoader]" << "Player " << exception.playerIndex << " trying to place base second time." << game::logend;
            } catch (DoublePlacingExc &exception){
                game::log << "[FileLoader]" << "This cell is busy by other object." << game::logend;
            } catch (OutOfRangeExc &exception){
                game::log << "[FileLoader]" << "Out of range. Cell " << exception.x << " " << exception.y << " is not exist." << game::logend;
            } catch (ImpossibleMoveExc &exception){
                game::log << "[FileLoader]" << "Can't move to this cell. They busy by other object." << game::logend;
            } catch (...){
                game::log << "[FileLoader]" << "Undefined error." << game::logend;
            }
            auto memento = command->getMemento();
            gameInfo.addToHistory(memento);
            calculatedHash += memento->getHash(hashFunc);
            gameInfo.nextUser();

        }

        game::log << "String hash from file: " << fileHashStr << game::logend;
        game::log << "Int hash from file: " << fileHash << game::logend;
        game::log << "Calculated hash: " << calculatedHash << game::logend;
        game::log << "Read commands count: " << gameInfo.getHistory().size() << game::logend;

        if (fileHash != calculatedHash){
            game::log << "Wrong file format. The correctness of the loaded field is not guaranteed." << game::logend;
            throw InvalidFileLoadExc();
        }

    }

    ~LoadCommand() override{

        fs.close();

    }

};

class LoadCommandHandler: public CommandHandler{

public:

    bool canHandle(std::vector<std::string> &cmd) override{

        return cmd.size() == 2 && cmd[0] == "load";

    }

    CommandPtr handle(std::vector<std::string> &cmd) override{

        if (canHandle(cmd)){
            return CommandPtr(new LoadCommand(cmd[1]));
        }

        if (next) return next->handle(cmd);

        return std::make_unique<Command>();

    }

};



#endif //BATTLEFORHONOUR_LOADCOMMAND_H

#ifndef BATTLEFORHONOUR_LOADCOMMAND_H
#define BATTLEFORHONOUR_LOADCOMMAND_H


#include "../ConnectCI.h"

class LoadCommand: public Command {

private:

    std::ifstream fs;
    ConnectCI interpreter;

public:

    explicit LoadCommand(std::string &filename): fs(filename){}
    void execute(GameState &gameState) override{

        gameState.newGame();

        std::string terminal;

        std::hash<std::string> toHash;
        unsigned long int calculatedHash = 0;
        unsigned long int fileHash = 0;

        std::string fileHashStr;
        std::getline(fs, fileHashStr);

        fileHash = convertStr(fileHashStr);

        while (std::getline(fs, terminal)){

            std::unique_ptr<Command> command = interpreter.handle(terminal);
            try {
                command->execute(gameState);
            } catch(DoubleBasePlacingExc &exception) {
                game::log << "[#FileLoader]" << "User " << exception.playerIndex << " trying to place second base." << game::logend;
            } catch (DoublePlacingExc &exception){
                game::log << "[#FileLoader]" << "This cell is busy by other object." << game::logend;
            } catch (OutOfRangeExc &exception){
                game::log << "[#FileLoader]" << "Out of range. Cell " << exception.x << " " << exception.y << " is not exist." << game::logend;
            } catch (ImpossibleMoveExc &exception){
                game::log << "[#FileLoader]" << "Can't move to this cell. They busy by other object." << game::logend;
            } catch (...){
                game::log << "[#FileLoader]" << "Unknown error." << game::logend;
            }
            auto snapshot = command->getSnapshot();
            gameState.addAction(snapshot);
            calculatedHash += snapshot->getHash(toHash);
            gameState.nextUser();

        }

        game::log << "String hash: " << fileHashStr << game::logend;
        game::log << "Integer hash: " << fileHash << game::logend;
        game::log << "Calculated hash: " << calculatedHash << game::logend;
        game::log << "Commands were read: " << gameState.getActions().size() << game::logend;

        if (fileHash != calculatedHash){
            game::log << "Wrong file format. File may be incorrect." << game::logend;
            throw InvalidFileLoadExc();
        }

    }

    ~LoadCommand() override{
        fs.close();
    }

};

class LoadCommandHandler: public CommandHandler{

public:

    bool canHandle(std::vector<std::string> &terminal) override{
        return terminal.size() == 2 && terminal[0] == "load";
    }

    std::unique_ptr<Command> handle(std::vector<std::string> &terminal) override{

        if (canHandle(terminal)){
            return std::unique_ptr<Command>(new LoadCommand(terminal[1]));
        }

        if (next)
            return next->handle(terminal);

        return std::make_unique<Command>();

    }

};



#endif //BATTLEFORHONOUR_LOADCOMMAND_H

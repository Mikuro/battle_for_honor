#ifndef BATTLEFORHONOUR_SAVECOMMAND_H
#define BATTLEFORHONOUR_SAVECOMMAND_H


#include "Command.h"

class SaveCommand: public Command {

private:

    std::ofstream fs;

public:

    explicit SaveCommand(std::string &filename){
        fs = std::ofstream(filename);
        game::log << "File opened" << game::logend;
        game::log << "File is opened: " << fs.is_open() << game::logend;

    }
    void execute(GameState &gameState) override{

        std::hash<std::string> toHash;
        unsigned long int fileHash = 0;

        game::log << "Saving..." << game::logend;

        auto actions = gameState.getActions();

        for (auto elem: actions){
            fileHash += elem->getHash(toHash);
        }

        fs << fileHash << std::endl;

        for (auto elem: actions){
            elem->saveToFile(fs);
        }

        game::log << "Saved commands count: " << gameState.getActions().size() << game::logend;

    }

    ~SaveCommand() override{
        game::log << "File closed" << game::logend;
        fs.close();
        game::log << "File is opened: " << fs.is_open() << game::logend;
    }

};

class SaveCommandHandler: public CommandHandler{

    bool canHandle(std::vector<std::string> &terminal) override{
        return terminal.size() == 2 && terminal[0] == "save";

    }

    std::unique_ptr<Command> handle(std::vector<std::string> &terminal) override{

        if (canHandle(terminal)){
            return std::unique_ptr<Command>(new SaveCommand(terminal[1]));
        }

        if (next)
            return next->handle(terminal);

        return std::make_unique<Command>();
    }

};


#endif //BATTLEFORHONOUR_SAVECOMMAND_H

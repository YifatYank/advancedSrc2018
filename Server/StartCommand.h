/*
 * StartCommand.h
 *
 *  Created on: Dec 30, 2017
 *      Author: yifat
 */

#ifndef SERVER_STARTCOMMAND_H_
#define SERVER_STARTCOMMAND_H_

#include "Command.h"
#include "GameMaster.h"

class StartCommand: public Command {
private:
	string name_;
	GameMaster & games_;

public:
	StartCommand(string command_name, GameMaster & games_master);
	virtual void execute(vector <string> args);
	virtual ~StartCommand();
};

#endif /* SERVER_STARTCOMMAND_H_ */

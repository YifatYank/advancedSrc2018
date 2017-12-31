/*
 * joinCommand.h
 *
 *  Created on: Dec 31, 2017
 *      Author: yifat
 */

#ifndef SERVER_JOINCOMMAND_H_
#define SERVER_JOINCOMMAND_H_

#include "Command.h"
#include "GameMaster.h"

class joinCommand: public Command {
private:
	string name_;
	GameMaster & games_;
public:
	joinCommand(GameMaster & games_master);
	virtual void execute(vector <string> args);
	virtual ~joinCommand();
};

#endif /* SERVER_JOINCOMMAND_H_ */

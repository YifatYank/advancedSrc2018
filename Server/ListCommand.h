/*
 * ListCommand.h
 *
 *  Created on: Dec 31, 2017
 *      Author: shomps
 */

#ifndef SRC_SERVER_LISTCOMMAND_H_
#define SRC_SERVER_LISTCOMMAND_H_

#include "Command.h"
#include "GameMaster.h"

class ListCommand: public Command {
private:
	string name_;
	GameMaster & games_;

public:
	ListCommand(string command_name, GameMaster & games_master);
	virtual void execute(vector <string> args);
	virtual ~ListCommand();
};

#endif /* SRC_SERVER_LISTCOMMAND_H_ */

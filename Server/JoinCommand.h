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
#include "SocketManager.h"

class JoinCommand: public Command {
private:
	string name_;
	GameMaster & games_;
	SocketManager * sockets_;

public:
	JoinCommand(GameMaster & games_master, SocketManager * sockets);
	virtual string getName();
	virtual bool execute(vector <string> args);
	virtual ~JoinCommand();
};

#endif /* SERVER_JOINCOMMAND_H_ */

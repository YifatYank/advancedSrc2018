/*
 * ClientStartCommand.h
 *
 *  Created on: Dec 31, 2017
 *      Author: yifat
 */

#ifndef CLIENT_CLIENTSTARTCOMMAND_H_
#define CLIENT_CLIENTSTARTCOMMAND_H_

#include "ClientCommand.h"
#include "Client.h"
#include "Player.h"

class ClientStartCommand: public ClientCommand {
private:
	string name_;
	Client & client_;
	Player ** player;

public:
	ClientStartCommand(Client &client, Player ** player);
	virtual string getName();
	bool execute(string command);
	virtual ~ClientStartCommand();
};

#endif /* CLIENT_CLIENTSTARTCOMMAND_H_ */

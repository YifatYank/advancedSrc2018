/*
 * ClientJoinCommand.h
 *
 *  Created on: Dec 31, 2017
 *      Author: shomps
 */

#ifndef SRC_CLIENT_CLIENTJOINCOMMAND_H_
#define SRC_CLIENT_CLIENTJOINCOMMAND_H_

#include "Client.h"
#include "ClientCommand.h"
#include "Player.h"

using namespace std;

class ClientJoinCommand: public ClientCommand {
private:
	string name_;
	Client & client_;
	Player ** player_;
public:
	ClientJoinCommand(Client &client, Player **player);
	virtual string getName();
	virtual bool execute(string command);
	virtual ~ClientJoinCommand();
};


#endif /* SRC_CLIENT_CLIENTJOINCOMMAND_H_ */

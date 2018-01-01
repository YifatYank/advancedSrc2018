/*
 * ClientListCommand.h
 *
 *  Created on: Dec 31, 2017
 *      Author: shomps
 */

#ifndef SRC_CLIENT_CLIENTLISTCOMMAND_H_
#define SRC_CLIENT_CLIENTLISTCOMMAND_H_

#include "ClientCommand.h"
#include "Client.h"
#include <vector>
#include <string>
using namespace std;


class ClientListCommand: public ClientCommand {
private:
	string name_;
	Client & client_;
public:
	ClientListCommand(Client &client);
	virtual string getName();
	virtual bool execute(string command);
	virtual ~ClientListCommand();
};

#endif /* SRC_CLIENT_CLIENTLISTCOMMAND_H_ */

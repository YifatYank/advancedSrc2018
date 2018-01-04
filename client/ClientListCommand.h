/**
 * Names       : Yifat Yankocivh
 * 				 Shoham Bar-Gad
 * IDs	       : 204709224
 * 				 315706614
 * User Names  : yankovy
 * 				 bagnosh
 *
 * Class Name  : ClientListCommant.h
 * Description : Defines the methods of the ClientListCommand
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

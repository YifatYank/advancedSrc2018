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
	/** Function name	: constructor
	 *  Parameters		: client reference, player double pointer
	 *  Return value	: new ClientJoinCommand
	 *  General flow	: constructs a ClientJoinCommand
	 */
	ClientJoinCommand(Client &client, Player **player);

	/** Function name	: getName
	 *  Parameters		: none
	 *  Return value	: string
	 *  General flow	: returns command's name
	 */
	virtual string getName();

	/** Function name	: execute
	 *  Parameters		: string
	 *  Return value	: boolean
	 *  General flow	: executes command
	 */
	virtual bool execute(string command);

	/** Function name	: destructor
	 *  Parameters		: none
	 *  Return value	: none
	 *  General flow	: deletes the ClientJoinCommand
	 */
	virtual ~ClientJoinCommand();
};


#endif /* SRC_CLIENT_CLIENTJOINCOMMAND_H_ */

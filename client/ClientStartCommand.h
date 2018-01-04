/**
 * Names       : Yifat Yankocivh
 * 				 Shoham Bar-Gad
 * IDs	       : 204709224
 * 				 315706614
 * User Names  : yankovy
 * 				 bagnosh
 *
 * Class Name  : ClientStartCommant.h
 * Description : Defines the methods of the ClientStartCommand
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
	/** Function name	: constructor
	 *  Parameters		: client reference, dpuble pointer to player
	 *  Return value	: new ClientStartCommand
	 *  General flow	: constructs a ClientStartCommand
	 */
	ClientStartCommand(Client &client, Player ** player);

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
	bool execute(string command);

	/** Function name	: destructor
	 *  Parameters		: none
	 *  Return value	: none
	 *  General flow	: deletes ClientStartCommand
	 */
	virtual ~ClientStartCommand();
};

#endif /* CLIENT_CLIENTSTARTCOMMAND_H_ */

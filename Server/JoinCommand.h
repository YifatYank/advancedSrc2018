/**
 * Names       : Yifat Yankocivh
 * 				 Shoham Bar-Gad
 * IDs	       : 204709224
 * 				 315706614
 * User Names  : yankovy
 * 				 bagnosh
 *
 * Class Name  : JoinCommand.h
 * Description : Defines the methods of JoinCommand
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

	/** Function name	: constructor
	 * Parameters		: pointers to GameMaster, SocketManager
	 * Return value	    : new JoinCommand
	 * General flow	    : constructs a JoinCommand
	 */
	JoinCommand(GameMaster & games_master, SocketManager * sockets);

	/** Function name	: getName
	 * Parameters		: none
	 * Return value	    : string
	 * General flow	    : returns command's name
	 */
	virtual string getName();

	/** Function name	: execute
	 * Parameters		: vector<string>
	 * Return value	    : boolean
	 * General flow	    : executes command
	 */
	virtual bool execute(vector <string> args);

	/** Function name	: destructor
	 * Parameters		: none
	 * Return value	    : none
	 * General flow	    : deletes the JoinCommand
	 */
	virtual ~JoinCommand();
};

#endif /* SERVER_JOINCOMMAND_H_ */

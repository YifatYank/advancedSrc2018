/**
 * Names       : Yifat Yankocivh
 * 				 Shoham Bar-Gad
 * IDs	       : 204709224
 * 				 315706614
 * User Names  : yankovy
 * 				 bagnosh
 *
 * Class Name  : CommandsManager.h
 * Description : Defines the methods of CommandsManager
 */

#ifndef COMMANDSMANAGER_H_
#define COMMANDSMANAGER_H_

#include <string>
#include <map>
#include "Command.h"
#include "GameMaster.h"
#include "SocketManager.h"

using namespace std;

class CommandsManager {
private:
	map<string, Command *> command_map_;
	GameMaster & games_;
public:
	/** Function name	: constructor
	 * Parameters		: pointers to GameMaster, SocketManager
	 * Return value	    : constructed CommandsManager
	 * General flow	    : constructs a CommandsManager
	 */
	CommandsManager(GameMaster & gamesList, SocketManager * sockets);

	/** Function name	: ExecuteCommand
	 * Parameters		: string, vector<string>
	 * Return value	    : boolean
	 * General flow	    : executes command
	 */
	bool ExecuteCommand(string command, vector<string> args);

	/** Function name	: destructor
	 * Parameters		: none
	 * Return value	    : none
	 * General flow	    : destroys the CommandsManager
	 */
	virtual ~CommandsManager();
};

#endif /* COMMANDSMANAGER_H_ */

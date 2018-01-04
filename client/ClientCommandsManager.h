/*
 * ClientCommandsManager.h
 *
 *  Created on: Jan 1, 2018
 *      Author: shomps
 */

#ifndef SRC_CLIENT_CLIENTCOMMANDSMANAGER_H_
#define SRC_CLIENT_CLIENTCOMMANDSMANAGER_H_

#include <string>
#include <map>
#include "ClientCommand.h"
#include "Client.h"
#include "Player.h"
using namespace std;

class ClientCommandsManager {
private:
	map<string, ClientCommand *> command_map_;
public:
	/** Function name	: constructor
	 *  Parameters		: client reference, player double pointer
	 *  Return value	: new ClientCommandsManager
	 *  General flow	: constructs new ClientCommandsManager
	 */
	ClientCommandsManager(Client &client, Player ** player);

	/** Function name	: executeCommand
	 *  Parameters		: string
	 *  Return value	: boolean
	 *  General flow	: executes given commands
	 */
	bool ExecuteCommand(string command);

	/** Function name	: splitedString
	 *  Parameters		: string, token character
	 *  Return value	: vector<string>
	 *  General flow	: returns separated string according to token
	 */
	vector<string> splitedString(string string_to_split, char delim);

	/** Function name	: destructor
	 *  Parameters		: none
	 *  Return value	: none
	 *  General flow	: deletes the ClientCommandsManager
	 */
	virtual ~ClientCommandsManager();
};

#endif /* SRC_CLIENT_CLIENTCOMMANDSMANAGER_H_ */

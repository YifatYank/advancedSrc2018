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
using namespace std;

class ClientCommandsManager {
private:
	map<string, ClientCommand *> command_map_;
public:
	ClientCommandsManager();
	bool ExecuteCommand(string command);
	vector<string> splitedString(string string_to_split, char delim);
	virtual ~ClientCommandsManager();
};

#endif /* SRC_CLIENT_CLIENTCOMMANDSMANAGER_H_ */

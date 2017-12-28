/*
 * CommandSet.h
 *
 *  Created on: Dec 27, 2017
 *      Author: yifat
 */

#ifndef SERVER_COMMANDSET_H_
#define SERVER_COMMANDSET_H_

#include <map>
#include <string>
#include "Command.h"
using namespace std;

class CommandSet {
private:
	map<string, Command *> commands;
public:
	CommandSet();
	void addCommad(Command * command);
	void removeCommad(Command * command);
	virtual ~CommandSet();
};

#endif /* SERVER_COMMANDSET_H_ */

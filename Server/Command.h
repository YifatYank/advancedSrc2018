/*
 * Command.h
 *
 *  Created on: Dec 27, 2017
 *      Author: yifat
 */

#ifndef SERVER_COMMAND_H_
#define SERVER_COMMAND_H_

#include <string>
using namespace std;

class Command{
private:
	string name;

public:
	virtual string getName() = 0;
	virtual void * doCommand(void * params) = 0;
	virtual ~Command();
};

#endif /* SERVER_COMMAND_H_ */

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
	string getName() = 0;
	void * doCommand(void * params) = 0;
};

#endif /* SERVER_COMMAND_H_ */

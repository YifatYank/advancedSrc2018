/*
 * ClientCommand.h
 *
 *  Created on: Dec 31, 2017
 *      Author: yifat
 */

#ifndef CLIENT_CLIENTCOMMAND_H_
#define CLIENT_CLIENTCOMMAND_H_

#include <vector>
#include <string>
using namespace std;


class ClientCommand {
public:
	ClientCommand();
	virtual string getName() = 0;
	virtual bool execute();
	virtual ~ClientCommand();
};

#endif /* CLIENT_CLIENTCOMMAND_H_ */

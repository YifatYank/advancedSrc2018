/*
 * ClientListCommand.h
 *
 *  Created on: Dec 31, 2017
 *      Author: shomps
 */

#ifndef SRC_CLIENT_CLIENTLISTCOMMAND_H_
#define SRC_CLIENT_CLIENTLISTCOMMAND_H_

#include "ClientCommand.h"
#include <vector>
#include <string>
using namespace std;


class ClientListCommand: public ClientCommand {
public:
	ClientListCommand();
	virtual string getName() = 0;
	virtual bool execute();
	virtual ~ClientListCommand();
};

#endif /* SRC_CLIENT_CLIENTLISTCOMMAND_H_ */

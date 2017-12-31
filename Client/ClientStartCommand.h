/*
 * ClientStartCommand.h
 *
 *  Created on: Dec 31, 2017
 *      Author: yifat
 */

#ifndef CLIENT_CLIENTSTARTCOMMAND_H_
#define CLIENT_CLIENTSTARTCOMMAND_H_

#include "ClientCommand.h"

class ClientStartCommand: public ClientCommand {
public:
	ClientStartCommand();
	virtual ~ClientStartCommand();
};

#endif /* CLIENT_CLIENTSTARTCOMMAND_H_ */

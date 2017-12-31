/*
 * ClientHandler.h
 *
 *  Created on: Dec 28, 2017
 *      Author: yifat
 */

#ifndef SERVER_CLIENTHANDLER_H_
#define SERVER_CLIENTHANDLER_H_

#include "CommandsManager.h"
#include "ServerDefinitions.h"
#include "GameMaster.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <string.h>
#include <vector>


using namespace std;

class ClientHandler {
private:
	CommandsManager * commandsSet_;
	GameMaster * games_;

	vector<string> splitedString(string string_to_split, char delim);
	string intToString(int num);
	int stringToInt(string str);
public:
	ClientHandler();
	void handleClient(int client_socket);
	virtual ~ClientHandler();
};

#endif /* SERVER_CLIENTHANDLER_H_ */
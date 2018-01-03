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
#include "ThreadManager.h"
#include "SocketManager.h"
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
	SocketManager * sockets_;
	ThreadManager * threads_;
	CommandsManager * commandsSet_;
	GameMaster * games_;

	static void * handleCLientThread(void * params);
public:
	vector<string> splitedString(string string_to_split, char delim);
	string intToString(int num);
	int stringToInt(string str);
	ClientHandler(SocketManager * sockets ,ThreadManager * threads);
	void handleClient(int client_socket);
	CommandsManager * getCommandSet();
	GameMaster *getGameMaster();
	virtual ~ClientHandler();
};

typedef struct {
	int client_socket_;
	ClientHandler * handler_;
} ParamsToHandleCLientThread;

#endif /* SERVER_CLIENTHANDLER_H_ */

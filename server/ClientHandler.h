/**
 * Names       : Yifat Yankocivh
 * 				 Shoham Bar-Gad
 * IDs	       : 204709224
 * 				 315706614
 * User Names  : yankovy
 * 				 bagnosh
 *
 * Class Name  : ClientHandler.h
 * Description : Defines the methods of the ClientHandler class.
 */

#ifndef SERVER_CLIENTHANDLER_H_
#define SERVER_CLIENTHANDLER_H_

#include "ThreadPool.h"
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

#define MAX_THREADS 5

class ClientHandler {
private:
	SocketManager * sockets_;
	ThreadManager * threads_;
	CommandsManager * commandsSet_;
	GameMaster * games_;
	ThreadPool pool;

public:
	/** Function name	: handleClientThread
	 * Parameters		: void *
	 * Return value	    : void *
	 * General flow	    : a static method that's intended to work as a thread.
	 */
	static void * handleCLientThread(void * params);

	/** Function name	: splitedString
	 * Parameters		: string to split, token
	 * Return value	    : vector with split string
	 * General flow	    : splits a string by certified token.
	 */
	vector<string> splitedString(string string_to_split, char delim);

	/** Function name	: intToString
	 * Parameters		: integer
	 * Return value	    : string
	 * General flow	    : converts an integer into string representation
	 */
	string intToString(int num);

	/** Function name	: stringToInt
	 * Parameters		: string
	 * Return value	    : integer
	 * General flow	    : converts numeric string into integer
	 */
	int stringToInt(string str);

	/** Function name	: constructor
	 * Parameters		: pointers to SocketManager and ThreadManager
	 * Return value	    : created ClientHandler
	 * General flow	    : constructs a ClientHandler.
	 */
	ClientHandler(SocketManager * sockets ,ThreadManager * threads);

	/** Function name	: handleClient
	 * Parameters		: integer (socket)
	 * Return value	    : none
	 * General flow	    : handles the Client referenced by given socket
	 */
	void handleClient(int client_socket);

	/** Function name	: getCommandSet
	 * Parameters		: none
	 * Return value	    : pointer to CommandSet
	 * General flow	    : returns own CommandSet
	 */
	CommandsManager * getCommandSet();

	/** Function name	: getGameMaster
	 * Parameters		: none
	 * Return value	    : pointer to GameMaster
	 * General flow	    : returns own GameMaster
	 */
	GameMaster *getGameMaster();

	/** Function name	: destructor
	 * Parameters		: none
	 * Return value	    : none
	 * General flow	    : destroys the ClientHandler
	 */
	virtual ~ClientHandler();
};

typedef struct {
	int client_socket_;
	ClientHandler * handler_;
} ParamsToHandleCLientThread;

#endif /* SERVER_CLIENTHANDLER_H_ */

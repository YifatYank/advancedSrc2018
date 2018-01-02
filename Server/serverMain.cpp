/*
 * serverMain.cpp
 *
 *  Created on: Dec 10, 2017
 *      Author: yifat
 */
#include "Server.h"
#include "ClientHandler.h"
#define PORT 8002

int main(){
	ClientHandler handle = ClientHandler();
	Server server(PORT, handle);
	server.start();
	server.stop();
	return 0;
}

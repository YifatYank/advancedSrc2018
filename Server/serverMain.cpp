/*
 * serverMain.cpp
 *
 *  Created on: Dec 10, 2017
 *      Author: yifat
 */
#include "Server.h"
#include "ClientHandler.h"
#include "ThreadManager.h"
#define PORT 8002

int main(){
	ThreadManager * threads = new ThreadManager();
	SocketManager * sockets = new SocketManager();
	ClientHandler handle = ClientHandler(sockets, threads);
	Server server(PORT, handle, sockets, threads);
	server.start();
	server.stop();
	delete (threads);
	delete(sockets);
	return 0;
}

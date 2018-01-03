/**
 * Names       : Yifat Yankocivh
 * 				 Shoham Bar-Gad
 * IDs	       : 204709224
 * 				 315706614
 * User Names  : yankovy
 * 				 bagnosh
 *
 * Class Name  : ServerMain.cpp
 * Description : main class of Server area
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

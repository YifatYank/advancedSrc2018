/**
 * Names       : Yifat Yankocivh
 * 				 Shoham Bar-Gad
 * IDs	       : 204709224
 * 				 315706614
 * User Names  : yankovy
 * 				 bagnosh
 *
 * Class Name  : Server.h
 * Description : Defines the methods of the Server class.
 */

#ifndef SERVER_H_
#define SERVER_H_

#include "ClientHandler.h"
#include "SocketManager.h"
#include "ThreadManager.h"

class Server {
private:
	int port_;
	int server_socket_1_;
	ClientHandler & handler_;
	SocketManager * sockets_;
	ThreadManager * threads_;

	void handleClient(int client_socket1, int client_socket2);

	/** Function name	    : setConfigs
	 * Parameters		: none
	 * Return value	    : none
	 * General flow	    : sets configurations from file.
	 */
	void setConfigs();
public:
	/** Function name	    : constructor
	 * Parameters		: port number
	 * Return value	    : new Server
	 * General flow	    : creates a server.
	 */
	Server(int port, ClientHandler & client_handler, SocketManager * sockets, ThreadManager * threads);
	/** Function name	    : constructor (alternative)
	 * Parameters		: port 		- The port number the server will listen to.
	 * 					  handler 	- The handler will handle the clients once they are connected.
	 * Return value	    : new Server
	 * General flow	    : creates a server.
	 */
	Server(ClientHandler & client_handler, SocketManager * sockets, ThreadManager * threads);
	/** Function name	    : start
	 * Parameters		: handler 	- The handler will handle the clients once they are connected.
	 * Return value	    : none
	 * General flow	    : activates server.
	 */
	void start();
	/** Function name	    : stop
	 * Parameters		: none
	 * Return value	    : none
	 * General flow	    : deactivates server.
	 */
	void stop();
	virtual ~Server();
};

#endif /* SERVER_H_ */

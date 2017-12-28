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

class Server {
private:
	int port_;
	int server_socket_1_;
	//int server_socket_2_;

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
	Server(int port);
	/** Function name	    : constructor (alternative)
	 * Parameters		: none
	 * Return value	    : new Server
	 * General flow	    : creates a server.
	 */
	Server();
	/** Function name	    : start
	 * Parameters		: none
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
};

#endif /* SERVER_H_ */

/**
 * Names       : Yifat Yankocivh
 * 				 Shoham Bar-Gad
 * IDs	       : 204709224
 * 				 315706614
 * User Names  : yankovy
 * 				 bagnosh
 *
 * Class Name  : Client.h
 * Description : Defines the methods of the Client class.
 */

#ifndef CLIENT_H_
#define CLIENT_H_

class Client {
private:
	const char *server_ip_;
	int server_port_;
	int client_socket_;
	/** Function name	    : setConfigs
		 * Parameters		: none
		 * Return value	    : none
		 * General flow	    : sets configurations from file.
		 */
	void setConfigs();
public:
	/** Function name	    : constructor
		 *  Parameters		: none
		 *  Return value	: a Client object.
		 *  General flow	: creates a Client.
		 */
	Client();
	/** Function name	    : constructor (alternative)
		 * Parameters		: ip address, port number
		 * Return value	    : a Client object.
		 * General flow	    : creates a Client.
		 */
	Client(const char *server_ip, int server_port);
	/** Function name	    : connectToServer
		 * Parameters		: none
		 * Return value	    : none
		 * General flow	    : connects to server.
		 */
	void connectToServer();
	/** Function name	    : disconnectFromServer
		 * Parameters		: none
		 * Return value	    : none
		 * General flow	    : disconnects from server.
		 */
	void disconnectFromServer();
	/** Function name	    : sendInt
		 * Parameters		: integer
		 * Return value	    : none
		 * General flow	    : sends int to server.
		 */
	void sendInt(int num);
	/** Function name	    : recieveInt
		 * Parameters		: none
		 * Return value	    : integer
		 * General flow	    : recieves int from server.
		 */
	int reciveInt();
};


#endif /* CLIENT_H_ */

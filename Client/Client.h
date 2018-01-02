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

#include <string>
using namespace std;

#define BUFFER_SIZE 64

class Client {
private:
	char server_ip_[20];
	int server_port_;
	int client_socket_;
	static Client *instance;
	/** Function name	    : setConfigs
	 * Parameters		: none
	 * Return value	    : none
	 * General flow	    : sets configurations from file.
	 */
	void setConfigs();

	/** Function name	    : constructor (alternative)
	 * Parameters		: ip address, port number
	 * Return value	    : a Client object.
	 * General flow	    : creates a Client.
	 */
	Client(const char *server_ip, int server_port);

	/** Function name	: disconnectFromServer
	 * Parameters		: none
	 * Return value	    : none
	 * General flow	    : disconnects from server.
	 */
	void disconnectFromServer();

public:
	/** Function name	    : constructor
	 *  Parameters		: none
	 *  Return value	: a Client object.
	 *  General flow	: creates a Client.
	 */
	Client();

	/** Function name	    : connectToServer
	 * Parameters		: none
	 * Return value	    : none
	 * General flow	    : connects to server.
	 */
	void connectToServer();

	/** Function name	: getInctance
	 * Parameters		: none
	 * Return value	    : none
	 * General flow	    : Returns the only instance of client.
	 */
	static Client *getInctance();

	/** Function name	: sendInt
	 * Parameters		: integer
	 * Return value	    : none
	 * General flow	    : sends int to server.
	 */
	void sendInt(int num);
	/** Function name	: recieveInt
	 * Parameters		: none
	 * Return value	    : integer
	 * General flow	    : recieves int from server.
	 */
	int reciveInt();

	/** Function name	: sendString
	 * Parameters		: a string
	 * Return value	    : none
	 * General flow	    : sends a string to server.
	 */
	void sendString(string str);

	/** Function name	: reciveString
	 * Parameters		: none
	 * Return value	    : string
	 * General flow	    : recieves a string from server.
	 */
	string reciveString();

	/** Function name	: ResetInstace
	 * Parameters		: none
	 * Return value	    : none
	 * General flow	    : deletes the only instance of client.
	 */
	static void ResetInstace();
	/** Function name	: ~Client
	 * Parameters		: none
	 * Return value	    : none
	 * General flow	    : The Client's distructor.
	 */
	~Client();
};


#endif /* CLIENT_H_ */

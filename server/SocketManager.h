/**
 * Names       : Yifat Yankocivh
 * 				 Shoham Bar-Gad
 * IDs	       : 204709224
 * 				 315706614
 * User Names  : yankovy
 * 				 bagnosh
 *
 * Class Name  : SocketManager.h
 * Description : Defines the methods of SocketManager
 */

#ifndef SRC_SERVER_SOCKETMANAGER_H_
#define SRC_SERVER_SOCKETMANAGER_H_

#include <sys/socket.h>
#include <vector>
#include <pthread.h>

using namespace std;

class SocketManager {
private:
	vector<int> sockets_;
	vector<int> sockets_in_game_;
	pthread_mutex_t socket_mutex_;
public:
	/** Function name	: constructor
	 * Parameters		: none
	 * Return value	    : new SocketManager
	 * General flow	    : constructs a SocketManager
	 */
	SocketManager();

	/** Function name	: addSocket
	 * Parameters		: int (socket)
	 * Return value	    : none
	 * General flow	    : adds socket
	 */
	void addSocket(int socket);

	/** Function name	: addToGame
	 * Parameters		: int (socket)
	 * Return value	    : none
	 * General flow	    : adds existing socket to game
	 */
	void addToGame(int socket);

	/** Function name	: getInGame
	 * Parameters		: none
	 * Return value	    : vector<int>
	 * General flow	    : returns sockets in game
	 */
	vector<int> getInGame();

	/** Function name	: getWaiting
	 * Parameters		: none
	 * Return value	    : vector<int>
	 * General flow	    : returns sockets waiting for games
	 */
	vector<int> getWaiting();

	/** Function name	: removeSocket
	 * Parameters		: int (socket)
	 * Return value	    : none
	 * General flow	    : removes socket
	 */
	void removeSocket(int socket);

	/** Function name	: removeAll
	 * Parameters		: none
	 * Return value	    : none
	 * General flow	    : removes all sockets
	 */
	void removeAll();

	/** Function name	: closeSocket
	 * Parameters		: int (socket)
	 * Return value	    : none
	 * General flow	    : closes and removes socket
	 */
	void closeSocket(int socket);

	/** Function name	: closeAll
	 * Parameters		: none
	 * Return value	    : none
	 * General flow	    : closes and removes all sockets
	 */
	void closeAll();

	/** Function name	: destructor
	 * Parameters		: none
	 * Return value	    : none
	 * General flow	    : deletes the SocketManager
	 */
	virtual ~SocketManager();
};

#endif /* SRC_SERVER_SOCKETMANAGER_H_ */

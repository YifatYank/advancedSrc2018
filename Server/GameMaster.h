/**
 * Names       : Yifat Yankocivh
 * 				 Shoham Bar-Gad
 * IDs	       : 204709224
 * 				 315706614
 * User Names  : yankovy
 * 				 bagnosh
 *
 * Class Name  : GameMaster.h
 * Description : Defines the methods of the GameMaster.
 */

#ifndef SRC_SERVER_GAMEMASTER_H_
#define SRC_SERVER_GAMEMASTER_H_

#include "Game.h"
#include <vector>
#include <string>
#include <pthread.h>

using namespace std;

class GameMaster {
private:
	vector<Game> games_;
	pthread_mutex_t game_mutex_;
	Game findGame(string);
public:

	/** Function name	: constructor
	 * Parameters		: none
	 * Return value	    : constructed GameMaster
	 * General flow	    : Constructs a GameMaster
	 */
	GameMaster();

	/** Function name	: startGame
	 * Parameters		: string, integer (socket)
	 * Return value	    : Game
	 * General flow	    : starts a Game
	 */
	Game startGame(string name, int socket_number);

	/** Function name	: JoinGame
	 * Parameters		: string
	 * Return value	    : Game
	 * General flow	    : joins an existing Game
	 */
	Game joinGame(string name);

	/** Function name	: removeGame
	 * Parameters		: string
	 * Return value	    : none
	 * General flow	    : erases a Game
	 */
	void removeGame(string name);

	/** Function name	: getGames
	 * Parameters		: none
	 * Return value	    : vector<string>
	 * General flow	    : returns all game names
	 */
	vector<string> getGames();

	/** Function name	: destructor
	 * Parameters		: none
	 * Return value	    : none
	 * General flow	    : deletes the Game
	 */
	virtual ~GameMaster();
};

#endif /* SRC_SERVER_GAMEMASTER_H_ */

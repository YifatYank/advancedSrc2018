/**
 * Names       : Yifat Yankocivh
 * 				 Shoham Bar-Gad
 * IDs	       : 204709224
 * 				 315706614
 * User Names  : yankovy
 * 				 bagnosh
 *
 * Class Name  : GameManager.h
 * Description : Defines the attributes and methods needed to
 * 				 sustain and manage a running game and all of
 * 				 its components.
 */

#ifndef GAMEMANAGER_H_
#define GAMEMANAGER_H_

#include "Player.h"
#include "GameLogic.h"
#include "GameDisplay.h"

class GameManager {
private:
	Player * white_;
	Player * black_;
	GameLogic * logic_;
	Board * game_board_;
	GameDisplay * display_;
	CellValue winner_;

public:
	/**
	 * Function name    : GameManager
	 * Parameters       : two Player pointers and board width
	 * Return value     : Initialized GameManager
	 * General Flow     : Constructs a GameManager.
	 */
	GameManager(Player * white, Player * black, int width);

	/** Function name	: play
	 *  Parameters		: None.
	 *  Return value	: None.
	 *  General flow	: Plays the game, until it ends.
	 *  				  Controls game flow.
	 */
	virtual void play();

	/** Function name	: getWinner
	 *  Parameters		: None.
	 *  Return value	: The game's winning color value.
	 *  General flow	: Returns the games winner's colors.
	 *  				  However, if the game has not over yet,
	 *  				  the function returns the value EMPTY.
	 */
	virtual CellValue getWinner();

	/**
	 * Function name    : ~GameManager
	 * Parameters       : none
	 * Return value     : none
	 * General flow     : GameManager destructor.
	 */
	virtual ~GameManager();
};

#endif /* GAMEMANAGER_H_ */

/**
 * Names       : Yifat Yankocivh
 * 				 Shoham Bar-Gad
 * IDs	       : 204709224
 * 				 315706614
 * User Names  : yankovy
 * 				 bagnosh
 *
 * Class Name  : GameDisplay.h
 * Description : Defines the methods used to display
 * 				 the surface of the game.
 */

#ifndef GAMEDISPLAY_H_
#define GAMEDISPLAY_H_

#include "Board.h"
#include "GeneralDefinitions.h"

/** The class is an interface that represents how the game is displayed for the user. */
class GameDisplay {
public:
	/** Function name	: Display
	 *  Parameters		: game Board.
	 *  Return value	: None.
	 *  General flow	: Displays the game board.
	 */
	virtual void Display(const Board &bord) = 0;

	/**
	 * Function name    : DisplayOpenMenu
	 * Parameters       : none
	 * Return value     : GameType
	 * General flow     : displays the game choice menu,
	 * 					  returns choice.
	 */
	virtual GameType DisplayOpenMenu() = 0;

	/** Function name	: ~GameDisplay
	 *  Parameters		: None.
	 *  Return value	: None.
	 *  General flow	: GameDisplay's destructor.
	 */
	virtual ~GameDisplay() {
	}
};
#endif /* GAMEDISPLAY_H_ */

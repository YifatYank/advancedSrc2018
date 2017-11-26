/**
 * Name : Yifat Yankocivh
 * ID	: 204709224
 * User Name : yankovy
 */

#ifndef GAMEDISPLAY_H_
#define GAMEDISPLAY_H_

#include "Board.h"

/** The class is an interface that represents how the game is displayed for the user. */
class GameDisplay {
public:
	/** Function name	: Display
	 *  Parameters		: board - A game Board.
	 *  Return value	: None.
	 *  General flow	: Displaying the game board.
	 */
	virtual void Display(const Board &bord) = 0;

	/** Function name	: ~GameDisplay
	 *  Parameters		: None.
	 *  Return value	: None.
	 *  General flow	: GameDisplay's destractor.
	 */
	virtual ~GameDisplay(){}
};
#endif /* GAMEDISPLAY_H_ */

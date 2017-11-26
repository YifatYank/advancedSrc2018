/**
 * Name : Yifat Yankocivh
 * ID	: 204709224
 * User Name : yankovy
 */

#ifndef CONSULEDISPLAY_H_
#define CONSULEDISPLAY_H_

#include "GameDisplay.h"

/** The class represent a game that displayed to the user by the console*/
class ConsuleDisplay : public GameDisplay{
public:
	/** Function name	: ConsuleDisplay
	 *  Parameters		: None.
	 *  Return value	: None.
	 *  General flow	: Empty constractor.
	 */
	ConsuleDisplay();

	/** Function name	: Display
	 *  Parameters		: board - A game Board.
	 *  Return value	: None.
	 *  General flow	: Displaying the game board.
	 */
	virtual void Display(const Board &bord);

	/** Function name	: ~ConsuleDisplay
	 *  Parameters		: None.
	 *  Return value	: None.
	 *  General flow	: ConsuleDisplay's destractor.
	 */
	virtual ~ConsuleDisplay();

};

#endif /* CONSULEDISPLAY_H_ */

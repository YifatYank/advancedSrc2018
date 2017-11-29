/**
 * Names       : Yifat Yankocivh
 * 				 Shoham Bar-Gad
 * IDs	       : 204709224
 * 				 315706614
 * User Names  : yankovy
 * 				 bagnosh
 *
 * Class Name  : ConsuleDisplay.h
 * Description : Defines the methods used to display
 * 				 the surface of the game on the console.
 */

#ifndef CONSULEDISPLAY_H_
#define CONSULEDISPLAY_H_

#include "GameDisplay.h"

class ConsuleDisplay: public GameDisplay {
public:
	/** Function name	: ConsuleDisplay
	 *  Parameters		: None.
	 *  Return value	: None.
	 *  General flow	: Empty constructor.
	 */
	ConsuleDisplay();

	/** Function name	: Display
	 *  Parameters		: game Board.
	 *  Return value	: None.
	 *  General flow	: Displays the game board.
	 */
	virtual void Display(const Board &bord);

	/** Function name	: ~ConsuleDisplay
	 *  Parameters		: None.
	 *  Return value	: None.
	 *  General flow	: ConsuleDisplay's destructor.
	 */
	virtual ~ConsuleDisplay();

	/**
	 * Function name    : DisplayOpenMenu
	 * Parameters       : none
	 * Return value     : GameType
	 * General flow     : displays the game choice menu,
	 * 					  returns choice.
	 */
	virtual GameType DisplayOpenMenu();
};

#endif /* CONSULEDISPLAY_H_ */

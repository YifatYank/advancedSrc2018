ame /**
 * Name : Yifat Yankocivh
 * ID	: 204709224
 * User Name : yankovy
 */

#ifndef CONSOLEPLAYER_H_
#define CONSOLEPLAYER_H_

#include "Player.h"
#include "ConsuleDisplay.h"
using namespace std;

/** The class is an interface that represents a reversy player, that uses the console.*/
class ConsolePlayer: public Player {
private:
	Board * game_;
	CellValue value_;
	ConsuleDisplay * display_;

public:
	/** Function name	: ConsolePlayer
	 *  Parameters		: value - The players value - the player 'color'.
	 *  Return value	: The console player created.
	 *  General flow	: Assinment of the members.
	 */
	ConsolePlayer(CellValue value);

	/** Function name	: move
	 *  Parameters		: The functions gets a list of possible move.
	 *  Return value	: The point chosen between the points provided.
	 *  General flow	: The function let the user chose between the optional points,
	 *  				  checks if the point is from the point provided, and returns the point chosen.
	 */
	virtual Point move(vector<Point *> * moves);

	/** Function name	: getValue
	 *  Parameters		: None.
	 *  Return value	: The returns the player value, "color".
	 *  General flow	: The function return the player's value, the player's color.
	 */
	virtual CellValue getValue () const;

	/** Function name	: setBoard
	 *  Parameters		: board - A game board.
	 *  Return value	: None.
	 *  General flow	: The functions set the board the player uses.
	 */
	virtual void setBoard(Board * board);

	/** Function name	: ~ConsolePlayer
	 *  Parameters		: None.
	 *  Return value	: None.
	 *  General flow	: Distractor of ConsolePlayer.
	 */
	virtual ~ConsolePlayer();
};

#endif /* CONSOLEPLAYER_H_ */

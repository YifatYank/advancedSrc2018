/**
 * Names       : Yifat Yankocivh
 * 				 Shoham Bar-Gad
 * IDs	       : 204709224
 * 				 315706614
 * User Names  : yankovy
 * 				 bagnosh
 *
 * Class Name  : ConsolePlayer.h
 * Description : Defines the attributes and methods of a
 * 				 human player in the game. (Interface)
 */

#ifndef CONSOLEPLAYER_H_
#define CONSOLEPLAYER_H_

#include "Player.h"
#include "ConsuleDisplay.h"
using namespace std;

class ConsolePlayer: public Player {
private:
	//Board * game_;
	CellValue value_;
	ConsuleDisplay * display_;

public:
	/** Function name	: ConsolePlayer
	 *  Parameters		: Player's value ('color').
	 *  Return value	: The created console player.
	 *  General flow	: Assignment of the members.
	 */
	ConsolePlayer(CellValue value);

	/** Function name	: move
	 *  Parameters      : list of possible moves, last move of  the opponent,
	 *  				  game board.
	 *  Return value	: The point chosen between the points provided.
	 *  General flow	: The function lets the user choose their next move,
	 *  				  checks if the point is legal,
	 *  				  and returns the point finally chosen.
	 */
	virtual Point move(vector<Point *> * moves, Point opponent_move,
			Board &board);

	/** Function name	: getValue
	 *  Parameters		: None.
	 *  Return value	: a player's value, their "color".
	 *  General flow	: The function returns the player's value,
	 *  				  the player's color.
	 */
	virtual CellValue getValue() const;

	/** Function name	: ~ConsolePlayer
	 *  Parameters		: None.
	 *  Return value	: None.
	 *  General flow	: ConsolePlayer destructor.
	 */
	virtual ~ConsolePlayer();
};

#endif /* CONSOLEPLAYER_H_ */

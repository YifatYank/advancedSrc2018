/**
 * Name : Yifat Yankocivh
 * ID	: 204709224
 * User Name : yankovy
 */

#ifndef CLASSICLOGIC_H_
#define CLASSICLOGIC_H_
#include "GameLogic.h"
#include "Player.h"
#include "GameDisplay.h"
#include "ConsuleDisplay.h"
#include "Point.h"
#include <iostream>
using namespace std;

/*The class represents the classical logic of reversy game */
class ClassicLogic : public GameLogic {
private:
	Board * game_board_;
	Player * white_;
	Player * black_;

	bool playDirection(int x,int y,int xMove,int yMove, CellValue value, bool checkMode);
public:
	/** Function name	: ClassicLogic
	 *  Parameters		: size, and two players.
	 *  Return value	: The ClassicLogic created.
	 *  General flow	: Assignment of members, creation of the board and initialization of the board .
	 */
	ClassicLogic(Board * board, Player * first, Player * second);

	virtual Board * getBoard();

	virtual Board * swapBoard(Board * board);

	/** Function name	: getLegalMoves
	 *  Parameters		: A player's value - a player's color.
	 *  Return value	: A vector contains all the legal moves the player can do.
	 *  General flow	: Check all the cells in the game board - if they are legal moves.
	 *  			      If the cell is a legal move - the function adds the cell's location to the vector.
	 */
	virtual vector<Point *> * getLegalMoves(CellValue value);


	/** Function name	: playMove
	 *  Parameters		: The player's value - a player's color, and the player's move.
	 *  Return value	: If the move is legal or not.
	 *  General flow	: Check if the move is legal - if  the move is legal the function plays the move.
	 */
	virtual bool playMove(Point move, CellValue value);


	/** Function name	: ~ClassicLogic
	 *  Parameters		: None.
	 *  Return value	: None.
	 *  General flow	: The classicLogic destractor. Frees the board was allocated in the constractor.
	 */
	virtual ~ClassicLogic();
};

#endif /* CLASSICLOGIC_H_ */

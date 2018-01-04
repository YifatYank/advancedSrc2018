/**
 * Names       : Yifat Yankocivh
 * 				 Shoham Bar-Gad
 * IDs	       : 204709224
 * 				 315706614
 * User Names  : yankovy
 * 				 bagnosh
 *
 * Class Name  : RemotePlayer.h
 * Description : Defines the methods of the RemotePlayer class.
 */

#ifndef REMOTEPLAYER_H_
#define REMOTEPLAYER_H_

#include "Player.h"
#include "Client.h"

class RemotePlayer: public Player {
private:
	Client & client_;
	CellValue value_;
	bool first_t_; //Indicates weather it is the first step of the user.

public:
	/** Function name    : constructor
	 *  Parameters       : Client reference
	 *  Return value     : new RemotePlayer
	 *  General flow     : constructs a RemotePlayer
	 */
	RemotePlayer(Client & client);

	/** Function name    : constructor
	 *  Parameters       : color, Client reference
	 *  Return value     : new RemotePlayer
	 *  General flow     : constructs a RemotePlayer
	 */
	RemotePlayer(CellValue value, Client & client);

	/** Function name	: getValue
	 *  Parameters		: None.
	 *  Return value	: a player's value, their "color".
	 *  General flow	: The function returns the player's value,
	 *  				  the player's color.
	 */
	virtual CellValue getValue() const;

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

	/** Function name    : destructor
	 *  Parameters       : none
	 *  Return value     : none
	 *  General flow     : deletes the RemotePlayer
	 */
	virtual ~RemotePlayer();
};

#endif /* REMOTEPLAYER_H_ */

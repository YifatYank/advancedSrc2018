/**
 * Names       : Yifat Yankocivh
 * 				 Shoham Bar-Gad
 * IDs	       : 204709224
 * 				 315706614
 * User Names  : yankovy
 * 				 bagnosh
 *
 * Class Name  : AIPlayer.cpp
 * Description : Implements the methods of an
 * 				 artificial player in the game.
 */

#include "AIPlayer.h"
#include <iostream>
#include <limits>
#include <math.h>

AIPlayer::AIPlayer(CellValue value, GameLogic * logic) {
	this->value_ = value;
	this->logic_ = logic;
}

Point AIPlayer::move(vector<Point*>* moves, Point last_move, Board &board) {
	// For debug
//	ConsuleDisplay * dis = new ConsuleDisplay();

	Board * replace = board.copyBoard();
	Board * tem;// =
	this->logic_->swapBoard(replace);

	//define opponent's color
	CellValue opponent;
	opponent = (this->value_ == WHITE) ? BLACK : WHITE;

	// This part only applies after the first move
	if (last_move != Point(-1, -1)) {
		//play last turn
		logic_->playMove(last_move, opponent);
	}
	/*
	 // Debug thing
	 cout << "-------------------------------------------" << endl;
	 cout << "Board after other player's played" << endl;
	 dis->Display(*this->logic_->getBoard());
	 */
	//set bookmark values
	Point bestMove(-1, -1);
	int minScore = (int) pow(this->logic_->getBoard()->getGameBoardWidth(), 2);

	vector<Point*>::iterator m = moves->begin();
	for (; m != moves->end(); m++) {
		//copy actual board to save current state
		tem = this->logic_->getBoard()->copyBoard();
		//replace actual board with tem, hold actual
		Board * hold = this->logic_->swapBoard(tem);
		//simulate turn:
		//change operable board
		Point point((*m)->getX(), (*m)->getY());
		logic_->playMove(point, this->value_);

		/*
		 //Debug thing
		 // The board after this player move simulation
		 cout << "Simulate AI's move" << "(" << (*m)->getX() << ","
		 << (*m)->getY() << ")" << endl;
		 dis->Display(*this->logic_->getBoard());
		 */

		//get opponent's possible moves
		vector<Point*> * opMoves = logic_->getLegalMoves(opponent);
		//our best possible score
		int maxScore = -(int) pow(this->logic_->getBoard()->getGameBoardWidth(),
				2);

		vector<Point*>::iterator n = opMoves->begin();

		for (; n != opMoves->end(); n++) {
			//replace operable board with temmie, hold temp on bold
			Board * temmie = tem->copyBoard();
			Board * bold = this->logic_->swapBoard(temmie);

			Point p((*n)->getX(), (*n)->getY());

			logic_->playMove(p, opponent);
			/*
			 //Debug thing
			 // The board after this player move simulation
			 cout << "Simulate opponent's move after AI's move" << "("
			 << (*n)->getX() << "," << (*n)->getY() << ")" << endl;
			 dis->Display(*this->logic_->getBoard());
			 */

			int score = (logic_->getBoard()->getBlackCellsNumber())
					- (logic_->getBoard()->getWhiteCellsNumber());
			if (score > maxScore) {
				maxScore = score;
			}
			//delete temmie
			Board * goner = this->logic_->swapBoard(bold);
			goner->copyBoard();
			delete (goner);
		}
		opMoves->clear();
		delete (opMoves);
		if (maxScore < minScore) {
			minScore = maxScore;
			bestMove.setX((*m)->getX());
			bestMove.setY((*m)->getY());
		}
		Board * goner = this->logic_->swapBoard(hold);
		delete (goner);
	}

	/*
	 //Debug thing
	 // The board after this player move simulation
	 cout << "Back to original board" << endl;
	 dis->Display(*this->logic_->getBoard());
	 */

	Point ret(bestMove.getX(), bestMove.getY());
	moves->clear();
	delete (moves);

	//if the AIPlayer has no moves left, don't do a thing.
	if (ret != Point(-1, -1)) {
		// Updates the permanent board with the chosen move
		this->logic_->playMove(ret, this->value_);
	}

	/*
	 //Debug thing
	 // The board after chosen move is played
	 cout << "I've decided!" << endl;
	 dis->Display(*this->logic_->getBoard());
	 */

	//return as last move
	return ret;
}

CellValue AIPlayer::getValue() const {
	return this->value_;
}

AIPlayer::~AIPlayer() {
}

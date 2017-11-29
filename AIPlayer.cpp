/*
 * AIPlayer.cpp
 *
 *  Created on: Nov 27, 2017
 *      Author: shomps
 */

#include "AIPlayer.h"
#include <iostream>
#include <limits>
#include <math.h>

AIPlayer::AIPlayer(CellValue value, GameLogic * logic) :
		value_(value) {
	this->display_ = new ConsuleDisplay();
	this->game_ = NULL;
	this->logic_ = logic;
}

Point AIPlayer::move(vector<Point*>* moves, Point last_move) {
	//define opponent's color
	CellValue opponent;
	opponent = (this->value_ == WHITE) ? BLACK : WHITE;
	//play last turn
	logic_->playMove(last_move, opponent);
	//set bookmark values
	Point bestMove(0,0);
	int minScore = (int) pow(this->game_->getGameBoardWidth(), 2);

	vector<Point*>::iterator m = moves->begin();

	for (; m != moves->end(); m++) {
		//copy actual board to save current state
		Board * tem = game_->copyBoard();
		//replace actual board with tem, hold actual
		Board * hold = this->logic_->swapBoard(tem);
		//simulate turn:
		//change operable board
		logic_->playMove(m, value_);
		//get opponent's possible moves
		vector<Point*> opMoves = logic_->getLegalMoves(opponent);
		//our best possible score
		int maxScore = -(int*) pow(this->game_->getGameBoardWidth(), 2);

		vector<Point*>::iterator n = opMoves->begin();

		for (; n != opMoves->end(); n++) {
			//replace operable board with temmie, hold temp on bold
			Board temmie = tem->copyBoard();
			Board * bold = this->logic_->GameLogic::swapBoard(temmie);
			//
			logic_->playMove(n, opponent);
			int score = (logic_->getBoard()->getBlackCellsNumber())
					- (logic_->getBoard()->getWhiteCellsNumber());
			if (score > maxScore) {
				maxScore = score;
			}
			//delete temmie
			Board * goner = this->logic_->swapBoard(temmie);
			delete(goner);
		}
		delete(opMoves);
		if (maxScore < minScore) {
			minScore = maxScore;
			bestMove = m;
		}
		Board * goner = this->logic_->swapBoard(hold);
		delete(goner);
	}
	Point ret(bestMove.x_, bestMove.y_);
	delete(moves);
	return ret;
}

CellValue AIPlayer::getValue() const {
	return this->value_;
}

void AIPlayer::setBoard(Board* board) {
	this->game_ = board;
}

AIPlayer::~AIPlayer() {
}

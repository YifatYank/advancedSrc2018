/**
 * Name : Yifat Yankocivh
 * ID	: 204709224
 * User Name : yankovy
 */

#include "ClassicLogic.h"
using namespace std;

ClassicLogic::ClassicLogic(Board * board, Player * first, Player * second) : white_(first), black_(second) {
	int half = board->getGameBoardWidth() / 2;
	this->gameBoard_ = board;
	this->gameBoard_->setCellValue(half, half, WHITE);
	this->gameBoard_->setCellValue(half + 1,half + 1, WHITE);
	this->gameBoard_->setCellValue(half,half + 1, BLACK);
	this->gameBoard_->setCellValue(half + 1, half, BLACK);
	this->black_->setBoard(this->gameBoard_);
	this->white_->setBoard(this->gameBoard_);
}

ClassicLogic::~ClassicLogic() {
}

bool ClassicLogic::playDirection(int x,int y,int xMove,int yMove, CellValue value, bool checkMode) {
    int isTurned;

    // If out of range
    if(this->gameBoard_->getCellValue(x,y) == BOEDER) {
        return false;
    }

    // If we reached an empty spot.
    if(this->gameBoard_->getCellValue(x,y) == EMPTY){
        // 1 means false
    	return false;
    }

    // If we reaches a cell with the current player's color
    if(this->gameBoard_->getCellValue(x,y) == value){
        return true;
    }

    // We are in a cell with the opponent's color
    // Checks if there is a cell with the players color in the end
    isTurned = playDirection(x + xMove, y + yMove, xMove, yMove, value, checkMode);
    // If we have to turn the cell's color
    if(isTurned){
        if(!checkMode) {
            this->gameBoard_->setCellValue(x,y,value);
        }
    }
    return isTurned;
}

bool ClassicLogic::playMove(Point move, CellValue value) {
	bool is_legal = false;

	this->gameBoard_->setCellValue(move.getX(),move.getY(),value);

	// Change up
	if((this->gameBoard_->getCellValue(move.getX()- 1, move.getY()) != BOEDER) &&
	   (this->gameBoard_->getCellValue(move.getX() - 1,move.getY()) != EMPTY) &&
	   (this->gameBoard_->getCellValue(move.getX() - 1,move.getY()) != value) &&
	   (this->playDirection(move.getX() - 1, move.getY(), -1,0, value,false))) {
		is_legal = true;
	}

	// Change down
	if((this->gameBoard_->getCellValue(move.getX() + 1,move.getY()) != BOEDER) &&
	   (this->gameBoard_->getCellValue(move.getX() + 1,move.getY()) != EMPTY) &&
	   (this->gameBoard_->getCellValue(move.getX() + 1,move.getY()) != value) &&
	   (this->playDirection(move.getX() + 1, move.getY(), 1,0, value,false))) {
		is_legal = true;
	}

	// Check left.
	if ((this->gameBoard_->getCellValue(move.getX(),move.getY() - 1) != BOEDER) &&
		(this->gameBoard_->getCellValue(move.getX(),move.getY() - 1) != EMPTY) &&
		(this->gameBoard_->getCellValue(move.getX(),move.getY() - 1) != value) &&
			(this->playDirection(move.getX(), move.getY() - 1, 0, - 1, value,false))) {
			is_legal = true;
	}

	// Check right.
	if ((this->gameBoard_->getCellValue(move.getX(),move.getY() + 1) != BOEDER) &&
	    (this->gameBoard_->getCellValue(move.getX(),move.getY() + 1) != EMPTY) &&
		(this->gameBoard_->getCellValue(move.getX(),move.getY() + 1) != value) &&
		(this->playDirection(move.getX(), move.getY() + 1, 0, 1, value,false))) {
		is_legal = true;
	}

	// Check up right
	if ((this->gameBoard_->getCellValue(move.getX() + 1,move.getY() + 1) != BOEDER) &&
		(this->gameBoard_->getCellValue(move.getX() + 1,move.getY() + 1) != EMPTY) &&
		(this->gameBoard_->getCellValue(move.getX() + 1,move.getY()+ 1) != value) &&
		(this->playDirection(move.getX() + 1, move.getY() + 1, 1, 1, value,false))) {
		is_legal = true;
	}

	// Check up left
	if ((this->gameBoard_->getCellValue(move.getX() + 1,move.getY() - 1) != BOEDER) &&
	    (this->gameBoard_->getCellValue(move.getX() + 1,move.getY() - 1) != EMPTY) &&
		(this->gameBoard_->getCellValue(move.getX() + 1,move.getY() - 1) != value) &&
		(this->playDirection(move.getX() + 1, move.getY() - 1, 1, - 1, value,false))) {
		is_legal = true;
	}

	// Check down right
	if ((this->gameBoard_->getCellValue(move.getX() - 1,move.getY() + 1) != BOEDER) &&
		(this->gameBoard_->getCellValue(move.getX() - 1,move.getY() + 1) != EMPTY) &&
		(this->gameBoard_->getCellValue(move.getX() - 1,move.getY()+ 1) != value) &&
		(this->playDirection(move.getX() - 1, move.getY() + 1, -1,1, value,false))) {
		is_legal = true;
	}

	// Check down left
	if ((this->gameBoard_->getCellValue(move.getX() - 1,move.getY() - 1) != BOEDER) &&
		(this->gameBoard_->getCellValue(move.getX() - 1,move.getY() - 1) != EMPTY) &&
		(this->gameBoard_->getCellValue(move.getX() - 1,move.getY() - 1) != value) &&
		(this->playDirection(move.getX() - 1, move.getY() - 1, -1, -1, value,false))) {
		is_legal = true;
	}

	return is_legal;
}

vector <Point *> * ClassicLogic::getLegalMoves(CellValue value){
    int height = this->gameBoard_->getGameBoardWidth();


    vector<Point *> * moves_list = new vector<Point *>();
    // Goes trough all the array cells and search for a legal move.
    for(int index = 1; index <= height; index++){
    	for(int jndex = 1; jndex <= height; jndex++){
    		if(this->gameBoard_->getCellValue(index, jndex) == EMPTY) {
    			// Check up
    			if((this->gameBoard_->getCellValue(index - 1,jndex) != BOEDER) &&
    			   (this->gameBoard_->getCellValue(index - 1,jndex) != EMPTY) &&
				   (this->gameBoard_->getCellValue(index - 1,jndex) != value) &&
				   (this->playDirection(index - 1, jndex, -1,0, value,true))) {
    				Point * p = new Point(index, jndex);
    				moves_list->push_back(p);
				// Check down
    			} else if((this->gameBoard_->getCellValue(index + 1,jndex) != BOEDER) &&
    					  (this->gameBoard_->getCellValue(index + 1,jndex) != EMPTY) &&
						  (this->gameBoard_->getCellValue(index + 1,jndex) != value) &&
						  (this->playDirection(index + 1, jndex, 1,0, value,true))) {
    				Point * p = new Point(index, jndex);
    				moves_list->push_back(p);
    			// Check left.
    			} else if ((this->gameBoard_->getCellValue(index,jndex - 1) != BOEDER) &&
    					   (this->gameBoard_->getCellValue(index,jndex - 1) != EMPTY) &&
					       (this->gameBoard_->getCellValue(index,jndex - 1) != value) &&
					       (this->playDirection(index, jndex - 1, 0, - 1, value,true))) {
    				Point * p = new Point(index, jndex);
    				moves_list->push_back(p);
    			// Check right.
    			} else if ((this->gameBoard_->getCellValue(index,jndex + 1) != BOEDER) &&
    					   (this->gameBoard_->getCellValue(index,jndex + 1) != EMPTY) &&
						   (this->gameBoard_->getCellValue(index,jndex + 1) != value) &&
						   (this->playDirection(index, jndex + 1, 0, 1, value,true))) {
    				Point * p = new Point(index, jndex);
    				moves_list->push_back(p);
    				// Check up right
    			} else if ((this->gameBoard_->getCellValue(index + 1,jndex + 1) != BOEDER) &&
    					   (this->gameBoard_->getCellValue(index + 1,jndex + 1) != EMPTY) &&
						   (this->gameBoard_->getCellValue(index + 1,jndex + 1) != value) &&
						   (this->playDirection(index + 1, jndex + 1, 1, 1, value,true))) {
    				Point * p = new Point(index, jndex);
    				moves_list->push_back(p);
				// 	Check up left
    			} else if ((this->gameBoard_->getCellValue(index + 1,jndex - 1) != BOEDER) &&
    					   (this->gameBoard_->getCellValue(index + 1,jndex - 1) != EMPTY) &&
						   (this->gameBoard_->getCellValue(index + 1,jndex - 1) != value) &&
						   (this->playDirection(index + 1, jndex - 1, 1, - 1, value,true))) {
    				Point * p = new Point(index, jndex);
    				moves_list->push_back(p);
				// 	Check down right
    			} else if ((this->gameBoard_->getCellValue(index - 1,jndex + 1) != BOEDER) &&
    					   (this->gameBoard_->getCellValue(index - 1,jndex + 1) != EMPTY) &&
						   (this->gameBoard_->getCellValue(index - 1,jndex + 1) != value) &&
						   (this->playDirection(index - 1, jndex + 1, -1,1, value,true))) {
    				Point * p = new Point(index, jndex);
    				moves_list->push_back(p);
				// 	Check down left
    			} else if ((this->gameBoard_->getCellValue(index - 1,jndex - 1) != BOEDER) &&
    					   (this->gameBoard_->getCellValue(index - 1,jndex - 1) != EMPTY) &&
						   (this->gameBoard_->getCellValue(index - 1,jndex - 1) != value) &&
						   (this->playDirection(index - 1, jndex - 1, -1, -1, value,true))) {
    				Point * p = new Point(index, jndex);
					moves_list->push_back(p);
    			}
    		}
    	}
    }
    return moves_list;
}


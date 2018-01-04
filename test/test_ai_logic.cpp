
#include "ClassicLogic.h"
#include "AIPlayer.h"
#include "gtest/gtest.h"

TEST(tesAiPlayer, senario1){
	Board * b =  new Board(4);
	ClassicLogic * logic = new ClassicLogic(b);
	Player * player = new AIPlayer(WHITE,new ClassicLogic(b->copyBoard()));
	logic->playMove(Point(1,3),WHITE);
	logic->playMove(Point(1,2),BLACK);

	Point p = player->move(logic->getLegalMoves(WHITE),Point(-1,-1),*(logic->getBoard()));
	logic->playMove(p, WHITE);
	EXPECT_EQ(1, logic->getBoard()->getBlackCellsNumber());
	EXPECT_EQ(6, logic->getBoard()->getWhiteCellsNumber());
}

TEST(tesAiPlayer, senario2){
	Board * b =  new Board(4);
	ClassicLogic * logic = new ClassicLogic(b);
	Player * player = new AIPlayer(WHITE,new ClassicLogic(b->copyBoard()));
	logic->playMove(Point(1,3),WHITE);
	logic->playMove(Point(1,2),BLACK);
	logic->playMove(Point(1,1),WHITE);
	logic->playMove(Point(3,4),BLACK);
	Point p = player->move(logic->getLegalMoves(WHITE),Point(-1,-1),*(logic->getBoard()));
	logic->playMove(p, WHITE);
	EXPECT_EQ(2, logic->getBoard()->getBlackCellsNumber());
	EXPECT_EQ(7, logic->getBoard()->getWhiteCellsNumber());
}


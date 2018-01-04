#include "ClassicLogic.h"
#include "gtest/gtest.h"

TEST(ClassicLoficTest, getLegalMoves){
	Board * b  = new Board(4);
	ClassicLogic * logic = new ClassicLogic(b);
	vector<Point*> * vec = logic->getLegalMoves(WHITE);
	vector<Point*>::iterator  it = vec->begin();
	for(;it!=vec->end(); it++) {
		Point * p = (*it);
		EXPECT_TRUE(((*p == Point(1,3)) || *p == Point(3,1) || *p == Point(2,4) || *p == Point(4,2)));
	}

	logic->playMove(Point(1,3),WHITE);
	vec = logic->getLegalMoves(BLACK);
	it = vec->begin();
	for(;it!=vec->end(); it++) {
		Point * p = (*it);
		EXPECT_TRUE(((*p == Point(1,2)) || *p == Point(1,4) || *p == Point(3,4)));
	}

	delete(logic);
	delete(b);
}

TEST(ClassicLoficTest, makeMoveWhite){
	Board * b =  new Board(4);
	ClassicLogic * logic = new ClassicLogic(b);
	logic->playMove(Point(1,3),WHITE);

	EXPECT_EQ(logic->getBoard()->getCellValue(1,1), EMPTY);
	EXPECT_EQ(logic->getBoard()->getCellValue(1,2), EMPTY);
	EXPECT_EQ(logic->getBoard()->getCellValue(1,3), WHITE);
	EXPECT_EQ(logic->getBoard()->getCellValue(1,4), EMPTY);
	EXPECT_EQ(logic->getBoard()->getCellValue(2,1), EMPTY);
	EXPECT_EQ(logic->getBoard()->getCellValue(2,2), WHITE);
	EXPECT_EQ(logic->getBoard()->getCellValue(2,3), WHITE);
	EXPECT_EQ(logic->getBoard()->getCellValue(2,4), EMPTY);
	EXPECT_EQ(logic->getBoard()->getCellValue(3,1), EMPTY);
	EXPECT_EQ(logic->getBoard()->getCellValue(3,2), BLACK);
	EXPECT_EQ(logic->getBoard()->getCellValue(3,3), WHITE);
	EXPECT_EQ(logic->getBoard()->getCellValue(3,4), EMPTY);
	EXPECT_EQ(logic->getBoard()->getCellValue(4,1), EMPTY);
	EXPECT_EQ(logic->getBoard()->getCellValue(4,2), EMPTY);
	EXPECT_EQ(logic->getBoard()->getCellValue(4,3), EMPTY);
	EXPECT_EQ(logic->getBoard()->getCellValue(4,4), EMPTY);
}

TEST(ClassicLoficTest, makeMoveBlack){
	Board * b =  new Board(4);
	ClassicLogic * logic = new ClassicLogic(b);
	logic->playMove(Point(1,3),WHITE);
	logic->playMove(Point(1,2),BLACK);

	EXPECT_EQ(logic->getBoard()->getCellValue(1,1), EMPTY);
	EXPECT_EQ(logic->getBoard()->getCellValue(1,2), BLACK);
	EXPECT_EQ(logic->getBoard()->getCellValue(1,3), WHITE);
	EXPECT_EQ(logic->getBoard()->getCellValue(1,4), EMPTY);
	EXPECT_EQ(logic->getBoard()->getCellValue(2,1), EMPTY);
	EXPECT_EQ(logic->getBoard()->getCellValue(2,2), BLACK);
	EXPECT_EQ(logic->getBoard()->getCellValue(2,3), WHITE);
	EXPECT_EQ(logic->getBoard()->getCellValue(2,4), EMPTY);
	EXPECT_EQ(logic->getBoard()->getCellValue(3,1), EMPTY);
	EXPECT_EQ(logic->getBoard()->getCellValue(3,2), BLACK);
	EXPECT_EQ(logic->getBoard()->getCellValue(3,3), WHITE);
	EXPECT_EQ(logic->getBoard()->getCellValue(3,4), EMPTY);
	EXPECT_EQ(logic->getBoard()->getCellValue(4,1), EMPTY);
	EXPECT_EQ(logic->getBoard()->getCellValue(4,2), EMPTY);
	EXPECT_EQ(logic->getBoard()->getCellValue(4,3), EMPTY);
	EXPECT_EQ(logic->getBoard()->getCellValue(4,4), EMPTY);
}

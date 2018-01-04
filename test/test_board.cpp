#include "Board.h"
#include "gtest/gtest.h"

TEST(BoardTest, GettersAndStters){
	Board board(4);
	EXPECT_EQ(BOEDER,board.getCellValue(0,0));
	EXPECT_EQ(EMPTY,board.getCellValue(1,1));
	board.setCellValue(1,2,WHITE);
	board.setCellValue(3,4,BLACK);
	EXPECT_EQ(WHITE,board.getCellValue(1,2));
	EXPECT_EQ(BLACK,board.getCellValue(3,4));
}

TEST(BoardTest, TraceNumOfaluesCells){
	Board board(4);
	EXPECT_EQ(4,board.getGameBoardWidth());

	EXPECT_EQ(16,board.getEmptyCellsNumber());
	EXPECT_EQ(0,board.getWhiteCellsNumber());
	EXPECT_EQ(0,board.getBlackCellsNumber());

	board.setCellValue(1,1,WHITE);
	board.setCellValue(1,2,BLACK);
	EXPECT_EQ(14,board.getEmptyCellsNumber());
	EXPECT_EQ(1,board.getWhiteCellsNumber());
	EXPECT_EQ(1,board.getBlackCellsNumber());
}

TEST(BoardTest, TestCopy){
	Board board(4);
	board.setCellValue(1,1,WHITE);
	board.setCellValue(1,2,BLACK);
	Board * new_board = board.copyBoard();

	for(int i = 0; i< board.getGameBoardWidth();i++){
		for(int j = 0; j < board.getGameBoardWidth();j++){
			EXPECT_EQ(board.getCellValue(i,j) ,new_board->getCellValue(i,j));
		}
	}

}

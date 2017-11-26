/**
 * Name : Yifat Yankocivh
 * ID	: 204709224
 * User Name : yankovy
 */

#ifndef GENERALDEFINITIONS_H_
#define GENERALDEFINITIONS_H_

/**The struct represents a cell in the board.*/
struct Point{
	int x_;
	int y_;
};

/** The enum represents the possible values that a game cell could have.*/
enum CellValue{ BOEDER,
				EMPTY,
				BLACK,
				WHITE };

#endif /* GENERALDEFINITIONS_H_ */

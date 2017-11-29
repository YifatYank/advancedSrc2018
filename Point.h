/*
 * Point.h
 *
 *  Created on: Nov 27, 2017
 *      Author: yifat
 */

#ifndef POINT_H_
#define POINT_H_

class Point {
private:
	int x_;
	int y_;

public:
	Point(int x, int y);
	Point(const Point &obj);
	Point * copy();
	int getX()const;
	void setX(int x);
	int getY()const;
	void setY(int y);
	bool operator ==(Point &other) const;
	bool operator !=(Point &other) const;
	virtual ~Point();
};

#endif /* POINT_H_ */

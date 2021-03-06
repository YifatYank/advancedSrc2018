/**
 * Names       : Yifat Yankocivh
 * 				 Shoham Bar-Gad
 * IDs	       : 204709224
 * 				 315706614
 * User Names  : yankovy
 * 				 bagnosh
 *
 * Class Name  : Point.cpp
 * Description : Implements the attributes and methods of a point
 * 				 within the game.
 */

#include "Point.h"

Point::Point(int x, int y) : x_(x), y_(y) {
}

Point::Point(const Point &obj) {
   x_ = obj.getX();
   y_ = obj.getY();
}

Point * Point::copy() {
	Point * point = new Point(*this);
	return point;
}

int Point::getX()const{
	return this->x_;
}

int Point::getY()const{
	return this->y_;
}

void Point::setX(int x){
	this->x_ = x;
}

void Point::setY(int y){
	this->y_ = y;
}

bool Point::operator ==(const Point &other) const{
	if((this->x_ == other.x_) && (this->y_ == other.y_)){
		return true;
	}
	return false;
}

bool Point::operator !=(const Point &other) const {
	return !(*this == other);
}

Point::~Point() {
}


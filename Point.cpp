/*
 * Point.cpp
 *
 *  Created on: Nov 27, 2017
 *      Author: yifat
 */

#include "Point.h"

Point::Point(int x, int y) : x_(x), y_(y) {
}

Point::Point(const Point &obj) {
   x_ = obj.x_;
   y_ = obj.y_;
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

bool Point::operator ==(Point &other) const{
	if((this->x_ == other.getX()) && (this->y_ == other.getY())){
		return true;
	}
	return false;
}

bool Point::operator !=(Point &other) const {
	return !(this->operator ==(other));
}

Point::~Point() {
}


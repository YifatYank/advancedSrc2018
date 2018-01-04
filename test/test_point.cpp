#include "Point.h"
#include "gtest/gtest.h"

TEST(PointTest, PointStters){
	Point p(1,2);
	EXPECT_EQ(1,p.getX());
	EXPECT_EQ(2,p.getY());
	p.setX(3);
	p.setY(4);
	EXPECT_EQ(1,p.getX());
	EXPECT_EQ(2,p.getY());
}

TEST(PointTest, comparation){
	Point p(1,2);
	Point q(1,2);
	Point r(1,3);
	Point s(4,2);
	EXPECT_TRUE(p==q);
	EXPECT_FALSE(p==r);
	EXPECT_FALSE(p==s);
}

TEST(PointTest, copy){
	Point p(1,2);
	Point * q = p.copy();
	EXPECT_TRUE(p==*q);
	delete(q);
}

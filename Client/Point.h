/**
 * Names       : Yifat Yankocivh
 * 				 Shoham Bar-Gad
 * IDs	       : 204709224
 * 				 315706614
 * User Names  : yankovy
 * 				 bagnosh
 *
 * Class Name  : Point.h
 * Description : Defines the attributes and methods of a point
 * 				 within the game.
 */

#ifndef POINT_H_
#define POINT_H_

class Point {
private:
	//x coordinate
	int x_;
	//y coordinate
	int y_;

public:
	/** Function name	: Point constructor
	 *  Parameters		: Two integers (coordinates).
	 *  Return value	: Initialized Point
	 *  General flow	: The function initializes a Point
	 *  				  from two integers.
	 */
	Point(int x, int y);

	/** Function name	: Point copy constructor
	 *  Parameters		: Another Point.
	 *  Return value	: Copied instance of Point
	 *  General flow	: The function copies an instance
	 *  	              from an existing Point.
	 */
	Point(const Point &obj);

	/** Function name	: copy
	 *  Parameters		: none.
	 *  Return value	: Point (pointer)
	 *  General flow	: The function calls the copy constructor
	 *  	              and returns a pointer to its product.
	 */
	Point * copy();

	/** Function name	: getX
	 *  Parameters		: none.
	 *  Return value	: x coordinate
	 *  General flow	: The function returns a Point's
	 *  				  x coordinate.
	 */
	int getX() const;

	/** Function name	: setX
	 *  Parameters		: x coordinate
	 *  Return value	: none
	 *  General flow	: The function sets a Point's
	 *  				  x coordinate.
	 */
	void setX(int x);

	/** Function name	: getY
	 *  Parameters		: none.
	 *  Return value	: y coordinate
	 *  General flow	: The function returns a Point's
	 *  				  y coordinate.
	 */
	int getY() const;

	/** Function name	: setY
	 *  Parameters		: y coordinate
	 *  Return value	: none
	 *  General flow	: The function sets a Point's
	 *  				  y coordinate.
	 */
	void setY(int y);

	/** Function name	: operator definer (==)
	 *  Parameters		: another Point
	 *  Return value	: boolean value
	 *  General flow	: defines comparison between two Points.
	 */
	bool operator ==(const Point &other) const;

	/** Function name	: operator definer (!=)
	 *  Parameters		: another Point
	 *  Return value	: boolean value
	 *  General flow	: defines comparison between two Points.
	 */
	bool operator !=(const Point &other) const;

	/** Function name	: ~Point
	 *  Parameters		: none
	 *  Return value	: none
	 *  General flow	: Point destructor.
	 */
	virtual ~Point();
};

#endif /* POINT_H_ */

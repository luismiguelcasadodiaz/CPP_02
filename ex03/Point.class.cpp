#include "Point.class.hpp"


Point::Point( void ): _x(0), _y(0) //constructor by default
{
}

Point::Point(float const x, float const y ): _x(x), _y(y)//parametric constructor by default
{
}

Point::Point(const Point& other) :_x(other._x), _y(other._y)//constructor by copy
{
}

Point &  Point::operator=(const Point & other)
{

	if (this != &other)
	{
		*this = Point(other);
	}
	return *this; 
}

Point::~Point( void ) // destructor
{
}


Fixed Point::getx() const{
	return this->_x;
}

Fixed Point::gety() const{
	return this->_y;
}

// Helper functions for canonicalization

std::ostream& operator<<(std::ostream& os, const Point& obj)
{
	os << "( " << obj.getx() << " , " << obj.gety() << " )";
	return os;
};


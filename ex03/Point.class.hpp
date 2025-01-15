#ifndef Point_H
# define Point_H
#include "Fixed.class.hpp"
#include <iostream>

class Point {
public:
    Point( void ); //constructor by default
    Point(const Point& other); //constructor by copy
    Point & operator=(const Point & other);
    ~Point( void ); // destructor

    Point( float const x, float const y  ); //parametric constructor by default
    Fixed getx() const;
    Fixed gety() const;
private:
	Fixed const _x;
    Fixed const _y;




    // Helper functions for canonicalization
};

std::ostream& operator<<(std::ostream& os, const Point& obj);

#endif // Point_H

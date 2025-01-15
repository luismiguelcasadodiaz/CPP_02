#ifndef Fixed_H
# define Fixed_H

#include <iostream>
#include <cmath>
/*! \class Fixed
    \brief implements fixed point float numbers in a int

    the least 8 significance bits are reserved for the fractional part.
    we have only 24 bits for the integer part.

    the range of velues to represents fits inside

    _MIN_FIXED <= x <= _MAX_FIXED

*/
class Fixed {
public:
    Fixed( void ); //constructor by default
    Fixed(const Fixed& other); //constructor by copy
    Fixed & operator=(const Fixed & other);
    ~Fixed( void ); // destructor

    // Constructor(s)
    Fixed( int const n ); //constructor for integer
    Fixed( float const f ); //constructor for float

    // Getters
	int getRawBits( void ) const;

    // Setters
	void setRawBits( int const raw );

    // Comparison operators

    // member functions
	float toFloat ( void ) const;
	int	toInt( void ) const;


private:
	int _N;
	static const int _fracbits;
    static const int _MIN_INT_FIXED;
    static const int _MAX_INT_FIXED;
    static const float _MIN_FLT_FIXED;
    static const float _MAX_FLT_FIXED;
    static const float _EPSILON_PLUS;
    static const float _EPSILON_MINUS;


    // Helper functions for canonicalization
};

std::ostream& operator<<(std::ostream& os, const Fixed& obj);

#endif // Fixed_H

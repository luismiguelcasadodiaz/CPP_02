#ifndef Fixed_H
# define Fixed_H

#include <iostream>

class Fixed {
public:
    Fixed( void ); //constructor by default
    Fixed(const Fixed& other); //constructor by copy
    Fixed & operator=(const Fixed & other);
    ~Fixed( void ); // destructor

    // Constructor(s)
    //Fixed(${ARGS_LIST});

    // Getters
	int getRawBits( void ) const;

    // Setters
	void setRawBits( int const raw );

    // Comparison operators

    // Canonicalization function


private:
	int _N;
	static const int _fracbits;

    // Helper functions for canonicalization
};

std::ostream& operator<<(std::ostream& os, const Fixed& obj);

#endif // Fixed_H

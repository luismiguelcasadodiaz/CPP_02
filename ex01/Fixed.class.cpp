#include "Fixed.class.hpp"

int const Fixed::_fracbits = 8;
const int Fixed::_MIN_INT_FIXED = -8388607;
const int Fixed::_MAX_INT_FIXED = 8388607;
const float Fixed::_MIN_FLT_FIXED = -8388607.99609375f;
const float Fixed::_MAX_FLT_FIXED = 8388607.99609375f;



Fixed::Fixed( void ) //constructor by default
{
	std::cout << "Default constructor called for Fixed " << std::endl;
	this->setRawBits( 0 );
	return ;
}

Fixed::Fixed(const Fixed& other) //constructor by copy
{
	std::cout << "Copy constructor called for Fixed " << std::endl;
	*this = other;
	return;
}

Fixed &  Fixed::operator=(const Fixed & other)
{
	std::cout << "Copy assignment operator called for Fixed " << std::endl;
	if (this != &other)
	{
		this->_N = other.getRawBits();
	}
	return (*this); 
}

Fixed::~Fixed( void ) // destructor
{
	std::cout << "Destructor called for Fixed " << std::endl;
	return ;
}

// Constructor(s)
Fixed::Fixed( int const n ) //constructor for integer
{
	std::cout << "Int constructor called for Fixed " << std::endl;
	this->setRawBits(n << Fixed::_fracbits);
}

Fixed::Fixed( const float value ) //constructor for float
{
	std::cout << "Float constructor called for Fixed " << std::endl;
	this->setRawBits(static_cast<int>(roundf(value * (1 <<  _fracbits))));
}
//Fixed::Fixed(${ARGS_LIST});

// Getters
int Fixed::getRawBits( void ) const
{
	return this->_N;
}

// Setters
void Fixed::setRawBits( int const raw)
{
	if (Fixed::_MIN_INT_FIXED <= raw && raw <= Fixed::_MAX_INT_FIXED)
		this->_N = raw;
	else {
		std::cout << ">>>>>Overflow: "<< raw << " is not in Fixed class range" << std::endl;
		this->_N = 0;
	}
	return ;
}

// Comparison operators

// member functions
int Fixed::toInt( void ) const
{
	return (this->getRawBits() >> Fixed::_fracbits);
}

float Fixed::toFloat( void ) const
{
	return ((float)this->getRawBits() / (1 << Fixed::_fracbits));
}


// Helper functions for canonicalization

std::ostream& operator<<(std::ostream& os, const Fixed& obj)
{
	os <<  obj.toFloat();
	return os;
};


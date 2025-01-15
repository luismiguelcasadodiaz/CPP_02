#include "Fixed.class.hpp"

int const Fixed::_fracbits = 8;
const int Fixed::_MIN_INT_FIXED = -8388607;
const int Fixed::_MAX_INT_FIXED = 8388607;
const float Fixed::_MIN_FLT_FIXED = -8388607.99609375f;
const float Fixed::_MAX_FLT_FIXED = 8388607.99609375f;
const float Fixed::_EPSILON_PLUS =   0.00390625f;
const float Fixed::_EPSILON_MINUS = -0.00390625f;


Fixed::Fixed( void ) //constructor by default
{
	std::cout << "Default constructor called for Fixed " << std::endl;
	this->_N = 0;
	this->_i_am_int = true;
}

Fixed::Fixed(const Fixed& other) //constructor by copy
{
	std::cout << "Copy constructor called for Fixed " << std::endl;
	*this = other;
}

Fixed &  Fixed::operator=(const Fixed & other)
{
	std::cout << "Copy assignment operator called for Fixed " << std::endl;
	if (this != &other)
	{
		this->_N = other.getRawBits();
		this->_i_am_int = other.am_i_int();
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
	if (Fixed::_MIN_INT_FIXED <= n && n <= Fixed::_MAX_INT_FIXED)
		this->_N = (n << Fixed::_fracbits);
	else {
		std::cout << ">>>>>Overflow: "<< n << " is not in Fixed class range.";
		std::cout << "Object created with value 0." << std::endl;
		this->_N = 0;
	}
	this->_i_am_int = true;
}

Fixed::Fixed( const float f ) //constructor for float
{
	std::cout << "Float constructor called for Fixed " << std::endl;
	if (Fixed::_MIN_FLT_FIXED <= f && f <= Fixed::_MAX_FLT_FIXED)
		this->_N = static_cast<int>(roundf(f * (1 <<  _fracbits)));
	else {
		std::cout << ">>>>>Overflow: "<< f << " is not in Fixed class range. ";
		std::cout << "Object created with value 0." << std::endl;
		this->_N = 0;
	}
	this->_i_am_int = false;
}
//Fixed::Fixed(${ARGS_LIST});

// Getters
int Fixed::getRawBits( void ) const
{
	return this->_N;
}

bool Fixed::am_i_int() const{
	return (this->_i_am_int);
}

// Setters
void Fixed::setRawBits( int const raw)
{
	this->_N = raw;
}

// aritmetic operators
// Comparison operators
// PRE increment-decrement operators
// member functions
int Fixed::toInt( void ) const
{
	return (this->_N >> Fixed::_fracbits);
}

float Fixed::toFloat( void ) const
{
	return ((float)this->_N/ (1 << Fixed::_fracbits));
}


// Helper functions for canonicalization

std::ostream& operator<<(std::ostream& os, const Fixed& obj)
{
	if (obj.am_i_int())
		os <<  obj.toInt();
	else
		os << obj.toFloat();
	return os;
};


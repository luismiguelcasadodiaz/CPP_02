#include "Fixed.class.hpp"

int const Fixed::_fracbits = 8;

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
	return *this; 
}

Fixed::~Fixed( void ) // destructor
{
	std::cout << "Destructor called for Fixed " << std::endl;
	return ;
}

// Constructor(s)
//Fixed::Fixed(${ARGS_LIST});

// Getters
int Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->_N;
}

// Setters
void Fixed::setRawBits( int const raw)
{
	this->_N = raw;
	return;
}

// Comparison operators

// Canonicalization function



// Helper functions for canonicalization

std::ostream& operator<<(std::ostream& os, const Fixed& obj)
{
	os << "my attribute list" << obj.getRawBits() <<std::endl;
	return os;
};


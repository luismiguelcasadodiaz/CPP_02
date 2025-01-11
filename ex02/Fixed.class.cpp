#include "Fixed.class.hpp"

int const Fixed::_fracbits = 8;
const int Fixed::_MIN_INT_FIXED = -8388607;
const int Fixed::_MAX_INT_FIXED = 8388607;
const float Fixed::_MIN_FLT_FIXED = -8388607.99609375f;
const float Fixed::_MAX_FLT_FIXED = 8388607.99609375f;



Fixed::Fixed( void ) //constructor by default
{
	std::cout << "Default constructor called for Fixed " << std::endl;
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
Fixed::Fixed( int const n ) //constructor for integer
{
	std::cout << "Int constructor called for Fixed " << std::endl;
	
	if (Fixed::_MIN_INT_FIXED <= n && n <= Fixed::_MAX_INT_FIXED) {
		int aux = n;
		for (int i=1; i < Fixed::_fracbits; i++)
			aux *=2 ;
		this->setRawBits(aux);
	}
	else {
		std::cout << ">>>>>Overflow: "<< n << " is not in Fixed class range" << std::endl;
		this->setRawBits( 0 );
	}
	return ;
}

Fixed::Fixed( float const f ) //constructor for float
{
	std::cout << "Float constructor called for Fixed " << std::endl;

	if (Fixed::_MIN_FLT_FIXED <= f && f <= Fixed::_MAX_FLT_FIXED) {
		float frac = f;
		for (int i=1; i < Fixed::_fracbits; i++)
			frac *=2 ;
		this->setRawBits(static_cast<int>(roundf(frac)));
	}
	else {
		std::cout << ">>>>>>Overflow: "<< f << " is not in Fixed class range" << std::endl;
		this->setRawBits( 0 );
	}
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
	this->_N = raw;
	return ;
}

// Comparison operators

// member functions
int Fixed::toInt( void ) const
{
	int aux = this->getRawBits();
	for (int i=1; i < Fixed::_fracbits; i++)
		aux /=2 ;
	return aux;
}

float Fixed::toFloat( void ) const
{
	float aux = static_cast<float>(this->getRawBits());
	for (int i=1; i < Fixed::_fracbits; i++)
		aux /=2 ;
	return aux;
}


// Helper functions for canonicalization

std::ostream& operator<<(std::ostream& os, const Fixed& obj)
{
	os <<  obj.toFloat();
	return os;
};


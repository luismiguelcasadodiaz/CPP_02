#include "Fixed.class.hpp"

int const Fixed::_fracbits = 8;
const int Fixed::_MIN_INT_FIXED = -8388607;
const int Fixed::_MAX_INT_FIXED = 8388607;
const float Fixed::_MIN_FLT_FIXED = -8388607.99609375f;
const float Fixed::_MAX_FLT_FIXED = 8388607.99609375f;
const float Fixed::_EPSILON_PLUS = 0.99609375f;
const float Fixed::_EPSILON_MINUS = -0.99609375f;



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
Fixed::Fixed( int const n ) //constructor for integer
{
	std::cout << "Int constructor called for Fixed " << std::endl;
	this->setRawBits(n << Fixed::_fracbits);
}

Fixed::Fixed( float const f ) //constructor for float
{
	std::cout << "Float constructor called for Fixed " << std::endl;
	this->setRawBits(static_cast<int>(roundf(f * (1 <<  _fracbits))));
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
	if ((Fixed::_MIN_INT_FIXED << Fixed::_fracbits) <= raw && raw <= (Fixed::_MAX_INT_FIXED << Fixed::_fracbits))
		this->_N = raw;
	else {
		std::cout << ">>>>>Overflow: "<< raw << " is not in Fixed class range" << std::endl;
		this->_N = 0;
	}
	return ;
}
    
// aritmetic operators
Fixed Fixed::operator+(const Fixed & other){
	bool overflow = true;
	if ((this->toFloat() >= 0) && (_MAX_INT_FIXED - this->_N)  > other.getRawBits())
		overflow = false;
	if ((this->toFloat() < 0) && (_MIN_INT_FIXED - this->_N) < other.getRawBits())
		overflow = false;
	if (overflow) {
		std::cout << "overflow ==> " << this->toInt() << " plus " ;
		std::cout << other.toInt() << " does not fit in Fixed Class" << std::endl;
		return this->toFloat();
		}
	return (this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed & other){
	if ((this->_N < 0) && (_MIN_INT_FIXED - this->_N) < other.getRawBits() ) {
		std::cout << "overflow ==> " << this->toInt() << " minus " ;
		std::cout << other.toInt() << " does not fit in Fixed Class" << std::endl;
		return this->_N;
	}
	return (this->toFloat() - other.toFloat());
}


Fixed Fixed::operator*(const Fixed & other){
	if (Fixed::_abs(Fixed::_MAX_INT_FIXED / this->toFloat()) < Fixed::_abs(other.toFloat())) {
		std::cout << "overflow ==> " << this->toInt() << " multiplied by " ;
		std::cout << other.toInt() << " does not fit in Fixed Class" << std::endl;
		return this->_N;
	}
	return (this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed & other){
	float zero_check = other.toFloat() - 0;
	float magnitud_check = (Fixed::_MAX_INT_FIXED * other.toFloat()) - this->toFloat();

	if (Fixed::_EPSILON_MINUS <= zero_check  && zero_check  <= Fixed::_EPSILON_PLUS){
		std::cout << "overflow ==> " << this->toInt() << " divided by " ;
		std::cout << "zero does not fit in Fixed Class" << std::endl;
		return this->_N;
	}
	else if (Fixed::_EPSILON_MINUS <= magnitud_check && magnitud_check <= Fixed::_EPSILON_PLUS){
		std::cout << "overflow ==> " << this->toInt() << " divided by " ;
		std::cout << other.toInt() << " does not fit in Fixed Class" << std::endl;
		return this->_N;
	}
	return (this->toFloat() / other.toFloat());
}


// Comparison operators
bool Fixed::operator>(const Fixed & other){
	return (this->toFloat() > other.toFloat());
}
bool Fixed::operator<(const Fixed & other){
	return (this->toFloat() < other.toFloat());
}
bool Fixed::operator>=(const Fixed & other){
	return ((this->toFloat() > other.toFloat()) || ((Fixed::_EPSILON_MINUS <= (this->toFloat() - other.toFloat())) && ((this->toFloat() > other.toFloat()) <= Fixed::_EPSILON_PLUS)));
}
bool Fixed::operator<=(const Fixed & other){
	return ((this->toFloat() < other.toFloat()) || ((Fixed::_EPSILON_MINUS <= (this->toFloat() - other.toFloat())) && ((this->toFloat() > other.toFloat()) <= Fixed::_EPSILON_PLUS)));
}

bool Fixed::operator==(const Fixed & other){
	return (((Fixed::_EPSILON_MINUS <= (this->toFloat() - other.toFloat())) && ((this->toFloat() > other.toFloat()) <= Fixed::_EPSILON_PLUS)));
}

bool Fixed::operator!=(const Fixed & other){
	return ((( (this->toFloat() - other.toFloat()) < Fixed::_EPSILON_MINUS ) || ( Fixed::_EPSILON_PLUS < (this->toFloat() > other.toFloat()))));
}
/*
// increment-decrement operators
Fixed & Fixed::operator++( void ){

	return ;
}

Fixed   Fixed::operator++( int n ){
	return ;
}

*/
// member functions
int Fixed::toInt( void ) const
{
	return ((int)(roundf((float)this->_N / (1 << this->_fracbits))));
}

float Fixed::toFloat( void ) const
{
	return ((float)this->getRawBits() / (1 << Fixed::_fracbits));
}
/*
	// class functions
static Fixed Fixed::min(Fixed & a, Fixed & b){

	return ;
}
static Fixed Fixed::min(Fixed const & a, Fixed const & b){

	return ;
}
static Fixed Fixed::max(Fixed & a, Fixed & b){

	return ;
}
static Fixed Fixed::max(Fixed const & a, Fixed const & b){

	return ;
}

*/
// Helper functions for canonicalization

float Fixed::_abs(const float value) const{
	if (value < 0)
		return (-value);
	return (value);
}

std::ostream& operator<<(std::ostream& os, const Fixed& obj)
{
	os <<  obj.toFloat();
	return os;
};


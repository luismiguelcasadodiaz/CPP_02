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
	//std::cout << "Copy constructor called for Fixed " << std::endl;
	*this = other;
}

Fixed &  Fixed::operator=(const Fixed & other)
{
	//std::cout << "Copy assignment operator called for Fixed " << std::endl;
	if (this != &other)
	{
		this->_N= other.getRawBits();
		this->_i_am_int = other.am_i_int();
	}
	return (*this); 
}

Fixed::~Fixed( void ) // destructor
{
	//std::cout << "Destructor called for Fixed " << std::endl;
	return ;
}

// Constructor(s)
Fixed::Fixed( int const n ) //constructor for integer
{
	//std::cout << "Int constructor called for Fixed " << std::endl;
	if (Fixed::_MIN_INT_FIXED <= n && n <= Fixed::_MAX_INT_FIXED)
		this->_N = (n << Fixed::_fracbits);
	else {
		std::cout << ">>>>>Overflow: "<< n << " is not in Fixed class range. Object created with value 0." << std::endl;
		this->_N = 0;
	}
	this->_i_am_int = true;
}

Fixed::Fixed( float const f ) //constructor for float
{
	//std::cout << "Float constructor called for Fixed " << std::endl;
	if (Fixed::_MIN_FLT_FIXED <= f && f <= Fixed::_MAX_FLT_FIXED)
		this->_N = static_cast<int>(roundf(f * (1 <<  _fracbits)));
	else {
		std::cout << ">>>>>Overflow: "<< f << " is not in Fixed class range. Object created with value 0." << std::endl;
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
Fixed Fixed::operator+(const Fixed & other) const {
	bool overflow = true;
	if ((this->toFloat() >= 0) && (_MAX_INT_FIXED - this->toFloat())  > other.toFloat())
		overflow = false;
	if ((this->toFloat() < 0) && (_MIN_INT_FIXED - this->toFloat()) < other.toFloat())
		overflow = false;
	if (overflow) {
		std::cout << "overflow ==> " << this->toInt() << " plus " ;
		std::cout << other.toInt() << " does not fit in Fixed Class" << std::endl;
		return this->toFloat();
		}
	return (this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed & other) const {
	if ((this->toFloat() < 0) && (_MIN_INT_FIXED - this->toFloat()) < other.toFloat() ) {
		std::cout << "overflow ==> " << this->toInt() << " minus " ;
		std::cout << other.toInt() << " does not fit in Fixed Class" << std::endl;
		return this->toFloat();
	}
	return (this->toFloat() - other.toFloat());
}


Fixed Fixed::operator*(const Fixed & other) const {
	if (Fixed::_abs(Fixed::_MAX_INT_FIXED / this->toFloat()) < Fixed::_abs(other.toFloat())) {
		std::cout << "overflow ==> " << this->toInt() << " multiplied by " ;
		std::cout << other.toInt() << " does not fit in Fixed Class" << std::endl;
		return this->toFloat();
	}
	return (this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed & other) const {
	if (other.toFloat() == 0){
		std::cout << "overflow ==> " << this->toInt() << " divided by " ;
		std::cout << "zero does not fit in Fixed Class" << std::endl;
		return this->toFloat();
	}
	else if ( (this->toFloat() < (Fixed::_MIN_INT_FIXED * other.toFloat())) || ((Fixed::_MAX_INT_FIXED * other.toFloat()) < this->toFloat())) {
		std::cout << "overflow ==> " << this->toInt() << " divided by " ;
		std::cout << other.toInt() << " does not fit in Fixed Class" << std::endl;
		return this->toFloat();
	}
	return (this->toFloat() / other.toFloat());
}


// Comparison operators
bool Fixed::operator>(const Fixed & other) const {
	return (this->toFloat() > other.toFloat());
}
bool Fixed::operator<(const Fixed & other) const {
	return (this->toFloat() < other.toFloat());
}
bool Fixed::operator>=(const Fixed & other) const {
	return ((this->toFloat() > other.toFloat()) || ((Fixed::_EPSILON_MINUS <= (this->toFloat() - other.toFloat())) && ((this->toFloat() - other.toFloat()) <= Fixed::_EPSILON_PLUS)));
}
bool Fixed::operator<=(const Fixed & other) const {
	float lhs = this->toFloat();
	float rhs = other.toFloat();
	float dif = this->toFloat() - other.toFloat();

	return (( lhs < rhs) || ((Fixed::_EPSILON_MINUS <= dif) && (dif <= Fixed::_EPSILON_PLUS)));
}

bool Fixed::operator==(const Fixed & other) const {
	return (((Fixed::_EPSILON_MINUS <= (this->toFloat() - other.toFloat())) && ((this->toFloat() > other.toFloat()) <= Fixed::_EPSILON_PLUS)));
}

bool Fixed::operator!=(const Fixed & other) const {
	return ((( (this->toFloat() - other.toFloat()) < Fixed::_EPSILON_MINUS ) || ( Fixed::_EPSILON_PLUS < (this->toFloat() > other.toFloat()))));
}

// PRE increment-decrement operators
Fixed & Fixed::operator++( void ){
	//std::cout << " PRE ++increment ";
	this->setRawBits(static_cast<int>(roundf((this->toFloat() + Fixed::_EPSILON_PLUS) * (1 <<  _fracbits) )));
	this->_i_am_int =false;
	return *this;
}

Fixed & Fixed::operator--( void ){
	//std::cout << " PRE --decrement ";
	this->setRawBits(static_cast<int>(roundf((this->toFloat() + Fixed::_EPSILON_MINUS) * (1 <<  _fracbits) )));
	this->_i_am_int =false;
	return *this;
}
// POST increment-decrement operators
Fixed   Fixed::operator++( int n ){
	//std::cout << " POST  increment++ ";
	Fixed old = *this;
	if (n == 0) {operator++();}
	return old;
}

Fixed   Fixed::operator--( int n ){
	//std::cout << " POST decrement-- ";
	Fixed old = *this;
	if (n == 0) {operator--();}
	return old;
}

// member functions
int Fixed::toInt( void ) const
{
	return ((int)(roundf((float)this->_N / (1 << Fixed::_fracbits))));
}

float Fixed::toFloat( void ) const
{
	return ((float)this->_N / (1 << Fixed::_fracbits));
}

	// class functions
Fixed Fixed::min(Fixed & a, Fixed & b) {
	if (a.toFloat() < b.toFloat())
		return (a);
	else
		return (b);
}
Fixed Fixed::min(Fixed const & a, Fixed const & b) {
	if (a.toFloat() < b.toFloat())
		return (a);
	else
		return (b);
}
Fixed Fixed::max(Fixed & a, Fixed & b) {
	if (a.toFloat() > b.toFloat())
		return (a);
	else
		return (b);
}
Fixed Fixed::max(Fixed const & a, Fixed const & b) {
	if (a.toFloat() > b.toFloat())
		return (a);
	else
		return (b);
}


// Helper functions for canonicalization

float Fixed::_abs(const float value) const{
	if (value < 0)
		return (-value);
	return (value);
}

std::ostream& operator<<(std::ostream& os, const Fixed& obj)
{
	if (obj.am_i_int())
		os <<  obj.toInt();
	else
		os << obj.toFloat();
	return os;
};



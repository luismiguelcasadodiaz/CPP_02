#include "${CLASS_NAME}.class.hpp"

int const ${CLASS_NAME}::_fracbits = 8;

${CLASS_NAME}::${CLASS_NAME}( void ) //constructor by default
{
	std::cout << "Default constructor called for ${CLASS_NAME} " << std::endl;
	return ;
}

${CLASS_NAME}::${CLASS_NAME}(const ${CLASS_NAME}& other) //constructor by copy
{
	std::cout << "Copy constructor called for ${CLASS_NAME} " << std::endl;
	*this = other;
	return;
}

${CLASS_NAME} &  ${CLASS_NAME}::operator=(const ${CLASS_NAME} & other)
{
	std::cout << "Copy assignment operator called for ${CLASS_NAME} " << std::endl;
	if (this != &other)
	{
		this->_N = other.getRawBits();
	}
	return *this; 
}

${CLASS_NAME}::~${CLASS_NAME}( void ) // destructor
{
	std::cout << "Destructor called for ${CLASS_NAME} " << std::endl;
	return ;
}

// Constructor(s)
//${CLASS_NAME}::${CLASS_NAME}(${ARGS_LIST});

// Getters
int ${CLASS_NAME}::getRawBits( void ) const
{
	return this->_N;
}

// Setters

// Comparison operators

// Canonicalization function



// Helper functions for canonicalization

std::ostream& operator<<(std::ostream& os, const ${CLASS_NAME}& obj)
{
	os << "my attribute list" << obj.getRawBits() <<std::endl;
	return os;
};


#include "${CLASS_NAME}.class.hpp"

${CLASS_NAME}::${CLASS_NAME}( void ) //constructor by default
{
	std::cout << "Default constructor called for ${CLASS_NAME} " << std::endl;
	return ;
}

${CLASS_NAME}::${CLASS_NAME}(const ${CLASS_NAME}& other) //constructor by copy
{
	*this = &other;
	return;
}

${CLASS_NAME}::${CLASS_NAME}& operator=(const ${CLASS_NAME}& other)
{
	if (this != other)
	{
		this->_N = other.getN();
	}
	return *this; 
}

${CLASS_NAME}~${CLASS_NAME}( void ) // destructor
{
	std::cout << "Destructor called for ${CLASS_NAME} " << std:endl;
	return ;
}

// Constructor(s)
//${CLASS_NAME}::${CLASS_NAME}(${ARGS_LIST});

// Getters

// Setters

// Comparison operators

// Canonicalization function
    void canonicalize();


private:

// Helper functions for canonicalization
};

std::ostream& operator<<(std::ostream& os, const ${CLASS_NAME}& obj)
{
	os << "my attribute list" << std::endl;
	return &os;
};


#ifndef ${CLASS_NAME}_H
# define ${CLASS_NAME}_H

#include <iostream>

class ${CLASS_NAME} {
public:
    ${CLASS_NAME}( void ); //constructor by default
    ${CLASS_NAME}(const ${CLASS_NAME}& other); //constructor by copy
    ${CLASS_NAME}& operator=(const ${CLASS_NAME}& other);
    ~${CLASS_NAME}( void ); // destructor

    // Constructor(s)
    //${CLASS_NAME}(${ARGS_LIST});

    // Getters

    // Setters

    // Comparison operators

    // Canonicalization function
    void canonicalize();


private:

    // Helper functions for canonicalization
};

std::ostream& operator<<(std::ostream& os, const ${CLASS_NAME}& obj);

#endif // ${CLASS_NAME}_H

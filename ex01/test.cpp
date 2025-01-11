#include <iostream>
#include <cmath>

void myfunc(float const f) {
    std::cout << "f              =>" << f << std::endl; 
    std::cout << "(int)f         =>" <<static_cast<int>(f) << std::endl; 
    std::cout << "roundf(f)      =>" << roundf(f) << std::endl; 
    std::cout << "(int)roundf(f) =>" << static_cast<int>(roundf(f)) << std::endl; 
	std::cout << "--------------------------------------" << std::endl;
}

int main() {
	std::cout << " passing -16777217.0f print helper function " << std::endl;
    myfunc(-16777217.0f); 
	std::cout << " passing -42.42f print helper function " << std::endl;
    myfunc(-42.42f); 
	std::cout << " passing -128.128f print helper function " << std::endl;
    myfunc(-128.128f); 
    return 0;
}

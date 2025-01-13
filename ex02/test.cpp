#include <iostream>
int main (void)
{
	int a = 4294967291;
	int b = 4294967292;
	int c = a + b;
	float f = 1.5f;

	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << c << std::endl;
	std::cout << f++ << std::endl;
	std::cout << f << std::endl;
	std::cout << --f << std::endl;
	return (0);
}

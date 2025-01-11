#include <iostream>
int main (void)
{
	int a = 4294967291;
	int b = 4294967292;
	int c = a + b;

	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << c << std::endl;
	return (0);
}

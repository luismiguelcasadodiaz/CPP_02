/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 15:02:55 by luicasad          #+#    #+#             */
/*   Updated: 2025/01/11 14:38:10 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Fixed.class.hpp"
#include <iostream>

int main( void )
{
	Fixed a;
	Fixed const b( 10 );
	Fixed const c( 42.42f );
	Fixed const d( b );

	a = Fixed( 1234.4321f );
	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;

	// LMCD tests int constructor
	std::cout <<" ---------------- int tests -------------" << std::endl;
	a = Fixed( 8388606);
	std::cout << "8388606 is " << a << std::endl;
	std::cout << "8388606 is " << a.toInt() << " as integer" << std::endl;
	a = Fixed( 8388607);
	std::cout << "8388607 is " << a << std::endl;
	std::cout << "8388607 is " << a.toInt() << " as integer" << std::endl;
	a = Fixed( 8388608);
	std::cout << "8388608 is " << a << std::endl;
	std::cout << "8388608 is " << a.toInt() << " as integer" << std::endl;
	a = Fixed( -8388606);
	std::cout << "-8388606 is " << a << std::endl;
	std::cout << "-8388606 is " << a.toInt() << " as integer" << std::endl;
	a = Fixed( -8388607);
	std::cout << "-8388607 is " << a << std::endl;
	std::cout << "-8388607 is " << a.toInt() << " as integer" << std::endl;
	a = Fixed( -83886068);
	std::cout << "-8388608 is " << a << std::endl;
	std::cout << "-8388608 is " << a.toInt() << " as integer" << std::endl;
	// LMCD test float constructor
	std::cout <<" ---------------- float tests -------------" << std::endl;
	a = Fixed( 8388607.99609375f);
	std::cout << "8388607.99609375fis " << a << std::endl;
	std::cout << "8388607.99609375f is " << a.toInt() << " as integer" << std::endl;
	a = Fixed( 8388607.99609375f);
	std::cout << "8388607.99609375f is " << a << std::endl;
	std::cout << "8388607.99609375f is " << a.toInt() << " as integer" << std::endl;
	a = Fixed( 8388607.99609375f);
	std::cout << "16777217.0f is " << a << std::endl;
	std::cout << "16777217.0f is " << a.toInt() << " as integer" << std::endl;
	a = Fixed( -8388607.99609375f);
	std::cout << "-8388607.99609375f is " << a << std::endl;
	std::cout << "-8388607.99609375f is " << a.toInt() << " as integer" << std::endl;
	a = Fixed( -8388607.99609375f);
	std::cout << "-8388607.99609375f is " << a << std::endl;
	std::cout << "-8388607.99609375fis " << a.toInt() << " as integer" << std::endl;
	a = Fixed( -8388607.99609375f);
	std::cout << "-8388607.99609375f is " << a << std::endl;
	std::cout << "-8388607.99609375f is " << a.toInt() << " as integer" << std::endl;
	
	return 0;
}

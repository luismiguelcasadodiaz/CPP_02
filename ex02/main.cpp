/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 15:02:55 by luicasad          #+#    #+#             */
/*   Updated: 2025/01/12 11:14:36 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Fixed.class.hpp"
#include <iostream>

int main( void ) {
//	Fixed a;
//	Fixed const b( Fixed( 5.05f ) + Fixed( 2 ) );

//	std::cout << a << std::endl;
//	std::cout << ++a << std::endl;
//	std::cout << a << std::endl;
//	std::cout << a++ << std::endl;
//	std::cout << a << std::endl;
//	std::cout << b << std::endl;
//	std::cout << Fixed::max( a, b ) << std::endl;
//
	Fixed a = Fixed( 5 );
	Fixed b = Fixed( 2 );
	Fixed c;


	std::cout << "a=" << a.toInt() << std::endl;
	std::cout << "b=" << b << std::endl;
	std::cout << "c=" << c << std::endl;
	c = a + b;
	std::cout << "c= a + b =" << c << std::endl;
	c = a - b;
	std::cout << "c= a - b =" << c << std::endl;
	c = a * b;
	std::cout << "c= a * b =" << c << std::endl;
	c = a / b;
	std::cout << "c= a / b =" << c << std::endl;

	Fixed aa = Fixed( 8388607 );
	Fixed bb = Fixed( 2 );
	Fixed cc;
	std::cout << "aa=" << aa.toInt() << std::endl;
	std::cout << "bb=" << bb << std::endl;
	std::cout << "cc=" << cc << std::endl;
	cc = aa + bb;
	std::cout << "cc= aa + bb =" << cc << std::endl;
	cc = aa - bb;
	std::cout << "cc= aa - bb =" << cc << std::endl;
	cc = aa * bb;
	std::cout << "cc= aa * bb =" << cc << std::endl;
	cc = aa / bb;
	std::cout << "c= aa / bb =" << cc << std::endl;
	return 0;
}

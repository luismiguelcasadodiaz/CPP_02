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
	
	
	std::cout << "-------------------------- Aritmetic operations" << std::endl;
	
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

	std::cout << "-------------------------- Aritmetic operations WITH OVERFLOW" << std::endl<< std::endl<< std::endl;
	Fixed zz = Fixed( 8388610 );
	Fixed aa = Fixed( 8388605 );
	Fixed bb = Fixed(  200000 );
	Fixed ee = Fixed( 1.0f );
	Fixed ff = Fixed( 1.0f + 0.00000005f);
	Fixed gg = Fixed( 1.0f + 0.00000015f);
	Fixed hh = Fixed( 1.0f + 0.00000115f);
	Fixed ii = Fixed( 1.0f + 0.00000915f);
	Fixed jj = Fixed( 1.0f + 0.00009915f);
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
	std::cout << "cc= aa / bb =" << cc << std::endl;

	std::cout << "-------------------------- comparison operators" << std::endl<< std::endl<< std::endl;
	std::cout << aa << " <  " << bb << " = " << (aa <  bb) << std::endl;
	std::cout << aa << " <= " << bb << " = " << (aa <= bb) << std::endl;
	std::cout << aa << " >  " << bb << " = " << (aa >  bb) << std::endl;
	std::cout << aa << " >= " << bb << " = " << (aa >= bb) << std::endl;
	std::cout << ee << " >= " << ff << " = " << (ee >= ff) << std::endl;
	std::cout << ff << " ff==ee " << ee << " = " << (ff == ee) << std::endl;
	std::cout << gg << " gg==ee " << ee << " = " << (gg == ee) << std::endl;
	std::cout << hh << " hh==ee " << ee << " = " << (hh == ee) << std::endl;
	std::cout << ii << " ii==ee " << ee << " = " << (ii != ee) << std::endl;
	std::cout << jj << " jj==ee " << ee << " = " << (jj != ee) << std::endl;



	std::cout << "-------------------------- MAX_MIN" << std::endl<< std::endl<< std::endl<< std::endl;
	std::cout << "Max (" << a <<" , "<< b << ") = " << Fixed::max(a, b) << std::endl;
	std::cout << "Min (" << a <<" , "<< b << ") = " << Fixed::min(a, b) << std::endl;
	std::cout << "Max (" << a <<" , 42) = " << Fixed::max(a, 42) << std::endl;
	std::cout << "Max (" << a <<" , 42.5f) = " << Fixed::max(a, 42.5f) << std::endl;
	std::cout << "Min (" << a <<" , 42) = " << Fixed::min(a, 42) << std::endl;
	std::cout << "Min (" << a <<" , 42.5f) = " << Fixed::min(a, 42.5f) << std::endl;
	return 0;
}

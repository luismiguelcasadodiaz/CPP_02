/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 15:02:55 by luicasad          #+#    #+#             */
/*   Updated: 2025/01/14 16:22:21 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "Fixed.class.hpp"
#include <iostream>

int main( void ) {
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	
	std::cout << "-------------------------- Aritmetic operations" << std::endl;
	
	Fixed c;

	c = a;
	c++;
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
	Fixed aa = Fixed( 8388607 );
	Fixed bb = Fixed(  200000 );

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

	Fixed ee = Fixed( 1.00000000000f);
	Fixed ff = Fixed( 1.001950000000f);
	Fixed gg = Fixed( 1.001960000000f);
	Fixed hh = Fixed( 1.001970000000f);
	Fixed ii = Fixed( 1.001980000000f);
	Fixed jj = Fixed( 1.002000000000f);
	std::cout << ee.toFloat() << " >= " << ff.toFloat() << " = " << (ee >= ff) << std::endl;
	std::cout << ff.toFloat() << " ff==ee " << ee << " = " << (ff == ee) << std::endl;
	std::cout << gg.toFloat() << " gg==ee " << ee << " = " << (gg == ee) << std::endl;
	std::cout << hh.toFloat() << " hh==ee " << ee << " = " << (hh == ee) << std::endl;
	std::cout << ii.toFloat() << " ii==ee " << ee << " = " << (ii == ee) << std::endl;
	std::cout << jj.toFloat() << " jj==ee " << ee << " = " << (jj == ee) << std::endl;
	int idx = 0;
	Fixed initi = Fixed(1.0000000f);
	Fixed limit = Fixed(1.0002000f);
	Fixed incre = Fixed(1.0000300f);
	Fixed refer = Fixed(1.0001000f );
	for (Fixed i = initi;i <=  limit;i++)
	{
		std::cout << i << "loop "<< idx++ << " i==ee " << refer << " = " << (i == refer) << std::endl;
	}
	




	std::cout << "-------------------------- MAX_MIN" << std::endl<< std::endl<< std::endl<< std::endl;
	std::cout << "Max (" << a <<" , "<< b << ") = " << Fixed::max(a, b) << std::endl;
	std::cout << "Min (" << a <<" , "<< b << ") = " << Fixed::min(a, b) << std::endl;
	std::cout << "Max (" << a <<" , 42) = " << Fixed::max(a, 42) << std::endl;
	std::cout << "Max (" << a <<" , 42.5f) = " << Fixed::max(a, 42.5f) << std::endl;
	std::cout << "Min (" << a <<" , 42) = " << Fixed::min(a, 42) << std::endl;
	std::cout << "Min (" << a <<" , 42.5f) = " << Fixed::min(a, 42.5f) << std::endl;

	std::cout << "-------------------------- PRE-POST AUTO IN/DE CREMENT" << std::endl<< std::endl<< std::endl<< std::endl;
	std::cout << "bb=" << bb <<" ,bb++ ==> bb= "<< bb++  << std::endl;
	std::cout << "bb=" << bb <<" ,bb++ ==> bb= "<< bb++  << std::endl;
	std::cout << "bb=" << bb <<" ,bb++ ==> bb= "<< bb++  << std::endl;
	std::cout << "bb=" << bb <<" ,--bb ==> bb= "<< --bb  << std::endl;
	std::cout << "bb=" << bb <<" ,--bb ==> bb= "<< --bb  << std::endl;
	std::cout << "bb=" << bb <<" ,--bb ==> bb= "<< --bb  << std::endl;
		
	std::cout << "aa=" << aa <<" ,aa++ ==> aa= "<< aa++  << std::endl;
	std::cout << "aa=" << aa <<" ,aa++ ==> aa= "<< aa++  << std::endl;
	std::cout << "aa=" << aa <<" ,aa++ ==> aa= "<< aa++  << std::endl;
	std::cout << "aa=" << aa <<" ,aa++ ==> aa= "<< aa++  << std::endl;
	std::cout << "aa=" << aa <<" ,aa++ ==> aa= "<< aa++  << std::endl;
	std::cout << "aa=" << aa <<" ,aa++ ==> aa= "<< aa++  << std::endl;
	std::cout << "aa=" << aa <<" ,--aa ==> aa= "<< --aa  << std::endl;
	std::cout << "aa=" << aa <<" ,--aa ==> aa= "<< --aa  << std::endl;
	std::cout << "aa=" << aa <<" ,--aa ==> aa= "<< --aa  << std::endl;

	return 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 15:02:55 by luicasad          #+#    #+#             */
/*   Updated: 2025/01/04 15:02:57 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Point.class.hpp"

//bsp returns true if point d is inside the triangle abc
bool bsp(Point const a, Point const b, Point const c, Point const d);

int main( void)
{

    Point aaa = Point( 2.0f, 1.0f );
    Point bbb = Point( 4.0f, 1.0f );
    Point ccc = Point( 3.0f, 5.0f );
    Point yes = Point( 3.0f, 3.0f );
    Point noo = Point( 5.0f, 5.0f );

    std::cout << "Does the triangle made of the point aaa=" << aaa;
    std::cout << " , the point bbb=" << bbb;
    std::cout << " and the point ccc=" << ccc;
    std::cout << " contains the point xxx=" << yes << "?";
    std::cout << (bsp(aaa, bbb, ccc, yes) ? "YES" : "NO") << std::endl;
    std::cout << "Does the triangle made of the point aaa=" << aaa;
    std::cout << " , the point bbb=" << bbb;
    std::cout << " and the point ccc=" << ccc;
    std::cout << " contains the point xxx=" << noo << "?";
    std::cout << (bsp(aaa, bbb, ccc, noo) ? "YES" : "NO") << std::endl;
}
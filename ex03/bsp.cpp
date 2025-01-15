/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 15:05:47 by luicasad          #+#    #+#             */
/*   Updated: 2025/01/14 17:11:13 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.class.hpp"
//https://www.omnicalculator.com/es/matematicas/calculadora-del-area-de-un-triangulo-con-coordenadas
//Please pay special attention to the factor order in the subtractions.
static float area(Point const a, Point const b, Point const c)
{
	float one = Fixed(a.getx() * (b.gety()- c.gety())).toFloat();
    float two = Fixed(b.getx() * (c.gety()- a.gety())).toFloat();
    float thr = Fixed(c.getx() * (a.gety()- b.gety())).toFloat();
    float tot = (one + two + thr);
    if (tot > 0)
        return (tot/ 2.0f);
    return (-tot/ 2.0f);
}
//I return at >= a1 + a2 + a3 instead at == a1 + a2 + a3 cause the FIxed class precision is not the best one.
bool bsp(Point const a, Point const b, Point const c, Point const d){
    if ( a == d || b == d || c == d)
        return (false);
    float at = area(a, b, c);
    float a1 = area(d, b, c);
    float a2 = area(a, d, c);
    float a3 = area(a, b, d);
    //std::cout << " at=" <<at << " a1="<< a1<< " a2=" << a2<< " a3=" << a3 << std::endl;
    return (at >= a1 + a2 + a3);
}

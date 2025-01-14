/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <luicasad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 15:05:47 by luicasad          #+#    #+#             */
/*   Updated: 2025/01/04 15:05:51 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.class.hpp"


bool bsp(Point const a, Point const b, Point const c, Point const d){

    return ((a.getx() == b.getx()) || (c.getx() == d.getx()));
}

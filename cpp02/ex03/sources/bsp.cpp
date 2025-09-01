/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 14:30:04 by mconreau          #+#    #+#             */
/*   Updated: 2023/05/09 22:08:23 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

static Fixed isOnLine(const Point a, const Point b, const Point point);
static Fixed getArea(const Point a, const Point b, const Point c);

bool	bsp(const Point a, const Point b, const Point c, const Point point)
{
	return (isOnLine(a, b, point) == false
		&& isOnLine(b, c, point) == false
		&& isOnLine(a, c, point) == false
		&& (getArea(a, b, c).abs()
		== (getArea(point, a, b).abs()
		+ getArea(point, b, c).abs()
		+ getArea(point, c, a).abs()))
		? true : false);
}

static Fixed isOnLine(const Point a, const Point b, const Point point)
{
	return ((((point.getX().abs() - a.getX().abs())
		* (b.getY().abs() - a.getY().abs())
		- (point.getY().abs() - a.getY().abs())
		* (b.getX().abs() - point.getX().abs())) != 0)
		? false : true);
}

static Fixed getArea(const Point a, const Point b, const Point c)
{
	return (((a.getX() * (b.getY() - c.getY()))
		+ (b.getX() * (c.getY() - a.getY()))
		+ (c.getX() * (a.getY() - b.getY()))) / 2);
}

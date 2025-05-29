/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 23:28:35 by mconreau          #+#    #+#             */
/*   Updated: 2024/03/26 21:10:49 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void) :
	_x(0), _y(0)
{
}

Point::Point(const float x, const float y) :
	_x(x), _y(y)
{
}

Point::Point(const Point &src)
{
	*this = src;
}

Point::~Point(void)
{
}

Fixed
Point::getX(void) const
{
	return (this->_x);
}

Fixed
Point::getY(void) const
{
	return (this->_y);
}

Point&
Point::operator=(const Point& rhs)
{
	const_cast<Fixed&>(this->_x) = rhs.getX();
	const_cast<Fixed&>(this->_y) = rhs.getY();
	return (*this);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 23:28:41 by mconreau          #+#    #+#             */
/*   Updated: 2024/03/26 21:04:54 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Fixed.hpp"
#include <iostream>

class   Point
{
	private  :
		const Fixed			_x;
		const Fixed			_y;

    public   :
    						Point(void);
							Point(const float x, const float y);
							Point(const Point& src);
							~Point(void);

		Fixed				getX(void) const;
		Fixed				getY(void) const;

		Point&				operator=(const Point& rhs);
};

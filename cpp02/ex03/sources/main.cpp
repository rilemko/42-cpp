/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 20:01:04 by mconreau          #+#    #+#             */
/*   Updated: 2024/03/26 21:11:00 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <iostream>

bool	bsp(const Point, const Point, const Point, const Point);

int
main(void)
{
	Point a(0, 0);
	Point b(20, 0);
	Point c(-30, 30);

	Point p(-15.0f, 15.0f);

	std::cout << "Point is in tiangle : "
		<< (bsp(a, b, c, p) == true ? "true" : "false") << std::endl;
}

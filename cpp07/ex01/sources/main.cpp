/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 14:27:41 by mconreau          #+#    #+#             */
/*   Updated: 2023/09/30 16:40:21 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int		main()
{
	// 1. Create an array of 4 elements, and iterate over them to display
	// them.

	std::cout
		<< "1. Create an array of 4 elements, and iterate over them to display "
		<< "them."
		<< std::endl << std::endl;

	int			tab1[] 	= {1, 2, 3, 4};

	::iter(tab1, 4, display);

	// 2. Iterate twice over the array incrementing each element, then
	// redisplays them.

	std::cout << std::endl
		<< "2. Iterate twice over the array incrementing each element, then "
		<< "redisplays them."
		<< std::endl << std::endl;

	::iter(tab1, 4, increment);
	::iter(tab1, 4, increment);
	::iter(tab1, 4, display);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 04:18:26 by ael-khni          #+#    #+#             */
/*   Updated: 2023/09/19 08:50:11 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iomanip>
#include <sstream>
#include "Array.hpp"

#define SIZE 		10
#define TOSTR(x) 	static_cast<const std::ostringstream&>((std::ostringstream() << std::dec << x)).str()

int main()
{
	// 1. Creates an array of int and an array of std::string of SIZE elements
	// each, then displays them by [] accessor.

	std::cout
		<< "1. Creates an array of int and an array of std::string of SIZE "
		<< "elements each, then displays them by [] accessor."
		<< std::endl << std::endl;

	Array<int> 			array0;
    Array<int> 			array1(SIZE);
	Array<std::string> 	array2(SIZE);

	for(int i = 0; i < SIZE; i++)
		array1[i] = i;
	std::cout << array1 << std::endl;
	
	for(int i = 0; i < SIZE; i++)
		array2[i] = TOSTR("str" + TOSTR(i));
	std::cout << array2 << std::endl;

	// 2. Modify the 3rd element of the 2 arrays by [] accessor, then
	// redisplay them by [] accessor.

	std::cout << std::endl
		<< "2. Modify the 3rd element of the 2 arrays by [] accessor, then "
		<< "redisplay them by [] accessor."
		<< std::endl << std::endl;

	array1[2] = 42;
	array2[2] = "~42~";
	std::cout << array1 << std::endl;
	std::cout << array2 << std::endl;

	// 3. Try to access out of bound element to throw the std::exception.

	std::cout << std::endl
		<< "3. Try to access out of bound element to throw the std::exception."
		<< std::endl << std::endl;

	try {
		array0[0] = 42;
	} 
	catch (std::exception& e)
	{
		std::cerr << "std::exception catched !" << std::endl;
	}
}

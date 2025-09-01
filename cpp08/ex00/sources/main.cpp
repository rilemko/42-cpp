/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 04:18:26 by ael-khni          #+#    #+#             */
/*   Updated: 2023/09/30 17:58:23 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list>
#include <vector>
#include "easyfind.hpp"

int main()
{
	// 1. Create a std::list and add 4 integers to it, then search for
	// integer 2 with easyfind.

	std::cout
		<< "1. Create a std::list and add 4 integers to it, then search for "
		<< "integer 2 with easyfind."
		<< std::endl << std::endl;

	std::list<int>	list;

	list.push_back(0);
	list.push_back(1);
	list.push_back(2);
	list.push_back(3);
	
	try
	{
		std::cout << "std::list   : " << easyfind(list, 2) << std::endl;
	}
	catch (std::runtime_error& e)
	{
		std::cerr << e.what() << std::endl;
	}

	// 2. Create a std::vector and add 4 integers to it, then search for
	// integer 2 with easyfind.

	std::cout << std::endl
		<< "2. Create a std::vector and add 4 integers to it, then search for "
		<< "integer 2 with easyfind."
		<< std::endl << std::endl;

	std::vector<int>	vect;

	vect.push_back(0);
	vect.push_back(1);
	vect.push_back(2);
	vect.push_back(3);

	try
	{
		std::cout << "std::vector : " << easyfind(vect, 2) << std::endl;
	}
	catch (std::runtime_error& e)
	{
		std::cerr << e.what() << std::endl;
	}

	// 3. Try searching for the integer 4, which is not in the list.

	std::cout << std::endl
		<< "3. Try finding the integer 4, which is not in the list."
		<< std::endl << std::endl;

	try
	{
		std::cout << "std::list   : " << easyfind(list, 4) << std::endl;
	}
	catch (std::runtime_error& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 04:18:26 by ael-khni          #+#    #+#             */
/*   Updated: 2023/09/30 18:36:44 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
	// 1. Creates a Span of size 5 without adding any elements.

	std::cout
		<< "1. Creates a Span of size 5 without adding any elements."
		<< std::endl;

	Span	span1(5);
	
	// 2. Tries to display the longest and shortest distances in the empty
	// list.

	std::cout
		<< "2. Tries to display the longest and shortest distances in the empty "
		<< "list."
		<< std::endl << std::endl;

	try
	{
		std::cout << "shortest : " << span1.shortestSpan() << std::endl;
		std::cout << "longest  : " << span1.longestSpan()  << std::endl;
	}
	catch(std::runtime_error& e)
	{
		std::cerr << e.what() << std::endl;
	}

	// 3. Try adding 6 elements to the Span of size 5.

	std::cout << std::endl
		<< "3. Try adding 6 elements to the Span of size 5."
		<< std::endl << std::endl;
	
	try
	{
		span1.addNumber(3);
		span1.addNumber(6);
		span1.addNumber(17);
		span1.addNumber(9);
		span1.addNumber(11);
		span1.addNumber(42);
	}
	catch (std::runtime_error& e)
	{
		std::cerr << e.what() << std::endl;
	}
	span1.display();

	// 4. Display the shortest and longest distances in the list.

	std::cout << std::endl
		<< "4. Display the shortest and longest distances in the list."
		<< std::endl << std::endl;

	std::cout << "shortest : " << span1.shortestSpan() << std::endl;
	std::cout << "longest  : " << span1.longestSpan()  << std::endl;

	// 5. Creates 3 Spans of size 10, and fill them using the addListed(),
	// addRanged() and addRandom() functions.

	std::cout << std::endl
		<< "5. Creates 3 Spans of size 10, and fill them using the "
		<< "addListed(), addRanged() and addRandom() functions."
		<< std::endl << std::endl;

	Span			span2(10), span3(10), span4(10);
	std::list<int>	list;

	list.push_back(0);
	list.push_back(1);
	list.push_back(2);
	list.push_back(3);
	list.push_back(4);
	list.push_back(5);

	span2.addListed(list);
	span3.addRanged(-5, 5);
	span4.addRandom(10);

	span2.display();
	span3.display();
	span4.display();
}

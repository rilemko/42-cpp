/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 04:18:26 by ael-khni          #+#    #+#             */
/*   Updated: 2023/10/01 12:51:52 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iomanip>
#include <limits>
#include "PmergeMe.hpp"

#include <unistd.h>

template <typename T>
void	init(int agc, char** agv, T* list);

int main(int agc, char **agv)
{
	if (agc < 2)
	{
		std::cerr << "Usage: " << agv[0] << " <integers...>" << std::endl;
		return (EXIT_FAILURE);
	}
	try
	{
		std::string			content;
		std::stringstream	stringstream;
		std::deque <int>	dque;
		std::vector<int>	vect;

		init<std::deque <int> >(agc - 1, agv + 1, &dque);
		init<std::vector<int> >(agc - 1, agv + 1, &vect);

		PmergeMe<std::deque <int> >	pmm1(dque);
		PmergeMe<std::vector<int> >	pmm2(vect);

		stringstream << pmm2;
		content = stringstream.str();
		std::cout << "Before : "
			<< ((pmm2.getSize() <= 12) ? stringstream.str() : (content.substr(0, 72) + " [...]}"))
			<< std::endl;
		stringstream.str("");

		pmm1.process();
		pmm2.process();

		stringstream << pmm2;
		content = stringstream.str();
		std::cout << "After  : "
			<< ((pmm2.getSize() <= 12) ? stringstream.str() : (content.substr(0, 72) + " [...]}"))
			<< std::endl;

		std::cout << "Time to process a range of "
			<< std::setw(4) << pmm1.getSize() << " elements with "
			<< std::setw(11) << "std::deque " << " : "
			<< std::setw(4) << pmm1.getTime() << " clock ticks"
			<< std::endl;

		std::cout << "Time to process a range of "
			<< std::setw(4) << pmm2.getSize() << " elements with "
			<< std::setw(11) << "std::vector" << " : " 
			<< std::setw(4) << pmm2.getTime() << " clock ticks"
			<< std::endl;
	}
	catch(std::runtime_error& e)
	{
		std::cerr << e.what() << std::endl;
		return (EXIT_FAILURE);
	}
}

template <typename T>
void	init(int agc, char** agv, T* list)
{
	long		current;
	std::string	content;
	char*		remains;
	
	for (int i = 0; i < agc; i++)
	{
		std::stringstream	stringstream(agv[i]);
		while (std::getline(stringstream, content, ' '))
		{
			if (std::strlen(content.c_str()) == 0)
				continue;
			current = std::strtol(content.c_str(), &remains, 10);
			if (std::strlen(remains) != 0
				|| current < -std::numeric_limits<int>::max()
				|| current > std::numeric_limits<int>::max())
				throw std::runtime_error("InvalidArgumentException : Invalid argument.");
			list->push_back(current);
		}
	}
}

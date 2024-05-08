/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 14:27:41 by mconreau          #+#    #+#             */
/*   Updated: 2024/03/26 22:42:50 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int
main(void)
{
	// 1. Try to instantiate a grade 0 bureaucrat.

	std::cout
		<< "1. Try to instantiate a grade 0 bureaucrat."
		<< std::endl << std::endl;

	try
	{
		Bureaucrat	Alfred("Alfred", 0);
		std::cout << Alfred << std::endl;
	}
	catch (Bureaucrat::BureaucratException& e)
	{
		std::cout << e.what() << std::endl;
	}

	// 2. Try to instantiate a grade 151 bureaucrat.

	std::cout << std::endl
		<< "2. Try to instantiate a grade 151 bureaucrat."
		<< std::endl << std::endl;

	try
	{
		Bureaucrat	Alfred("Alfred", 151);
		std::cout << Alfred << std::endl;
	}
	catch (Bureaucrat::BureaucratException& e)
	{
		std::cout << e.what() << std::endl;
	}

	// 3. Instantiate a grade 1 bureaucrat, then increment its grade by 1.

	std::cout << std::endl
		<< "3. Instantiate a grade 1 bureaucrat, then increment its grade by 1."
		<< std::endl << std::endl;

	try
	{
		Bureaucrat	Alfred("Alfred", 1);
		std::cout << Alfred << std::endl;
		Alfred.incrementGrade();
		std::cout << Alfred << std::endl;
	}
	catch (Bureaucrat::BureaucratException& e)
	{
		std::cout << e.what() << std::endl;
	}

	// 4. Instantiate a grade 150 bureaucrat, then decrement its grade by 1.

	std::cout << std::endl
		<< "4. Instantiate a grade 150 bureaucrat, then decrement its grade by 1."
		<< std::endl << std::endl;

	try
	{
		Bureaucrat	Alfred("Alfred", 150);
		std::cout << Alfred << std::endl;
		Alfred.decrementGrade();
		std::cout << Alfred << std::endl;
	}
	catch (Bureaucrat::BureaucratException& e)
	{
		std::cout << e.what() << std::endl;
	}
}

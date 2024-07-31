/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 14:27:41 by mconreau          #+#    #+#             */
/*   Updated: 2024/03/26 22:42:36 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void)
{
	// 1. Instantiate two bureaucrat, Alfred (grade 10) and Bobby (grade 100).

	std::cout
		<< "1. Instantiate two bureaucrat, Alfred (grade 10) and Bobby (grade 100)."
		<< std::endl << std::endl;

	Bureaucrat Alfred("Alfred", 10);
	std::cout << Alfred << std::endl;
	Bureaucrat Bobby("Bobby", 100);
	std::cout << Bobby << std::endl;

	// 2. Try to instantiate a grade 0 form.

	std::cout << std::endl
		<< "2. Try to instantiate a grade 0 form."
		<< std::endl << std::endl;

	try
	{
		Form	Form1("TooHigh", 1, 0);
		std::cout << Form1 << std::endl;
	}
	catch (Form::FormException& e)
	{
		std::cout << e.what() << std::endl;
	}

	// 3. Try to instantiate a grade 151 form.

	std::cout << std::endl
		<< "3. Try to instantiate a grade 151 form."
		<< std::endl << std::endl;

	try
	{
		Form	Form1("TooHigh", 1, 151);
		std::cout << Form1 << std::endl;
	}
	catch (Form::FormException& e)
	{
		std::cout << e.what() << std::endl;
	}

	// 4. Instantiate a grade 50 form, then try to sign it with Bobby (100).

	std::cout << std::endl
		<< "4. Instantiate a grade 50 form, then try to sign it with Bobby (100)."
		<< std::endl << std::endl;

	try
	{
		Form	Form1("BasicForm", 1, 50);
		std::cout << Form1 << std::endl;
		Form1.beSigned(Bobby);
		std::cout << Form1 << std::endl;
	}
	catch (Form::FormException& e)
	{
		std::cout << e.what() << std::endl;
	}

	// 5. Instantiate a grade 50 form, then try to sign it with Alfred (10).

	std::cout << std::endl
		<< "5. Instantiate a grade 50 form, then try to sign it with Alfred (10)."
		<< std::endl << std::endl;

	try
	{
		Form	Form1("BasicForm", 1, 50);
		std::cout << Form1 << std::endl;
		Form1.beSigned(Alfred);
		std::cout << Form1 << std::endl;
	}
	catch (Form::FormException& e)
	{
		std::cout << e.what() << std::endl;
	}
}

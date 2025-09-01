/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 14:27:41 by mconreau          #+#    #+#             */
/*   Updated: 2024/03/26 22:42:12 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int	main(void)
{
	// 1. Instantiate two bureaucrat, Alfred (grade 5) and Bobby (grade 140).

	std::cout
		<< "1. Instantiate two bureaucrat, Alfred (grade 5) and Bobby (grade 140)."
		<< std::endl << std::endl;

	Bureaucrat Alfred("Alfred", 5);
	std::cout << Alfred << std::endl;
	Bureaucrat Bobby("Bobby", 140);
	std::cout << Bobby << std::endl;

	// 2. Instantiate one ShrubberyCreationForm, execute with Bobby, 
	// try to execute with Bobby, then try to execute with Alfred.

	std::cout << std::endl
		<< "2. Instantiate one ShrubberyCreationForm, sign it with Bobby, "
		<< "try to execute with Bobby, then try to execute with Alfred."
		<< std::endl << std::endl;

	try
	{
		ShrubberyCreationForm	Form("Jardin");
		std::cout << Form << std::endl;
		Form.beSigned(Bobby);
		std::cout << Form << std::endl;
		Form.execute(Bobby);
		Form.execute(Alfred);
	}
	catch (AForm::FormException& e)
	{
		std::cout << e.what() << std::endl;
	}

	// 3. Instantiate one RobotomyRequestForm, execute with Alfred, 
	// try to execute with Bobby, then try to execute with Alfred.

	std::cout << std::endl
		<< "3. Instantiate one RobotomyRequestForm, sign it with Alfred, "
		<< "try to execute with Bobby, then try to execute with Alfred."
		<< std::endl << std::endl;

	try
	{
		RobotomyRequestForm	Form("Tac");
		std::cout << Form << std::endl;
		Form.beSigned(Alfred);
		std::cout << Form << std::endl;
		Form.execute(Bobby);
		Form.execute(Alfred);
	}
	catch (AForm::FormException& e)
	{
		std::cout << e.what() << std::endl;
	}

		// 4. Instantiate one PresidentialPardonForm, execute with Alfred, 
	// try to execute with Bobby, then try to execute with Alfred.

	std::cout << std::endl
		<< "4. Instantiate one PresidentialPardonForm, sign it with Alfred, "
		<< "try to execute with Bobby, then try to execute with Alfred."
		<< std::endl << std::endl;

	try
	{
		PresidentialPardonForm	Form("Tac");
		std::cout << Form << std::endl;
		Form.beSigned(Alfred);
		std::cout << Form << std::endl;
		Form.execute(Bobby);
		Form.execute(Alfred);
	}
	catch (AForm::FormException& e)
	{
		std::cout << e.what() << std::endl;
	}
}

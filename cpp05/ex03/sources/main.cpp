/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 14:27:41 by mconreau          #+#    #+#             */
/*   Updated: 2023/08/25 16:25:19 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int	main(void)
{
	// 1. Instantiate two bureaucrat, Alfred (grade 5) and Bobby (grade 140)
	// and one Intern.

	std::cout
		<< "1. Instantiate two bureaucrat, Alfred (grade 5) and Bobby (grade 140)"
		<< "and one Intern."
		<< std::endl << std::endl;

	Bureaucrat	Alfred("Alfred", 5);
	std::cout << Alfred << std::endl;
	Bureaucrat	Bobby("Bobby", 137);
	std::cout << Bobby << std::endl;
	Intern		Intern;

	// 2. Ask the Intern to create wrong form.

	std::cout << std::endl
		<< "2. Ask the Intern to create wrong form."
		<< std::endl << std::endl;
	{
		AForm	*Form = Intern.makeForm("wrong request", "Jardin");
		(void) Form;
	}

	// 3. Instantiate one ShrubberyCreationForm, execute with Bobby, 
	// try to execute with Bobby, then try to execute with Alfred.

	std::cout << std::endl
		<< "3. Instantiate one ShrubberyCreationForm, sign it with Bobby, "
		<< "try to execute with Bobby, then try to execute with Alfred."
		<< std::endl << std::endl;

	try
	{
		ShrubberyCreationForm	*Form
			= (ShrubberyCreationForm *) Intern.makeForm("shrubbery creation", "Jardin");
		std::cout << *Form << std::endl;
		Form->beSigned(Bobby);
		std::cout << *Form << std::endl;
		Form->execute(Bobby);
		Form->execute(Alfred);

		delete Form;
	}
	catch (AForm::FormException &e)
	{
		std::cout << e.what() << std::endl;
	}

	// 4. Instantiate one RobotomyRequestForm, execute with Alfred, 
	// try to execute with Bobby, then try to execute with Alfred.

	std::cout << std::endl
		<< "4. Instantiate one RobotomyRequestForm, sign it with Alfred, "
		<< "try to execute with Bobby, then try to execute with Alfred."
		<< std::endl << std::endl;

	try
	{
		RobotomyRequestForm	*Form
			= (RobotomyRequestForm *) Intern.makeForm("robotomy request", "Tac");
		std::cout << *Form << std::endl;
		Form->beSigned(Alfred);
		std::cout << *Form << std::endl;
		Form->execute(Bobby);
		Form->execute(Alfred);

		delete Form;
	}
	catch (AForm::FormException &e)
	{
		std::cout << e.what() << std::endl;
	}

	// 5. Instantiate one PresidentialPardonForm, execute with Alfred, 
	// try to execute with Bobby, then try to execute with Alfred.

	std::cout << std::endl
		<< "5. Instantiate one PresidentialPardonForm, sign it with Alfred, "
		<< "try to execute with Bobby, then try to execute with Alfred."
		<< std::endl << std::endl;

	try
	{
		PresidentialPardonForm	*Form
			= (PresidentialPardonForm *) Intern.makeForm("presidential pardon", "Tac");
		std::cout << *Form << std::endl;
		Form->beSigned(Alfred);
		std::cout << *Form << std::endl;
		Form->execute(Bobby);
		Form->execute(Alfred);

		delete Form;
	}
	catch (AForm::FormException &e)
	{
		std::cout << e.what() << std::endl;
	}
}

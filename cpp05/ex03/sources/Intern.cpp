/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 14:32:56 by mconreau          #+#    #+#             */
/*   Updated: 2024/03/26 22:47:42 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
	this->_keys[0] = "shrubbery creation";
	this->_keys[1] = "robotomy request";
	this->_keys[2] = "presidential pardon";
	this->_values[0] = &Intern::makeShrubberyForm;
	this->_values[1] = &Intern::makeRobotomyForm;
	this->_values[2] = &Intern::makePresidentialForm;
}

Intern::Intern(const Intern& src)
{
	*this = src;
}

Intern::~Intern()
{
}

AForm*
Intern::makePresidentialForm(std::string formTarget)
{
	return (new PresidentialPardonForm(formTarget));
}

AForm*
Intern::makeRobotomyForm(std::string formTarget)
{
	return (new RobotomyRequestForm(formTarget));
}

AForm*
Intern::makeShrubberyForm(std::string formTarget)
{
	return (new ShrubberyCreationForm(formTarget));
}

AForm*
Intern::makeForm(std::string formName, std::string formTarget)
{
	for (int i = 0; i < 3; i++)
		if (this->_keys[i] == formName)
			return ((std::cout << "Intern creates form " << formName << std::endl),
				(this->*_values[i])(formTarget));
	std::cout << "Intern couldn’t create form " << formName << std::endl;
	return (NULL);
}

Intern&
Intern::operator=(const Intern& rhs)
{
	(void) rhs;
	return (*this);
}

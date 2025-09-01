/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 14:32:56 by mconreau          #+#    #+#             */
/*   Updated: 2024/03/26 22:40:03 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) :
	AForm(target + "Form", 137, 145), _target(target)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

bool
ShrubberyCreationForm::execute(const Bureaucrat& executor)
{
	std::fstream	ostream;
	
	if (AForm::execute(executor) == true)
	{
		ostream.open((this->_target + "_shrubbery").c_str(), std::ios::out);
		if (ostream.is_open())
		{
			ostream << "            ,@@@@@@@," << std::endl
					<< "    ,,,.   ,@@@@@@/@@,  .oo8888o." << std::endl
					<< " ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o" << std::endl
					<< ",%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'" << std::endl
					<< "%&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'" << std::endl
					<< "%&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'" << std::endl
					<< "`&%\\ ` /%&'    |.|        \\ '|8'" << std::endl
					<< "    |o|        | |         | |" << std::endl
					<< "    |.|        | |         | |" << std::endl
					<< " \\/ ._\\//_/__/  ,\\_//__\\/.  \\_//__/_";
			ostream.close();
		}
		return (true);
	}
	return (false);
}

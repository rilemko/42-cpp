/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 14:32:56 by mconreau          #+#    #+#             */
/*   Updated: 2024/03/26 22:39:13 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string target) :
	AForm(target + "Form", 45, 72), _target(target)
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

bool
RobotomyRequestForm::execute(const Bureaucrat& executor)
{
	if (AForm::execute(executor) == true)
	{
		srand(time(NULL));
		std::cout << "*Brrrrrr Brrrrrr Brrrrrr*" << std::endl
			<< this->_target << (rand() % 2 ? " has been robotomized." : " was not robotomized.")
			<< std::endl;
		return (true);
	}
	return (false);
}

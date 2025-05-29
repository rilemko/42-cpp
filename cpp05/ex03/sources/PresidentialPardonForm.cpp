/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 14:32:56 by mconreau          #+#    #+#             */
/*   Updated: 2024/03/26 22:39:09 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string target) :
	AForm(target + "Form", 5, 25), _target(target)
{
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

bool
PresidentialPardonForm::execute(const Bureaucrat& executor)
{
	if (AForm::execute(executor) == true)
	{
		return ((std::cout << this->_target
			<< " has been forgiven by Zaphod Beeblebrox." << std::endl), true);
	}
	return (false);
}

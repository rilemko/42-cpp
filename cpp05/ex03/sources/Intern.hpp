/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 14:32:53 by mconreau          #+#    #+#             */
/*   Updated: 2024/03/26 22:48:46 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

class AForm;

class Intern
{
	private  :
		std::string			_keys[3];
		AForm				*(Intern::*_values[3])(std::string);

	public   :
							Intern();
							Intern(const Intern& src);
		virtual				~Intern();

		AForm*				makeForm(std::string formName, std::string formTarget);

		Intern&				operator=(const Intern& rhs);

	private:
		AForm*				makePresidentialForm(std::string formTarget);
		AForm*				makeRobotomyForm(std::string formTarget);
		AForm*				makeShrubberyForm(std::string formTarget);

};

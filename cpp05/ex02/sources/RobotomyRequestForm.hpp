/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 14:32:53 by mconreau          #+#    #+#             */
/*   Updated: 2024/03/26 22:39:00 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <AForm.hpp>
#include "Bureaucrat.hpp"
#include <cstdlib>
#include <iostream>

class Bureaucrat;

class RobotomyRequestForm : public AForm
{
	private  :
		const std::string	_target;

	public   :
							RobotomyRequestForm(const std::string target);
		virtual				~RobotomyRequestForm();

		bool				execute(const Bureaucrat& executor);
};

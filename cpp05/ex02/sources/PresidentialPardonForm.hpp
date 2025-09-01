/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 14:32:53 by mconreau          #+#    #+#             */
/*   Updated: 2024/03/26 22:38:10 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <AForm.hpp>
#include "Bureaucrat.hpp"
#include <cstdlib>
# include <iostream>

class Bureaucrat;

class PresidentialPardonForm : public AForm
{
	private  :
		const std::string	_target;

	public   :
							PresidentialPardonForm(const std::string target);
		virtual				~PresidentialPardonForm();

		bool				execute(const Bureaucrat& executor);
};

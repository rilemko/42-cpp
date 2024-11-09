/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 14:32:53 by mconreau          #+#    #+#             */
/*   Updated: 2024/03/26 22:36:27 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#define GRADE_MIN	150
#define GRADE_MAX	1

#include <iostream>

class AForm;

class Bureaucrat
{
	private  :
		int					_grade;
		const std::string	_name;

	public   :
							Bureaucrat(const std::string name, int grade = GRADE_MIN);
							Bureaucrat(const Bureaucrat& src);
							~Bureaucrat();

		void				decrementGrade();
		bool				executeForm(const AForm&) const;
		int					getGrade() const;
		const std::string	getName() const;
		void				incrementGrade();
		bool				signForm(const AForm&) const;

		Bureaucrat&			operator=(const Bureaucrat& rhs);

		class BureaucratException : public std::exception
		{
			public:
				using std::exception::what;
				virtual const char*	what() throw();
		};
		
		class GradeTooHighException : public BureaucratException
		{
			public:
				using BureaucratException::what;
				virtual const char*	what() throw();
		};

		class GradeTooLowException : public BureaucratException
		{
			public:
				using BureaucratException::what;
				virtual const char* what() throw();
		};
};

std::ostream&   operator<<(std::ostream& ostream, const Bureaucrat& rhs);
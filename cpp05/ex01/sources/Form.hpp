/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 14:32:53 by mconreau          #+#    #+#             */
/*   Updated: 2024/03/26 22:27:05 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#define GRADE_MIN	150
#define GRADE_MAX	1

#include "Bureaucrat.hpp"
#include <iostream>

class Bureaucrat;

class Form
{
	private  :
		int					_gradeToExec;
		int					_gradeToSign;
		bool				_formIsSigned;
		const std::string	_name;

	public   :
							Form(const std::string name, int gradeToExec = GRADE_MAX, int gradeToSign = GRADE_MAX);
							Form(const Form& src);
							~Form();

		bool				beSigned(const Bureaucrat& bureaucrat);
		int					getGradeToExec() const;
		int					getGradeToSign() const;
		const std::string	getName() const;
		bool				isSigned() const;

		Form&				operator=(const Form& rhs);

		class FormException : public std::exception
		{
			public:
				using std::exception::what;
				virtual const char*	what() throw();
		};
		
		class GradeTooHighException : public FormException
		{
			public:
				using FormException::what;
				virtual const char*	what() throw();
		};

		class GradeTooLowException : public FormException
		{
			public:
				using FormException::what;
				virtual const char* what() throw();
		};
};

std::ostream&   operator<<(std::ostream& ostream, const Form& rhs);

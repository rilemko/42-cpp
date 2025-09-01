/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 14:32:53 by mconreau          #+#    #+#             */
/*   Updated: 2024/03/26 22:34:21 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#define GRADE_MIN	150
#define GRADE_MAX	1

#include "Bureaucrat.hpp"
#include <iostream>

class Bureaucrat;

class AForm
{
	private  :
		int					_gradeToExec;
		int					_gradeToSign;
		bool				_formIsSigned;
		const std::string	_name;

	public   :
							AForm(const std::string name, int gradeToExec = GRADE_MAX, int gradeToSign = GRADE_MAX);
							AForm(const AForm& src);
		virtual				~AForm() = 0;

		bool				beSigned(const Bureaucrat& bureaucrat);
		bool				execute(const Bureaucrat& executor) const;
		int					getGradeToExec() const;
		int					getGradeToSign() const;
		const std::string	getName() const;
		bool				isSigned() const;

		AForm&				operator=(const AForm& rhs);

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

std::ostream&   operator<<(std::ostream& ostream, const AForm& rhs);

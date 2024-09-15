/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 14:32:56 by mconreau          #+#    #+#             */
/*   Updated: 2023/08/24 15:26:20 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(const std::string name, int gradeToExec, int gradeToSign) :
	_gradeToExec(gradeToExec), _gradeToSign(gradeToSign), _formIsSigned(false), _name(name)
{
	if (gradeToExec > GRADE_MIN || gradeToSign > GRADE_MIN)
		throw Form::GradeTooLowException();
	if (gradeToExec < GRADE_MAX || gradeToSign < GRADE_MAX)
		throw Form::GradeTooHighException();
}

Form::Form(const Form& src)
{
	*this = src;
}

Form::~Form()
{
}

bool
Form::beSigned(const Bureaucrat& bureaucrat)
{
	return (this->_formIsSigned = bureaucrat.signForm(*this));
}

int
Form::getGradeToExec() const
{
	return this->_gradeToExec;
}

int
Form::getGradeToSign() const
{
	return this->_gradeToSign;
}

bool
Form::isSigned() const
{
	return this->_formIsSigned;
}


const std::string	Form::getName() const
{
	return this->_name;
}

Form&
Form::operator=(const Form& rhs)
{
	this->_gradeToExec = rhs.getGradeToExec();
	this->_gradeToSign = rhs.getGradeToSign();
	this->_formIsSigned = rhs.isSigned();
	return (*this);
}

std::ostream&
operator<<(std::ostream& ostream, const Form& rhs)
{
    ostream << rhs.getName() << ", currently "
		<< (rhs.isSigned() ? "signed" : "unsigned")
		<< ", can be executed by bureaucrat grade " << rhs.getGradeToExec()
		<< ", can be signed by bureaucrat grade " << rhs.getGradeToSign();
    return ostream;
}

const char*
Form::FormException::what() throw()
{
	return "Form::FormException : A Formic exception has occurred.";
}

const char*
Form::GradeTooHighException::what() throw()
{
	return "Form::GradeTooHighException : Grade too high.";
}

const char*
Form::GradeTooLowException::what() throw()
{
	return "Form::GradeTooLowException : Grade too low.";
}

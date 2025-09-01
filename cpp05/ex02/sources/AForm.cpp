/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 14:32:56 by mconreau          #+#    #+#             */
/*   Updated: 2024/03/26 22:33:07 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(const std::string name, int gradeToExec, int gradeToSign) :
	_gradeToExec(gradeToExec), _gradeToSign(gradeToSign), _formIsSigned(false), _name(name)
{
	if (gradeToExec > GRADE_MIN || gradeToSign > GRADE_MIN)
		throw AForm::GradeTooLowException();
	if (gradeToExec < GRADE_MAX || gradeToSign < GRADE_MAX)
		throw AForm::GradeTooHighException();
}

AForm::AForm(const AForm& src)
{
	*this = src;
}

AForm::~AForm()
{
}

bool
AForm::beSigned(const Bureaucrat& bureaucrat)
{
	return (this->_formIsSigned = bureaucrat.signForm(*this));
}

bool
AForm::execute(const Bureaucrat& executor) const
{
	return (executor.executeForm(*this));
}

int
AForm::getGradeToExec() const
{
	return this->_gradeToExec;
}

int
AForm::getGradeToSign() const
{
	return this->_gradeToSign;
}

bool
AForm::isSigned() const
{
	return this->_formIsSigned;
}


const std::string
AForm::getName() const
{
	return this->_name;
}

AForm
&AForm::operator=(const AForm& rhs)
{
	this->_gradeToExec = rhs.getGradeToExec();
	this->_gradeToSign = rhs.getGradeToSign();
	this->_formIsSigned = rhs.isSigned();
	return (*this);
}

std::ostream&
operator<<(std::ostream& ostream, const AForm& rhs)
{
    ostream << rhs.getName() << ", currently "
		<< (rhs.isSigned() ? "signed" : "unsigned")
		<< ", can be executed by bureaucrat grade " << rhs.getGradeToExec()
		<< ", can be signed by bureaucrat grade " << rhs.getGradeToSign();
    return ostream;
}

const char*
AForm::FormException::what() throw()
{
	return "Form::FormException : A AFormic exception has occurred.";
}

const char*
AForm::GradeTooHighException::what() throw()
{
	return "Form::GradeTooHighException : Grade too high.";
}

const char*
AForm::GradeTooLowException::what() throw()
{
	return "Form::GradeTooLowException : Grade too low.";
}

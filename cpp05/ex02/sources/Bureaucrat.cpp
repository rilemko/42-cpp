/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 14:32:56 by mconreau          #+#    #+#             */
/*   Updated: 2024/03/26 22:36:03 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat(const std::string name, int grade) :
	_grade(grade), _name(name)
{
	if (grade > GRADE_MIN)
		throw Bureaucrat::GradeTooLowException();
	if (grade < GRADE_MAX)
		throw Bureaucrat::GradeTooHighException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& src)
{
	*this = src;
}

Bureaucrat::~Bureaucrat()
{
}

void
Bureaucrat::decrementGrade()
{
	if (this->_grade + 1 > GRADE_MIN)
		throw Bureaucrat::GradeTooLowException();
	this->_grade++;
}

bool
Bureaucrat::executeForm(const AForm &form) const
{
	if (form.isSigned() && this->_grade <= form.getGradeToExec())
		return ((std::cout << this->_name << " executed form " << form.getName() << std::endl), true);
	return ((std::cout << this->_name << " couldn’t execute form " << form.getName() << std::endl), false);
}

int
Bureaucrat::getGrade() const
{
	return this->_grade;
}

const std::string
Bureaucrat::getName() const
{
	return this->_name;
}

void
Bureaucrat::incrementGrade()
{
	if (this->_grade - 1 < GRADE_MAX)
		throw Bureaucrat::GradeTooHighException();
	this->_grade--;
}

bool
Bureaucrat::signForm(const AForm &form) const
{
	if (this->_grade <= form.getGradeToSign())
		return ((std::cout << this->_name << " signed form " << form.getName() << std::endl), true);
	return ((std::cout << this->_name << " couldn’t sign form " << form.getName() << std::endl), false);
}

Bureaucrat&
Bureaucrat::operator=(const Bureaucrat& rhs)
{
	this->_grade = rhs.getGrade();
	return (*this);
}

std::ostream&
operator<<(std::ostream& ostream, const Bureaucrat& rhs)
{
    ostream << rhs.getName() << ", bureaucrat grade " << rhs.getGrade();
    return ostream;
}

const char*
Bureaucrat::BureaucratException::what() throw()
{
	return "Bureaucrat::BureaucratException : A bureaucratic exception has occurred.";
}

const char*
Bureaucrat::GradeTooHighException::what() throw()
{
	return "Bureaucrat::GradeTooHighException : Grade too high.";
}

const char*
Bureaucrat::GradeTooLowException::what() throw()
{
	return "Bureaucrat::GradeTooLowException : Grade too low.";
}

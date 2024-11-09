/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 14:32:56 by mconreau          #+#    #+#             */
/*   Updated: 2024/03/26 22:18:24 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string name, int grade) :
	_grade(grade), _name(name)
{
	if (grade > GRADE_MIN)
		throw Bureaucrat::GradeTooLowException();
	if (grade < GRADE_MAX)
		throw Bureaucrat::GradeTooHighException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &src)
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

Bureaucrat
&Bureaucrat::operator=(const Bureaucrat& rhs)
{
	this->_grade = rhs.getGrade();
	return (*this);
}

std::ostream&
operator<<(std::ostream& stream, const Bureaucrat& rhs)
{
    stream << rhs.getName() << ", bureaucrat grade " << rhs.getGrade();
    return stream;
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

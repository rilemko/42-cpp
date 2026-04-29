/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 18:16:28 by mconreau          #+#    #+#             */
/*   Updated: 2024/05/07 14:30:42 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

const struct RPN::_operations RPN::_operations[4] = {
	{'+', &RPN::operateSum},
	{'-', &RPN::operateSub},
	{'*', &RPN::operateMul},
	{'/', &RPN::operateDiv}
};

RPN::RPN(std::string operations)
{
	double				current;
	char*				remains;
	std::stringstream	stringstream(operations);
	std::string			content, operators("+-/*");

	while (std::getline(stringstream, content, ' '))
	{
		if (std::strlen(content.c_str()) == 0)
			continue;
		current = std::strtod(content.c_str(), &remains);
		if (std::strlen(remains) != 0)
		{
			if (std::strlen(remains) != 1 || operators.find(content) == std::string::npos)
				throw Exception("InvalidArgumentException : Invalid argument.");
			for(int i = 0; i < 4; i++)
			{
				if (this->_operations[i].type == content[0])
				{
					if (this->_values.size() < 2)
						throw Exception("InvalidArgumentException : Invalid format.");
					current = this->_operations[i].callback(this->pop(), this->pop());
				}
			}
		}
		this->_values.push(current);
	}
}

RPN::RPN(const RPN& src)
{
	*this = src;
}

RPN::~RPN()
{
}

double
RPN::getResult() const
{
	return (this->_values.top());
}

double
RPN::operateDiv(double lhs, double rhs)
{
	return (rhs / lhs);
}

double
RPN::operateMul(double lhs, double rhs)
{
	return (lhs * rhs);
}

double
RPN::operateSub(double lhs, double rhs)
{
	return (rhs - lhs);
}

double
RPN::operateSum(double lhs, double rhs)
{
	return (lhs + rhs);
}

double
RPN::pop()
{
	double	top = this->_values.top();
	this->_values.pop();
	return (top);
}

RPN&
RPN::operator=(const RPN& src)
{
	this->_values = src._values;
	return (*this);
}

RPN::Exception::Exception(const std::string &message) :
	std::runtime_error(message)
{
}

std::ostream&
operator<<(std::ostream& ostream, const RPN& rhs)
{
	ostream << rhs.getResult();
	return (ostream);
}

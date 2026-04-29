/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 14:32:56 by mconreau          #+#    #+#             */
/*   Updated: 2024/03/26 22:56:53 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

char	ScalarConverter::_c = 0;
double	ScalarConverter::_d = 0;
float	ScalarConverter::_f = 0;
int		ScalarConverter::_i = 0;
char*	ScalarConverter::_ptr = NULL;

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter& src)
{
	*this = src;
}

ScalarConverter::~ScalarConverter()
{
}

ScalarConverter&
ScalarConverter::operator=(const ScalarConverter& rhs)
{
	(void) rhs;
	return (*this);
}

bool
ScalarConverter::ascii(int x)
{
	return (x > 0 && x < 127);
}

void
ScalarConverter::display()
{
	if (_ptr != NULL && (strlen(_ptr) > 1 || (strlen(_ptr) == 1 && _ptr[0] != 'f')))
		print(NPOSS, NPOSS, NPOSS, NPOSS);
	else
		print(
			(!isNan(_d) && !isInf(_i) ? (ascii(_i) && std::isprint(_i) ? TOSTR(_c) : NDISP) : NPOSS), 
			(!isNan(_d) && !isInf(_i) ? TOSTR(_i) : NPOSS), 
			TOSTR(std::setprecision(12) << _f << (_f == 0 || _f == _i ? ".0" : "") << "f"), 
			TOSTR(std::setprecision(12) << _d << (_d == 0 || _d == _i ? ".0" : ""))
		);
}


bool
ScalarConverter::isInf(int x)
{
	return (x > std::numeric_limits<int>::max()
		|| x < -std::numeric_limits<int>::max());
}

bool
ScalarConverter::isNan(double x)
{
	return (x != x);
}

void
ScalarConverter::print(std::string v1, std::string v2, std::string v3, std::string v4)
{
	std::cout 
		<< "char   : " << v1 << std::endl
		<< "int    : " << v2 << std::endl
		<< "float  : " << v3 << std::endl
		<< "double : " << v4 << std::endl;
}

void
ScalarConverter::convert(const std::string number)
{
	_d = (number.size() == 1 && !std::isdigit(number[0])) ? int(number[0]) : std::strtod(number.c_str(), &_ptr);
	_f = float(_d);
	_i = int(_d);
	_c = char(_i);
}

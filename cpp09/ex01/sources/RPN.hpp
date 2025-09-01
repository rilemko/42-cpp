/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 14:32:53 by mconreau          #+#    #+#             */
/*   Updated: 2024/05/07 14:30:02 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cmath>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>
#include <stack>
#include <string>

class RPN
{
	private:
		std::stack<double>		_values;
	
	static const struct _operations
	{
		char	type;
		double	(*callback)(double, double);
	}	_operations[4];

	public   :
								RPN(std::string operations);
								RPN(const RPN& src);
								~RPN();

		double					getResult() const;

		RPN&					operator=(const RPN& rhs);

	private  :
		static double			operateDiv(double lhs, double rhs);
		static double			operateMul(double lhs, double rhs);
		static double			operateSub(double lhs, double rhs);
		static double			operateSum(double lhs, double rhs);
		double					pop();

	public 	:
		class Exception : public std::runtime_error
		{
			public   :
								Exception(const std::string &message = "RPNException occured !");
		};
};

std::ostream&	operator<<(std::ostream&, const RPN&);

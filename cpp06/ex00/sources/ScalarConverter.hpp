/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 14:32:53 by mconreau          #+#    #+#             */
/*   Updated: 2024/03/26 23:10:28 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstdlib>
#include <cstring>
#include <limits>
#include <iomanip>
#include <iostream>
#include <sstream>

#define	NDISP		"Non displayable"
#define	NPOSS		"Impossible"
#define TOSTR(x) 	static_cast<const std::ostringstream&>((std::ostringstream() << std::dec << x)).str()

class ScalarConverter
{
	private  :
		static char			_c;
		static double		_d;
		static float		_f;
		static int			_i;
		static char*		_ptr;

	private  :
							ScalarConverter();
							ScalarConverter(const ScalarConverter& src);
							~ScalarConverter();
								
			static bool		ascii(int x);
			static bool		isInf(int x);
			static bool		isNan(double x);
			static void		print(std::string v1, std::string v2, std::string v3, std::string v4);

			ScalarConverter&	operator=(const ScalarConverter& rhs);

	public   :
		static void				display();
		static void				convert(std::string number);

};

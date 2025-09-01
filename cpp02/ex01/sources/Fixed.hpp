/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 23:28:41 by mconreau          #+#    #+#             */
/*   Updated: 2024/03/26 20:39:11 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cmath>
#include <iostream>
#include <ostream>

class   Fixed
{
	private  :
		int					_value;
		static const int	_fractionBits = 8;

    public   :
    						Fixed(void);
							Fixed(const Fixed& src);
							Fixed(const float i);
							Fixed(const int i);
							~Fixed(void);
		
		int					getRawBits(void) const;
		void				setRawBits(const int raw);
		float				toFloat(void) const;
		int					toInt(void) const;

		Fixed&				operator=(const Fixed&);
};

std::ostream&	operator<<(std::ostream& ostream, const Fixed& rhs);

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 23:28:41 by mconreau          #+#    #+#             */
/*   Updated: 2024/03/26 20:48:29 by mconreau         ###   ########.fr       */
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
		static Fixed&		min(Fixed& a, Fixed& b);
		static const Fixed&	min(const Fixed& a, const Fixed& b);
		static Fixed&		max(Fixed& a, Fixed& b);
		static const Fixed&	max(const Fixed& a, const Fixed& b);
		void				setRawBits(const int raw);
		float				toFloat(void) const;
		int					toInt(void) const;

		bool				operator<(const Fixed& rhs) const;
		bool				operator>(const Fixed& rhs) const;
		bool				operator<=(const Fixed& rhs) const;
		bool				operator>=(const Fixed& rhs) const;
		bool				operator==(const Fixed& rhs) const;
		bool				operator!=(const Fixed& rhs) const;
		Fixed&				operator=(const Fixed& rhs);
		Fixed				operator+(const Fixed& rhs) const;
		Fixed				operator-(const Fixed& rhs) const;
		Fixed				operator*(const Fixed& rhs) const;
		Fixed				operator/(const Fixed& rhs) const;
		Fixed&				operator++(void);
		Fixed				operator++(int);
		Fixed&				operator--(void);
		Fixed				operator--(int);
};

std::ostream&	operator<<(std::ostream& ostream, const Fixed& rhs);

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 23:28:41 by mconreau          #+#    #+#             */
/*   Updated: 2024/03/26 14:02:10 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <ostream>

class   Fixed
{
    public:
    						Fixed(void);
							Fixed(const Fixed&);
							Fixed(const float);
							Fixed(const int);
							~Fixed(void);

		bool				operator<(const Fixed&) const;
		bool				operator>(const Fixed&) const;
		bool				operator<=(const Fixed&) const;
		bool				operator>=(const Fixed&) const;
		bool				operator==(const Fixed&) const;
		bool				operator!=(const Fixed&) const;
		Fixed&				operator=(const Fixed&);
		Fixed				operator+(const Fixed&) const;
		Fixed				operator-(const Fixed&) const;
		Fixed				operator*(const Fixed&) const;
		Fixed				operator/(const Fixed&) const;
		Fixed&				operator++(void);
		Fixed				operator++(int);
		Fixed&				operator--(void);
		Fixed				operator--(int);
		
		static Fixed		abs(Fixed&);
		float				abs(void) const;
		int					getRawBits(void) const;
		static Fixed&		max(Fixed&, Fixed&);
		static const Fixed&	max(const Fixed&, const Fixed&);
		static Fixed&		min(Fixed&, Fixed&);
		static const Fixed&	min(const Fixed&, const Fixed&);
		void				setRawBits(const int);
		float				toFloat(void) const;
		int					toInt(void) const;

	private:
		int					value;
		static const int	fractionBits = 8;
};

std::ostream&	operator<<(std::ostream&, const Fixed&);

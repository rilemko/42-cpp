/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 23:28:35 by mconreau          #+#    #+#             */
/*   Updated: 2023/05/09 22:19:49 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cmath>
#include <ostream>
#include <iostream>
#include "Fixed.hpp"

Fixed::Fixed(void)
{
	this->value = 0;
}

Fixed::Fixed(const Fixed &fixed)
{
	*this = fixed;
}

Fixed::Fixed(const float i)
{
	this->value = roundf(i * (1 << this->fractionBits));
}

Fixed::Fixed(const int i)
{
	this->value = i << this->fractionBits;
}

Fixed::~Fixed(void)
{
}

bool	Fixed::operator<(const Fixed &fixed) const
{
	return (this->value < fixed.getRawBits());
}

bool	Fixed::operator>(const Fixed &fixed) const
{
	return (this->value > fixed.getRawBits());
}

bool	Fixed::operator<=(const Fixed &fixed) const
{
	return (this->value <= fixed.getRawBits());
}

bool	Fixed::operator>=(const Fixed &fixed) const
{
	return (this->value >= fixed.getRawBits());
}

bool	Fixed::operator==(const Fixed &fixed) const
{
	return (this->value == fixed.getRawBits());
}

bool	Fixed::operator!=(const Fixed &fixed) const
{
	return (this->value != fixed.getRawBits());
}

Fixed&	Fixed::operator=(const Fixed &fixed)
{
	this->value = fixed.getRawBits();
	return (*this);
}

Fixed	Fixed::operator+(const Fixed &fixed) const
{
	return (Fixed(this->toFloat() + fixed.toFloat()));
}

Fixed	Fixed::operator-(const Fixed &fixed) const
{
	return (Fixed(this->toFloat() - fixed.toFloat()));
}

Fixed	Fixed::operator*(const Fixed &fixed) const
{
	return (Fixed(this->toFloat() * fixed.toFloat()));
}

Fixed	Fixed::operator/(const Fixed &fixed) const
{
	return (Fixed(this->toFloat() / fixed.toFloat()));
}

Fixed&	Fixed::operator++(void)
{
	++this->value;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	fixed(*this);
	
	fixed.value = this->value++;
	return (fixed);
}

Fixed&	Fixed::operator--(void)
{
	--this->value;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	fixed(*this);

	fixed.value = this->value--;
	return (fixed);
}

Fixed	Fixed::abs(Fixed &fixed)
{
	Fixed	temp(fixed < 0 ? (fixed * -1) : fixed);

	return (temp);
}

float	Fixed::abs(void) const
{
	return (this->value < 0 ? -this->toFloat() : this->toFloat());
}

int		Fixed::getRawBits(void) const
{
	return (this->value);
}

Fixed& Fixed::max(Fixed &a, Fixed &b)
{
	return (a.getRawBits() > b.getRawBits() ? a : b);
}

const Fixed& Fixed::max(const Fixed &a, const Fixed &b)
{
	return (a.getRawBits() > b.getRawBits() ? a : b);
}

Fixed& Fixed::min(Fixed &a, Fixed &b)
{
	return (a.getRawBits() < b.getRawBits() ? a : b);
}

const Fixed& Fixed::min(const Fixed &a, const Fixed &b)
{
	return (a.getRawBits() < b.getRawBits() ? a : b);
}

void	Fixed::setRawBits(const int raw)
{
	this->value = raw;
}

float	Fixed::toFloat(void) const
{
	 return ((static_cast <float> (this->value)) / (1 << this->fractionBits));
}

int		Fixed::toInt(void) const
{
	return (this->value >> this->fractionBits);
}

std::ostream&	operator<<(std::ostream &ostream, const Fixed &fixed)
{
	ostream << fixed.toFloat();
	return (ostream);
}

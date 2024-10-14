/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 23:28:35 by mconreau          #+#    #+#             */
/*   Updated: 2024/03/26 21:08:16 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) :
	_value(0)
{
}

Fixed::Fixed(const Fixed& src)
{
	*this = src;
}

Fixed::Fixed(const float i)
{
	this->_value = roundf(i * (1 << this->_fractionBits));
}

Fixed::Fixed(const int i)
{
	this->_value = i << this->_fractionBits;
}

Fixed::~Fixed(void)
{
}

Fixed
Fixed::abs(Fixed& fixed)
{
	return (Fixed(fixed < 0 ? (fixed * -1) : fixed));
}

float
Fixed::abs(void) const
{
	return (this->_value < 0 ? -this->toFloat() : this->toFloat());
}

int
Fixed::getRawBits(void) const
{
	return (this->_value);
}

Fixed&
Fixed::min(Fixed& a, Fixed& b)
{
	return (a.getRawBits() < b.getRawBits() ? a : b);
}

const Fixed&
Fixed::min(const Fixed& a, const Fixed& b)
{
	return (a.getRawBits() < b.getRawBits() ? a : b);
}

Fixed&
Fixed::max(Fixed& a, Fixed& b)
{
	return (a.getRawBits() > b.getRawBits() ? a : b);
}

const Fixed&
Fixed::max(const Fixed& a, const Fixed& b)
{
	return (a.getRawBits() > b.getRawBits() ? a : b);
}

void
Fixed::setRawBits(const int raw)
{
	this->_value = raw;
}

float
Fixed::toFloat(void) const
{
	 return ((static_cast <float> (this->_value)) / (1 << this->_fractionBits));
}

int
Fixed::toInt(void) const
{
	return (this->_value >> this->_fractionBits);
}

bool
Fixed::operator<(const Fixed& rhs) const
{
	return (this->_value < rhs.getRawBits());
}

bool
Fixed::operator>(const Fixed& rhs) const
{
	return (this->_value > rhs.getRawBits());
}

bool
Fixed::operator<=(const Fixed& rhs) const
{
	return (this->_value <= rhs.getRawBits());
}

bool
Fixed::operator>=(const Fixed& rhs) const
{
	return (this->_value >= rhs.getRawBits());
}

bool
Fixed::operator==(const Fixed& rhs) const
{
	return (this->_value == rhs.getRawBits());
}

bool
Fixed::operator!=(const Fixed& rhs) const
{
	return (this->_value != rhs.getRawBits());
}

Fixed&
Fixed::operator=(const Fixed& rhs)
{
	this->_value = rhs.getRawBits();
	return (*this);
}

Fixed
Fixed::operator+(const Fixed& rhs) const
{
	return (Fixed(this->toFloat() + rhs.toFloat()));
}

Fixed
Fixed::operator-(const Fixed& rhs) const
{
	return (Fixed(this->toFloat() - rhs.toFloat()));
}

Fixed
Fixed::operator*(const Fixed& rhs) const
{
	return (Fixed(this->toFloat() * rhs.toFloat()));
}

Fixed
Fixed::operator/(const Fixed& rhs) const
{
	return (Fixed(this->toFloat() / rhs.toFloat()));
}

Fixed&
Fixed::operator++(void)
{
	++this->_value;
	return (*this);
}

Fixed
Fixed::operator++(int)
{
	Fixed	fixed(*this);
	
	fixed._value = this->_value++;
	return (fixed);
}

Fixed&
Fixed::operator--(void)
{
	--this->_value;
	return (*this);
}

Fixed
Fixed::operator--(int)
{
	Fixed	fixed(*this);

	fixed._value = this->_value--;
	return (fixed);
}

std::ostream&
operator<<(std::ostream& ostream, const Fixed& rhs)
{
	ostream << rhs.toFloat();
	return (ostream);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 23:28:35 by mconreau          #+#    #+#             */
/*   Updated: 2024/03/26 20:39:04 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) :
	_value(0)
{
	std::cout << "Default conctructor called" << std::endl;
}

Fixed::Fixed(const Fixed& src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::Fixed(const float i)
{
	std::cout << "Float conctructor called" << std::endl;
	this->_value = roundf(i * (1 << this->_fractionBits));
}

Fixed::Fixed(const int i)
{
	std::cout << "Int conctructor called" << std::endl;
	this->_value = i << this->_fractionBits;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

int
Fixed::getRawBits(void) const
{
	return (this->_value);
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

Fixed&
Fixed::operator=(const Fixed& rhs)
{
	std::cout << "Copy assignement operator called" << std::endl;
	this->_value = rhs.getRawBits();
	return (*this);
}

std::ostream&
operator<<(std::ostream& ostream, const Fixed& rhs)
{
	ostream << rhs.toFloat();
	return (ostream);
}

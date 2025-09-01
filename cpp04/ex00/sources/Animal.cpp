/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 15:09:39 by mconreau          #+#    #+#             */
/*   Updated: 2024/03/26 21:34:01 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void)
{
	std::cout << "Animal created" << std::endl;
}

Animal::Animal(const Animal &src)
{
	std::cout << "Animal copied" << std::endl;
	*this = src;
}

Animal::~Animal(void)
{
	std::cout << "Animal destroyed" << std::endl;
}

std::string
Animal::getType(void) const
{
	return (this->_type);
}

void
Animal::makeSound(void) const
{
	std::cout << "* Animal sound *" << std::endl;
}

Animal&
Animal::operator=(const Animal& src)
{
	this->_type = src._type;
	return (*this);
}

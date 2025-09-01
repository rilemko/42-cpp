/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 15:09:39 by mconreau          #+#    #+#             */
/*   Updated: 2024/03/26 21:55:58 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal(void)
{
	std::cout << "Animal created" << std::endl;
}

AAnimal::AAnimal(const AAnimal &src)
{
	std::cout << "Animal copied" << std::endl;
	*this = src;
}

AAnimal::~AAnimal(void)
{
	std::cout << "Animal destroyed" << std::endl;
}

std::string
AAnimal::getType(void) const
{
	return (this->_type);
}

void
AAnimal::makeSound(void) const
{
	std::cout << "* Animal sound *" << std::endl;
}

AAnimal&
AAnimal::operator=(const AAnimal& src)
{
	this->_type = src._type;
	return (*this);
}

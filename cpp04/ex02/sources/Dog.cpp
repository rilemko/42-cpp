/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 15:09:39 by mconreau          #+#    #+#             */
/*   Updated: 2024/03/26 21:47:35 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void) :
	_brain(new Brain)
{
	this->_type = "Cat";
	std::cout << "Dog created" << std::endl;
}

Dog::~Dog(void)
{
	delete this->_brain;
	std::cout << "Dog destroyed" << std::endl;
}

void
Dog::makeSound(void) const
{
	std::cout << "Waouf !" << std::endl;
}

Dog&
Dog::operator=(const Dog& src)
{
	this->_type = src._type;
	this->_brain = new Brain(*src._brain);
	return (*this);
}

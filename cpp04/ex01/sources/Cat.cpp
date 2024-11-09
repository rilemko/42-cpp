/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 15:09:39 by mconreau          #+#    #+#             */
/*   Updated: 2024/03/26 21:47:26 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void) :
	_brain(new Brain)
{
	this->_type = "Cat";
	std::cout << "Cat created" << std::endl;
}

Cat::~Cat(void)
{
	delete this->_brain;
	std::cout << "Cat destroyed" << std::endl;
}

void
Cat::makeSound(void) const
{
	std::cout << "Meow !" << std::endl;
}

Cat&
Cat::operator=(const Cat& src)
{
	this->_type = src._type;
	this->_brain = new Brain(*src._brain);
	return (*this);
}

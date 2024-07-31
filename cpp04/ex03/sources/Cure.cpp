/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 14:39:08 by mconreau          #+#    #+#             */
/*   Updated: 2024/03/26 22:04:02 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(void) :
	AMateria("cure")
{
}

Cure::~Cure(void)
{
}

AMateria*
Cure::clone(void) const
{
	return (new Cure(*this));
}

void
Cure::use(ICharacter& target)
{
	std::cout << "Cure : \"* heals " << target.getName()
		<< "'s wounds *\"" << std::endl;
}

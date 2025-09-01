/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 14:39:08 by mconreau          #+#    #+#             */
/*   Updated: 2024/03/26 22:04:28 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(void) :
	AMateria("ice")
{
}

Ice::~Ice(void)
{
}

AMateria*
Ice::clone(void) const
{
	return (new Ice(*this));
}

void
Ice::use(ICharacter& target)
{
	std::cout << "Ice : \"* shoots an ice bolt at "
		<< target.getName() << " *\"" << std::endl;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 20:54:25 by mconreau          #+#    #+#             */
/*   Updated: 2024/03/26 20:23:57 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon) :
	_name(name), _weapon(&weapon)
{
}

HumanA::~HumanA(void)
{
}

void
HumanA::attack(void) const
{
	std::cout << this->_name << " attack with their "
		<< this->_weapon->getType() << std::endl;
}

void
HumanA::setWeapon(Weapon& weapon)
{
	this->_weapon = &weapon;
}

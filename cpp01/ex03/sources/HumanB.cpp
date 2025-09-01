/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 20:54:23 by mconreau          #+#    #+#             */
/*   Updated: 2024/03/26 20:24:07 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) :
	_name(name), _weapon(NULL)
{
}

HumanB::~HumanB(void)
{
}

void
HumanB::attack(void) const
{
	std::cout << this->_name << " attack with their "
		<< this->_weapon->getType() << std::endl;
}

void
HumanB::setWeapon(Weapon& weapon)
{
	this->_weapon = &weapon;
}

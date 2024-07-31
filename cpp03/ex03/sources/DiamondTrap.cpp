/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 22:13:28 by mconreau          #+#    #+#             */
/*   Updated: 2023/05/10 13:47:48 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name) :
	ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name), _name(name)
{
	FragTrap::_attackPoints = 30;
	ScavTrap::_energyPoints = 50;
	FragTrap::_lifePoints = 100;
	std::cout << "DiamondTrap " << name
		<< " was created !" << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << this->_name
		<< " has disappeared." << std::endl;
}

void
DiamondTrap::whoAmI(void) const
{
	std::cout << "Who th f*ck i am ? " << this->_name << " or " <<
		ClapTrap::_name << " ?" << std::endl;
}

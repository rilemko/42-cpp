/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 22:13:28 by mconreau          #+#    #+#             */
/*   Updated: 2024/03/26 21:22:26 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
	this->_attackPoints = 20;
	this->_energyPoints = 50;
	this->_lifePoints = 100;
	std::cout << "Bip Bop Bip... ScavTrap " << name
		<< " activated." << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << this->_name
		<< " just turned off !" << std::endl;
}

void
ScavTrap::attack(const std::string &target)
{
	if (this->_lifePoints == 0)
		return (std::cout << "Bip Bop Bip... ScavTrap " << this->_name
			<< " has no more vital energy !" << std::endl, (void) NULL);
	if (this->_energyPoints == 0)
		return (std::cout << "Bip Bop Bip, ScavTrap " << this->_name
			<< " is out of energy !" << std::endl, (void) NULL);
	std::cout << "Bip Bip Bop... ScavTrap " << this->_name << " shoot "
		<< target << ", causing " << this->_attackPoints << " points of damage"
		<< std::endl;
	this->_energyPoints += -1;
}

void
ScavTrap::guardGate(void)
{
	if (this->_lifePoints == 0)
		return (std::cout << "Bip Bop Bip... ScavTrap " << this->_name
			<< " has no more vital energy !" << std::endl, (void) NULL);
	if (this->_energyPoints == 0)
		return (std::cout << "Bip Bop Bip... ScavTrap " << this->_name
			<< " is out of energy !" << std::endl, (void) NULL);
	std::cout << "Biiiiiiiiiiiiip... ScavTrap " << this->_name
		<< " is now in Gate Keeper mode !" << std::endl;
	this->_energyPoints += -1;
}

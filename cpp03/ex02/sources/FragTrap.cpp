/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 22:13:28 by mconreau          #+#    #+#             */
/*   Updated: 2024/03/26 21:22:32 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) :
	ClapTrap(name)
{
	this->_attackPoints = 30;
	this->_energyPoints = 100;
	this->_lifePoints = 100;
	std::cout << "FragTrap " << name
		<< " arrived." << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << this->_name
		<< " is gone." << std::endl;
}

void
FragTrap::highFivesGuys(void)
{
	if (this->_lifePoints == 0)
		return (std::cout << " FragTrap " << this->_name
			<< " has no more vital energy !" << std::endl, (void) NULL);
	if (this->_energyPoints == 0)
		return (std::cout << "FragTrap " << this->_name
			<< " is out of energy !" << std::endl, (void) NULL);
	std::cout << "FragTrap " << this->_name
		<< " want to high five everybody..." << std::endl;
	this->_energyPoints += -1;
}

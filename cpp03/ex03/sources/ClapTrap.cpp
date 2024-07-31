/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 22:13:28 by mconreau          #+#    #+#             */
/*   Updated: 2024/03/26 21:14:46 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name):
	_attackPoints(0), _energyPoints(10), _lifePoints(10), _name(name)
{
	std::cout << "What a legend ! ClapTrap " << name
		<< " is here !" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& src)
{
	*this = src;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << this->_name
		<< ", thank you for your service !" << std::endl;
}

void
ClapTrap::attack(const std::string& target)
{
	if (this->_lifePoints == 0)
		return (std::cout << "ClapTrap " << this->_name
			<< " has no more life !" << std::endl, (void) NULL);
	if (this->_energyPoints == 0)
		return (std::cout << "ClapTrap " << this->_name
			<< " is out of energy !" << std::endl, (void) NULL);
	std::cout << "ClapTrap " << this->_name << " attacks " << target
		<< ", causing " << this->_attackPoints << " points of damage"
		<< std::endl;
	this->_energyPoints += -1;
}

void
ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_lifePoints == 0)
		return (std::cout << "ClapTrap " << this->_name
			<< " has no more life !" << std::endl, (void) NULL);
	if (this->_energyPoints == 0)
		return (std::cout << "ClapTrap " << this->_name
			<< " is out of energy !" << std::endl, (void) NULL);
	std::cout << "ClapTrap " << this->_name << " is repaired by "
		<< amount << " life points !" << std::endl;
	this->_energyPoints += -1;
	this->_lifePoints += amount;
}

void
ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << this->_name << " takes "
		<< amount << " damage !" << std::endl;
	if (this->_lifePoints <= amount)
	{
		this->_lifePoints = 0;
		return (std::cout << "ClapTrap " << this->_name
			<< " is dead !" << std::endl, (void) NULL);
	}
	this->_lifePoints += -amount;
}

ClapTrap&
ClapTrap::operator=(const ClapTrap &src)
{
	this->_attackPoints = src._attackPoints;
	this->_energyPoints = src._energyPoints;
	this->_lifePoints = src._lifePoints;
	this->_name = src._name;
	return (*this);
}

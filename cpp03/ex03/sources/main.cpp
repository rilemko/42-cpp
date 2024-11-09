/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 20:01:04 by mconreau          #+#    #+#             */
/*   Updated: 2024/03/26 21:24:14 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "DiamondTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int main(void)
{
	// 1. Create DiamondTrap "Billy"
	
	std::cout
		<< "1. Create DiamondTrap \"Billy\""
		<< std::endl << std::endl;

	DiamondTrap	*Diam	= new DiamondTrap("Billy");

	// 2. Attack to check that the attack points (30) come from FragTrap
	
	std::cout << std::endl
		<< "2. Attack to check that the attack points (30) come from FragTrap"
		<< std::endl << std::endl;

	Diam->attack("someone");

	// 3. Uses its member function, as well as functions inherited from
	// FragTrap and ScavTrap
	
	std::cout << std::endl
		<< "3. Uses its member function, as well as functions inherited from "
		<< "FragTrap and ScavTrap"
		<< std::endl << std::endl;

	Diam->guardGate();
	Diam->highFivesGuys();
	Diam->whoAmI();

	// 4. Takes 99 damage then 1, to check that the life points (100) come from
	// FragTrap
	
	std::cout << std::endl
		<< "4. Takes 99 damage then 1, to check that the life points (100) "
		<< "come from FragTrap"
		<< std::endl << std::endl;

	Diam->takeDamage(99);
	Diam->takeDamage(1);

	// 5. Delete all objects

	std::cout << std::endl
		<< "4. Delete all objects"
		<< std::endl << std::endl;

	delete Diam;

}

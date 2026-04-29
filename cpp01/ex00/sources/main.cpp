/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 20:01:04 by mconreau          #+#    #+#             */
/*   Updated: 2024/03/26 20:18:23 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int
main(void)
{
	// 1. Create Zombie "LeDebile" (1) with newZombie()
	
	std::cout
		<< "1. Create Zombie \"LeDebile\" (1) with newZombie()"
		<< std::endl;

	Zombie*	LeDebile	= newZombie("LeDebile");

	// 2. Create Zombies "LeCon" and "Lidiot" with randomChunk(), which
	// announces itself and destroys itself
	
	std::cout
		<< "2. Create Zombies \"LeCon\" and \"Lidiot\" with randomChunk(), "
		<< "that announces itself and destroys itself"
		<< std::endl << std::endl;

	randomChunk("LeCon");
	randomChunk("Lidiot");

	// 3. Create Zombie "Labruti" (2) with newZombie(), then announce first
	// "Labruti" (2) then "LeDebile" (1)
	
	std::cout << std::endl
		<< "3. Create Zombie \"Labruti\" (2) with newZombie(), then announce "
		<< "first \"Labruti\" (2) then \"LeDebile\" (1)"
		<< std::endl << std::endl;

	Zombie*	Labruti	= newZombie("Labruti");

	Labruti->announce();
	LeDebile->announce();

	// 8. Delete all objects

	std::cout << std::endl
		<< "4. Delete all objects"
		<< std::endl << std::endl;

	delete LeDebile;
	delete Labruti;
}

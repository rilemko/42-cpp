/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 20:01:04 by mconreau          #+#    #+#             */
/*   Updated: 2024/03/26 20:15:10 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

#define	N 	12

int
main(void)
{
	// 1. Create Zombie Horde of N "leCon" with zombieHorde()
	
	std::cout
		<< "1. Create Zombie Horde of N (" << N << ") \"leCon\" with "
		<< "zombieHorde()"
		<< std::endl;
	
	Zombie*	Horde		= zombieHorde(N, "LeCon");

	// 2. Announce each
	
	std::cout
		<< "2. Announce each"
		<< std::endl << std::endl;

	for (int i = 0; i < N; i++)
		Horde[i].announce();
	
	// 8. Delete all objects

	std::cout << std::endl
		<< "3. Delete all objects"
		<< std::endl << std::endl;

	delete[] Horde;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 20:01:04 by mconreau          #+#    #+#             */
/*   Updated: 2024/03/26 21:16:50 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int
main(void)
{
	ClapTrap	clap("LeCon");
	ScavTrap	scav("R2D2");

	scav.attack("en l'air");
	scav.guardGate();
	for (int i = 0; i < 8; i++)
		clap.attack("R2D2");
	clap.takeDamage(6);
	clap.beRepaired(2);
	clap.attack("R2D2");
	clap.attack("R2D2");
	scav.attack("leCon");
	clap.takeDamage(20);
	clap.attack("R2D2");
}

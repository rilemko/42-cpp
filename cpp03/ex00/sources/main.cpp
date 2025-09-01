/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 20:01:04 by mconreau          #+#    #+#             */
/*   Updated: 2024/03/26 21:11:57 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

int
main(void)
{
	ClapTrap	clap("leCon");

	for (int i = 0; i < 8; i++)
		clap.attack("Tac");
	clap.takeDamage(6);
	clap.beRepaired(2);
	clap.attack("Tac");
	clap.attack("Tac");
	clap.takeDamage(8);
	clap.attack("Tac");
}

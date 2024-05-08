/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 22:11:29 by mconreau          #+#    #+#             */
/*   Updated: 2024/03/26 21:19:13 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class ClapTrap
{
	protected:
		unsigned int		_attackPoints;
		unsigned int		_energyPoints;
		unsigned int		_lifePoints;
		std::string			_name;

	public   :
							ClapTrap(std::string name);
							ClapTrap(const ClapTrap& src);
							~ClapTrap();

		void				attack(const std::string& target);
		void				beRepaired(unsigned int amount);
		void				takeDamage(unsigned int amount);

		ClapTrap&			operator=(const ClapTrap& rhs);
};

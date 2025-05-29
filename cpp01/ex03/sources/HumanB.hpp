/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 20:53:55 by mconreau          #+#    #+#             */
/*   Updated: 2024/03/26 20:24:29 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Weapon.hpp"
#include <iostream>

class   HumanB
{
	private  :
		std::string		_name;
		Weapon*			_weapon;

    public   :
    					HumanB(std::string name);
						~HumanB(void);

		void			attack(void) const;
		void			setWeapon(Weapon& weapon);
};

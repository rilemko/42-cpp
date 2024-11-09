/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 20:53:57 by mconreau          #+#    #+#             */
/*   Updated: 2024/03/26 20:24:01 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Weapon.hpp"
#include <iostream>

class   HumanA
{
	private  :
		std::string		_name;
		Weapon*			_weapon;

    public   :
    					HumanA(std::string name, Weapon& weapon);
						~HumanA(void);

		void			attack(void) const;
		void			setWeapon(Weapon& weapon);
};

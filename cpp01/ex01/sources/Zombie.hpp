/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 21:00:19 by mconreau          #+#    #+#             */
/*   Updated: 2024/03/26 20:19:26 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class   Zombie
{
	private  :
		std::string		_name;

    public   :
    					Zombie(void);
						~Zombie(void);

		void			announce(void) const;
		void			rename(std::string name);
};

Zombie*	zombieHorde(int N, std::string name);

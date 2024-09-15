/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 21:00:19 by mconreau          #+#    #+#             */
/*   Updated: 2024/03/26 20:11:38 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class   Zombie
{
	private  :
		std::string		_name;

    public   :
    					Zombie(std::string name);
						~Zombie(void);

		void			announce(void) const;
};

Zombie*	newZombie(std::string name);
void	randomChunk(std::string name);

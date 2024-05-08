/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 22:11:29 by mconreau          #+#    #+#             */
/*   Updated: 2024/03/26 21:28:51 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ClapTrap.hpp"
#include <iostream>
#include <string>

class FragTrap : virtual public ClapTrap
{	
	public   :
							FragTrap(std::string);
							~FragTrap();

		void				highFivesGuys(void);
};

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 20:53:59 by mconreau          #+#    #+#             */
/*   Updated: 2024/03/26 20:25:08 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class   Weapon
{
	private  :
		std::string			_type;

    public   :
    						Weapon(std::string type);
							~Weapon(void);

		const std::string&	getType(void) const;
		void				setType(std::string tupe);
};

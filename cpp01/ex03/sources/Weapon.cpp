/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 20:54:08 by mconreau          #+#    #+#             */
/*   Updated: 2024/03/26 20:25:25 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type) :
	_type(type)
{
}

Weapon::~Weapon(void)
{
}

const std::string&
Weapon::getType(void) const
{
	return (this->_type);
}

void
Weapon::setType(std::string type)
{
	this->_type = type;
}

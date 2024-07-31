/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 14:39:08 by mconreau          #+#    #+#             */
/*   Updated: 2024/03/26 22:14:00 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(const std::string &type) :
	_type(type)
{
}

AMateria::AMateria(const AMateria &src)
{
	*this = src;
}

AMateria::~AMateria(void)
{
}

const std::string&
AMateria::getType(void) const
{
	return (this->_type);
}

void	
AMateria::use(ICharacter &target)
{
	std::cout << "Amateria : \"* used on "
		<< target.getName() << " *\"" << std::endl;
}

AMateria&
AMateria::operator=(const AMateria& rhs)
{
	this->_type = rhs._type;
	return (*this);
}

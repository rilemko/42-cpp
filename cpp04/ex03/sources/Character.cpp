/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 14:39:08 by mconreau          #+#    #+#             */
/*   Updated: 2024/03/26 22:13:54 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(std::string name) :
	_name(name)
{
	for (int i = 0; i < 4; i++)
		this->_materias[i] = NULL;
}

Character::Character(const Character &src)
{
	for (int i = 0; i < 4; i++)
		this->_materias[i] = NULL;
	*this = src;
}

Character::~Character(void)
{
	for (int i = 0; i < 4; i++)
		delete this->_materias[i];
}

void
Character::equip(AMateria* m)
{
	for (int i = 0; i < 4; i++)
		if (this->_materias[i] == NULL)
			return (this->_materias[i] = m, (void) NULL);
}

AMateria*
Character::getMateria(int idx)
{
	if (idx >= 0 && idx <= 3)
		return (this->_materias[idx]);
	return (NULL);
}

const std::string&
Character::getName() const
{
	return (this->_name);
}

void
Character::unequip(int idx)
{
	if (idx >= 0 && idx <= 3)
		this->_materias[idx] = NULL;
}

void
Character::use(int idx, ICharacter& target)
{
	if ((idx >= 0 && idx <= 3) && this->_materias[idx] != NULL)
		this->_materias[idx]->use(target);
}

Character&
Character::operator=(const Character& rhs)
{
	for (int i = 0; i < 4; i++)
	{
		delete this->_materias[i];
		if (rhs._materias[i] != NULL)
			this->_materias[i] = rhs._materias[i]->clone();
	}
	this->_name = rhs._name;
	return (*this);
}

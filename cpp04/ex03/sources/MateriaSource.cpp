/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 14:39:08 by mconreau          #+#    #+#             */
/*   Updated: 2024/03/26 22:08:51 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void)
{
	for (int i = 0; i < 4; i++)
		this->_materias[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& src)
{
	for (int i = 0; i < 4; i++)
		this->_materias[i] = NULL;
	*this = src;
}

MateriaSource::~MateriaSource(void)
{
	for (int i = 0; i < 4; i++)
		delete this->_materias[i];
}

AMateria*
MateriaSource::createMateria(const std::string& type)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_materias[i] != NULL && type == this->_materias[i]->getType())
			return (this->_materias[i]->clone());
	}
	return (NULL);
}

void
MateriaSource::learnMateria(AMateria* m)
{
	for (int i = 0; i < 4; i++)
		if (this->_materias[i] == NULL)
			return (this->_materias[i] = m, (void) NULL);
}

MateriaSource&
MateriaSource::operator=(const MateriaSource& rhs)
{
	for (int i = 0; i < 4; i++)
	{
		delete this->_materias[i];
		this->_materias[i] = NULL;
		if (rhs._materias[i] != NULL)
			this->_materias[i] = rhs._materias[i]->clone();
	}
	return (*this);
}

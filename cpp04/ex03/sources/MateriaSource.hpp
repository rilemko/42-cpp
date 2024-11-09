/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 16:25:10 by mconreau          #+#    #+#             */
/*   Updated: 2024/03/26 22:08:44 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "IMateriaSource.hpp"

class	MateriaSource : public IMateriaSource
{
	protected:
		AMateria*			_materias[4];

	public   :
							MateriaSource(void);
							MateriaSource(const MateriaSource& src);
							~MateriaSource(void);

		AMateria*			createMateria(const std::string& type);
		void				learnMateria(AMateria *);

		MateriaSource&		operator=(const MateriaSource& rhs);
};

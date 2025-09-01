/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 16:25:10 by mconreau          #+#    #+#             */
/*   Updated: 2024/03/26 22:02:57 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "ICharacter.hpp"

class	Character : public ICharacter
{
	protected:
		AMateria*			_materias[4];
		std::string			_name;

	public   :
							Character(std::string name);
							Character(const Character& src);
							~Character(void);

		void				equip(AMateria* m);
		AMateria*			getMateria(int idx);
		const std::string&	getName() const;
		void				unequip(int idx);
		void				use(int idx, ICharacter& target);

		Character&			operator=(const Character& rhs);
};

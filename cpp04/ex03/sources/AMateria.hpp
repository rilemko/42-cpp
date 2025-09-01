/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 14:33:42 by mconreau          #+#    #+#             */
/*   Updated: 2024/03/26 21:59:22 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ICharacter.hpp"
#include <iostream>

class	ICharacter;

class	AMateria
{
	protected:
		std::string			_type;

	public   :
							AMateria(const std::string& type);
							AMateria(const AMateria& src);
		virtual				~AMateria(void) = 0;
		
		virtual AMateria*	clone(void) const = 0;
		const std::string&	getType(void) const;
		virtual void		use(ICharacter&);

		AMateria&			operator=(const AMateria& rhs);
};

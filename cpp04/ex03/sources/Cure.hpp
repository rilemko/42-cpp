/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 14:33:42 by mconreau          #+#    #+#             */
/*   Updated: 2024/03/26 22:03:55 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "AMateria.hpp"

class	Cure : public AMateria
{
	public   :
							Cure(void);
							~Cure(void);
		
		AMateria*			clone(void) const;
		void				use(ICharacter& target);

};

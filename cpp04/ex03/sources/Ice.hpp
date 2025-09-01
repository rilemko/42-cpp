/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 14:33:42 by mconreau          #+#    #+#             */
/*   Updated: 2024/03/26 22:04:13 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "AMateria.hpp"

class	Ice : public AMateria
{
	public:
							Ice(void);
							~Ice(void);
		
		AMateria*			clone(void) const;
		void				use(ICharacter& target);

};

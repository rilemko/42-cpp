/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 16:25:10 by mconreau          #+#    #+#             */
/*   Updated: 2024/03/26 22:06:40 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "AMateria.hpp"

class	IMateriaSource
{
	public   :
		virtual				~IMateriaSource(void) {}

		virtual void		learnMateria(AMateria* m) = 0;
		virtual AMateria*	createMateria(const std::string& type) = 0;
};

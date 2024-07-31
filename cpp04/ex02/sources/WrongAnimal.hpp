/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 15:07:15 by mconreau          #+#    #+#             */
/*   Updated: 2024/03/26 21:34:39 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class WrongAnimal
{
	protected:
		std::string		_type;

	public   :
						WrongAnimal(void);
						WrongAnimal(const WrongAnimal& src);
		virtual			~WrongAnimal(void);

		std::string		getType(void) const;
		virtual void	makeSound(void) const;

		WrongAnimal&	operator=(const WrongAnimal& rhs);
};

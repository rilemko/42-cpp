/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 15:07:15 by mconreau          #+#    #+#             */
/*   Updated: 2024/03/26 21:54:36 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AAnimal.hpp"
#include "Brain.hpp"
#include <iostream>

class Dog : public AAnimal
{
	private  :
		Brain*			_brain;

	public   :
						Dog(void);
						~Dog(void);

		void			makeSound(void) const;

		Dog&			operator=(const Dog&);
};

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 14:32:53 by mconreau          #+#    #+#             */
/*   Updated: 2024/03/26 23:00:24 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstdlib>
#include <stdint.h>
#include <iostream>
#include "Data.hpp"

class Serializer
{
	private  :
							Serializer();
							Serializer(const Serializer& src);
							~Serializer();

		Serializer&			operator=(const Serializer& rhs);
	
	public   :

		static Data*		deserialize(uintptr_t raw);
		static uintptr_t	serialize(Data* ptr);
};

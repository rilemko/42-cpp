/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 14:32:53 by mconreau          #+#    #+#             */
/*   Updated: 2024/03/26 23:06:52 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstdlib>
#include <exception>
#include <iomanip>
#include <iostream>

template<typename T>
class Array
{
	private  :
		T*				_array;
		unsigned int	_array_size;

	public   :

						Array(unsigned int = 0);
						Array(const Array& src);
						~Array();
	
		unsigned int 	size() const;

		Array& 			operator=(const Array& rhs);
		const T& 		operator[](unsigned int index) const;
		T& 				operator[](unsigned int index);
};

template <typename T>
std::ostream&	operator<<(std::ostream& ostream, const Array<T>& rhs);

#include "Array.tpp"

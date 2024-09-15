/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 14:32:53 by mconreau          #+#    #+#             */
/*   Updated: 2024/03/26 23:03:46 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstdlib>
#include <iostream>

template<typename T>
void
display(T& element)
{
	std::cout << element << std::endl;
}

template<typename T>
void
increment(T& element)
{
	element++;
}

template<typename T>
void
iter(T* tab, size_t size, void (*callback)(T&))
{
	for (size_t i = 0; i < size; i++)
		callback(tab[i]);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 14:32:53 by mconreau          #+#    #+#             */
/*   Updated: 2024/03/26 23:10:44 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstdlib>
#include <iostream>

template<typename T>
void
swap(T& a, T& b)
{
	T	tmp = a;
	a = b;
	b = tmp;
}

template<typename T>
T
min(T& a, T& b)
{
	return (a < b ? a : b);
}

template<typename T>
T
max(T& a, T& b)
{
	return (a > b ? a : b);
}

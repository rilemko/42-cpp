/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 14:32:53 by mconreau          #+#    #+#             */
/*   Updated: 2024/03/26 23:21:00 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstdlib>
#include <iostream>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
	public   :
		typedef typename std::stack<T>::container_type::iterator iterator;
	
						MutantStack();
						MutantStack(const MutantStack& src);
						~MutantStack();

		MutantStack& 	operator=(MutantStack& rhs);

		iterator 		begin();
		iterator 		end();
};

#include "MutantStack.tpp"

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 14:32:53 by mconreau          #+#    #+#             */
/*   Updated: 2024/03/26 23:18:37 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstdlib>
#include <exception>
#include <limits>
#include <list>
#include <iostream>

class Span
{
	private  :
		std::list<int>		_list;
		unsigned int		_maxSize;

	public   :
							Span(unsigned int = 0);
							Span(const Span& src);
							~Span();

		void 				addListed(std::list<int> list);
		void 				addNumber(int element);
		void 				addRandom(unsigned int count);
		void 				addRanged(int min, int max);
		void 				display() const;
		int					longestSpan() const;
		int 				shortestSpan() const;
		unsigned int 		size() const;

		Span& 				operator=(const Span& rhs);
};

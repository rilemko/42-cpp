/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 14:32:53 by mconreau          #+#    #+#             */
/*   Updated: 2024/05/07 14:30:20 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <ctime>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <deque>
#include <sstream>
#include <vector>

template <typename T>
class PmergeMe
{
	public   :
		typedef typename T::const_iterator iterator;
	
	private  :
		T 					_list;
		double				_time;

	public   :
							PmergeMe(T list);
							PmergeMe(const PmergeMe& src);
							~PmergeMe();

		iterator 			begin() const;
		iterator 			end() const;
		clock_t 			getTime() const;
		size_t 				getSize() const;
		void				process();
		
		PmergeMe& 			operator=(const PmergeMe& rhs);

	private:
		void				insertion(T& list, size_t start, size_t end);
		void				merge(T& list, size_t start, size_t end, size_t sub);
		void				sort(T& list, size_t start, size_t end);
		void				swap(int& nb1, int& nb2);

	public   :
		class Exception : public std::runtime_error
		{
			public   :
							Exception(const std::string &message = "PmergeMeException occured !");
		};
};

template <typename T>
std::ostream&	operator<<(std::ostream&, const PmergeMe<T>&);

#include "PmergeMe.cpp"

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 18:16:28 by mconreau          #+#    #+#             */
/*   Updated: 2024/05/07 14:30:50 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "PmergeMe.hpp"

template <typename T>
PmergeMe<T>::PmergeMe(T list) :
	_list(list), _time(0)
{
}

template <typename T>
PmergeMe<T>::PmergeMe(const PmergeMe& rhs)
{
	*this = rhs;
}

template <typename T>
PmergeMe<T>::~PmergeMe()
{
}

template <typename T>
typename PmergeMe<T>::iterator
PmergeMe<T>::begin() const
{
	return (this->_list.begin());
}

template <typename T>
typename PmergeMe<T>::iterator
PmergeMe<T>::end() const
{
	return (this->_list.end());
}

template <typename T>
clock_t
PmergeMe<T>::getTime() const
{
	return (this->_time);
}

template <typename T>
size_t
PmergeMe<T>::getSize() const
{
	return (this->_list.size());
}

template <typename T>
void
PmergeMe<T>::process()
{
	this->_time = clock();
	this->sort(this->_list, 0, this->_list.size() - 1);
	this->_time = clock() - this->_time;
}

template <typename T>
void
PmergeMe<T>::insertion(T& list, size_t start, size_t end)
{
	typename T::iterator	it1 = list.begin(), it2 = list.begin();

	std::advance(it1, start);
	std::advance(it2, end);
	if (*it1 > *it2)
		this->swap(*it1, *it2);
}

template <typename T>
void
PmergeMe<T>::merge(T& list, size_t start, size_t end, size_t sub)
{
	size_t index1 = sub - start + 1, index2 = end - sub;
	size_t indexL = 0, indexR = 0;
	
	T listL(list.begin() + start, list.begin() + sub + 1);
	T listR(list.begin() + sub + 1, list.begin() + end + 1);

	for (size_t i = start; i <= end; ++i)
	{
		if (indexR == index2 || (indexL != index1 && listL[indexL] <= listR[indexR]))
			list[i] = listL[indexL++];
		else
			list[i] = listR[indexR++];
	}
}

template <typename T>
void
PmergeMe<T>::sort(T& list, size_t start, size_t end)
{
	if (start < end)
	{
		if (end - start < 2)
			this->insertion(list, start, end);
		else
		{
			size_t	sub = start + (end - start) / 2;
			sort(list, start, sub);
			sort(list, sub + 1, end);
			merge(list, start, end, sub);
		}
	}
}

template <typename T>
void
PmergeMe<T>::swap(int& nb1, int& nb2)
{
	int	tmp = nb1;
	nb1 = nb2;
	nb2 = tmp;
}

template <typename T>
PmergeMe<T>&
PmergeMe<T>::operator=(const PmergeMe& rhs)
{
	this->_list = rhs._list;
	this->_time = rhs._time;
	return (*this);
}

template <typename T>
PmergeMe<T>::Exception::Exception(const std::string &message) :
	std::runtime_error(message)
{
}

template <typename T>
std::ostream&
operator<<(std::ostream& ostream, const PmergeMe<T>& rhs)
{
	ostream << "{";
	for (typename T::const_iterator it = rhs.begin(); it != rhs.end(); it++)
		ostream << std::setw(4) << *it << (it + 1 != rhs.end() ? ", " : "");
	ostream << "}";
	return (ostream);
}

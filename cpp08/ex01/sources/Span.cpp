/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 18:16:28 by mconreau          #+#    #+#             */
/*   Updated: 2024/03/26 23:18:27 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int n) :
	_maxSize(n)
{
}

Span::Span(const Span& src)
{
	*this = src;
}

Span::~Span()
{
}

void
Span::addListed(std::list<int> list)
{
	for (std::list<int>::const_iterator it = list.begin(); it != list.end(); it++)
		this->addNumber(*it);
}

void
Span::addNumber(int element)
{
	if (this->_list.size() == this->_maxSize)
		throw std::runtime_error("std::runtime_error : Too many element.");
	this->_list.push_back(element);
}

void
Span::addRandom(unsigned int count)
{
	srand(time(NULL));
	for (size_t i = 0; i < count; i++)
		this->addNumber(rand() % 1000000);
}

void
Span::addRanged(int min, int max)
{
	for (int i = std::min(min, max); i < std::max(min, max); i++)
		this->addNumber(i);
}

void
Span::display() const
{
	std::cout << "{";
	for (std::list<int>::const_iterator it = this->_list.begin(); it != this->_list.end(); it++)
		std::cout << *it << (it != --this->_list.end() ? ", " : "");
	std::cout << "}" << std::endl;
}

int
Span::longestSpan() const
{
	if (this->_list.size() < 2)
		throw std::runtime_error("std::runtime_error : Not enough element.");
	
	size_t	span = 0, temp;

	for (std::list<int>::const_iterator it1 = this->_list.begin(); it1 != this->_list.end(); it1++)
		for (std::list<int>::const_iterator it2 = this->_list.begin(); it2 != this->_list.end(); it2++)
			if (it1 != it2 && (temp = std::abs(*it1 - *it2)) > span)
				span = temp;
	return (span);
}

int
Span::shortestSpan() const
{
	if (this->_list.size() < 2)
		throw std::runtime_error("std::runtime_error : Not enough element.");

	size_t	span = std::numeric_limits<int>::max(), temp;

	for (std::list<int>::const_iterator it1 = this->_list.begin(); it1 != this->_list.end(); it1++)
		for (std::list<int>::const_iterator it2 = this->_list.begin(); it2 != this->_list.end(); it2++)
			if (it1 != it2 && (temp = std::abs(*it1 - *it2)) < span)
				span = temp;
	return (span);
}

unsigned int
Span::size() const
{
	return (this->_list.size());
}

Span&
Span::operator=(const Span& src)
{
	this->_list = src._list;
	this->_maxSize = src._maxSize;
	return (*this);
}

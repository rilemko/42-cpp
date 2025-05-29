/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 21:10:35 by mconreau          #+#    #+#             */
/*   Updated: 2024/03/26 18:33:10 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) :
	_count(0)
{
}

PhoneBook::~PhoneBook(void)
{
}

void
PhoneBook::add(void)
{
	std::cout << std::setfill('-') << std::setw(45) << "-" << std::endl;
	std::cout << "Add new contact..." << std::endl;
	this->_contacts[this->_count % 8].add(this->_count % 8);
	std::cout << std::setfill('-') << std::setw(45) << "-" << std::endl;
	std::cout << "Contact added successfully !" << std::endl;
	this->_count++;
}

void
PhoneBook::search(void) const
{
	std::stringstream	stream;
	std::string			input;
	
	std::cout << std::setfill('-') << std::setw(45) << "-" << std::endl;
	for(int i = 0; i < 8; i++)
		this->_contacts[i].preview();
	std::cout << std::setfill('-') << std::setw(45) << "-" << std::endl;
	while ((std::cout << "What #id do you want to see (0-7) : ")
		&& (std::cin >> input))
	{
		if (input.length() == 1 && input[0] >= '0' && input[0] <= '7')
			break ;
	}
	this->_contacts[atoi(input.c_str())].show();
	std::cout << std::setfill('-') << std::setw(45) << "-" << std::endl;
}

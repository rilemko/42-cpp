/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 21:10:31 by mconreau          #+#    #+#             */
/*   Updated: 2024/03/26 20:18:42 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void)
{
	this->_exists = false;
	this->_index = 0;
}

Contact::~Contact(void)
{
}

void
Contact::add(int index)
{
	this->_exists = true;
	this->_index = index;
	this->readline("Firstname      : ", &this->_firstName);
	this->readline("Lastname       : ", &this->_lastName);
	this->readline("Nickname       : ", &this->_nickName);
	this->readline("Phone Number   : ", &this->_phoneNumber);
	this->readline("Darkest Secret : ", &this->_darkestSecret);
}

std::string
Contact::format(std::string content) const
{
	std::stringstream	stream;
	int					length;

	length = (content.length() > 10 ? 9 : 10);
	stream << std::right << std::setfill(' ') << std::setw(length);
	stream << content.substr(0, length) << (length == 9 ? "." : "");
	stream << std::flush;
	return (stream.str());
}

void
Contact::preview(void) const
{
	std::stringstream	stream;

	if (this->_exists == true)
	{
		stream << this->_index;
		std::cout << "|" << this->format(stream.str());
		std::cout << "|" << this->format(this->_firstName);
		std::cout << "|" << this->format(this->_lastName);
		std::cout << "|" << this->format(this->_nickName);
		std::cout << "|" << std::endl;
	}
}

void
Contact::readline(std::string prompt, std::string* buffer)
{
	buffer->clear();
	std::cout << prompt;
	while ((std::cin >> *buffer) && buffer->length() == 0)
		continue ; 
}

void
Contact::show(void) const
{
	if (this->_exists == true)
	{
		std::cout << "Firstname      : " << this->_firstName << std::endl;
		std::cout << "Lastname       : " << this->_lastName << std::endl;
		std::cout << "Nickname       : " << this->_nickName << std::endl;
		std::cout << "Phone Number   : " << this->_phoneNumber << std::endl;
		std::cout << "Darkest Secret : " << this->_darkestSecret << std::endl;
	}
}

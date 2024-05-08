/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 23:28:35 by mconreau          #+#    #+#             */
/*   Updated: 2024/03/26 20:32:03 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(void)
{
	this->_keys[0] = "DEBUG";
	this->_keys[1] = "INFO";
	this->_keys[2] = "WARNING";
	this->_keys[3] = "ERROR";
	this->_values[0] = &Harl::debug;
	this->_values[1] = &Harl::info;
	this->_values[2] = &Harl::warning;
	this->_values[3] = &Harl::error;
}

Harl::~Harl(void)
{
}

void
Harl::complain(std::string level)
{
	for (int i = 0; i < 4; i++)
		if (this->_keys[i].compare(level) == 0)
			return ((this->*_values[i])());
}

void
Harl::debug(void) const
{
	std::cout << "[DEBUG]" << std::endl;
	std::cout <<  "I love having extra bacon for my \
7XL-double-cheese-triple-pickle-specialketchup burger. I really do !"
		<< std::endl;
}

void
Harl::error(void) const
{
	std::cout << "[ERROR]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money. \
You didn’t put enough bacon in my burger ! If you did, I wouldn’t be asking \
for more !"
		<< std::endl;
}

void
Harl::info(void) const
{
	std::cout << "[INFO]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. I’ve \
been coming for years whereas you started working here since last month."
		<< std::endl;
}

void
Harl::warning(void) const
{
	std::cout << "[WARNING]" << std::endl;
	std::cout << "This is unacceptable ! I want to speak to the manager now."
		<< std::endl;
}

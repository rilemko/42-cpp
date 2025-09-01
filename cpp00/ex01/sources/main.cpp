/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 20:01:04 by mconreau          #+#    #+#             */
/*   Updated: 2024/03/26 19:56:24 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>

static void	ft_process(PhoneBook *PhoneBook, std::string input);

int main(void)
{
	PhoneBook	PhoneBook;
	std::string input;

	while ((std::cout << "> ") && (std::cin >> input)
		&& input.compare("EXIT") != 0)
		ft_process(&PhoneBook, input);
	return (0);
}

static void	ft_process(PhoneBook *PhoneBook, std::string input)
{
	if (input.compare("ADD") == 0)
		PhoneBook->add();
	if (input.compare("SEARCH") == 0)
		PhoneBook->search();
}

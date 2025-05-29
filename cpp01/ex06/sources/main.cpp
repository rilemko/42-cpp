/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 20:01:04 by mconreau          #+#    #+#             */
/*   Updated: 2024/03/26 20:30:34 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Harl.hpp"

int	process(std::string filter);

int
main(int argc, char** argv)
{
	if (argc == 2)
		return (process(argv[1]));
	std::cerr << "Usage: ./harlFilter [FILTER]" << std::endl;
	return (1);
}

int	process(std::string filter)
{
	Harl		Harl(filter);
	std::string	input;

	while ((std::cout << "What level do you want ? : ") && (std::cin >> input))
		Harl.complain(input);
	return (0);
}

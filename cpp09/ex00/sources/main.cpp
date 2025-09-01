/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 04:18:26 by ael-khni          #+#    #+#             */
/*   Updated: 2023/09/25 18:36:01 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int agc, char **agv)
{
	if (agc != 2)
	{
		std::cerr << "Usage: " << agv[0] << " <filename>" << std::endl;
		return (EXIT_FAILURE);
	}
	try
	{
		BitcoinExchange		btc("data.csv");
		btc.process(agv[1]);
		return (EXIT_SUCCESS);
	}
	catch(BitcoinExchange::Exception& e)
	{
		std::cerr << e.what() << std::endl;
		return (EXIT_FAILURE);
	}
}

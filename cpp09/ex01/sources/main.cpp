/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 04:18:26 by ael-khni          #+#    #+#             */
/*   Updated: 2023/09/25 18:36:13 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int agc, char **agv)
{
	if (agc != 2)
	{
		std::cerr << "Usage: " << agv[0] << " <operations...>" << std::endl;
		return (EXIT_FAILURE);
	}
	try
	{
		RPN		rpn(agv[1]);
		std::cout << rpn << std::endl;
		return (EXIT_SUCCESS);
	}
	catch(RPN::Exception& e)
	{
		std::cerr << e.what() << std::endl;
		return (EXIT_FAILURE);
	}
}

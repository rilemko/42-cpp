/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 20:01:04 by mconreau          #+#    #+#             */
/*   Updated: 2024/03/26 20:20:06 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int
main(void)
{
	std::string		original = "HI THIS IS BRAIN";
	std::string*	stringPTR = &original;
	std::string&	stringREF = original;

	std::cout << &original << " > " << original << std::endl;
    std::cout << stringPTR << " > " << *stringPTR << std::endl;
    std::cout << &stringREF << " > " << stringREF << std::endl;
}

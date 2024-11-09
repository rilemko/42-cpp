/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 04:18:26 by ael-khni          #+#    #+#             */
/*   Updated: 2024/03/26 23:21:38 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iomanip>
#include "MutantStack.hpp"

int main()
{
	// 1. Creates two MutantStack "stack1" and "stack2" and adds to stack1 5
	// string.

	std::cout
		<< "1. Creates two MutantStack \"stack1\" and \"stack2\" and add to "
		<< "stack1 5 string."
		<< std::endl;
	
	MutantStack<std::string>	stack1, stack2;

	stack1.push("str1");
	stack1.push("str2");
	stack1.push("str3");
	stack1.push("str4");
	stack1.push("str5");

	// 2. Copy "stack1" to "stack2", then iterate over "stack2" to display the
	// elements.

	std::cout
		<< "2. Copy \"stack1\" to \"stack2\", then iterate over \"stack2\" to "
		<< "display the elements."
		<< std::endl << std::endl;
	
	stack2 = stack1;
	for (MutantStack<std::string>::iterator it = stack2.begin(); it != stack2.end(); it++)
		std::cout << std::setw(4) << *it << " ";
	std::cout << std::endl;

	// 3. Display the top element with top(), remove it with pop() then
	// redisplay the elements.

	std::cout << std::endl
		<< "3. Display the top element with top(), remove it with pop() then "
		<< "redisplay the elements."
		<< std::endl << std::endl;

	std::cout << stack2.top() << std::endl;
	stack2.pop();
	for (MutantStack<std::string>::iterator it = stack2.begin(); it != stack2.end(); it++)
		std::cout << std::setw(4) << *it << " ";
	std::cout << std::endl;
}

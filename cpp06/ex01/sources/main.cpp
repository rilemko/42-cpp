/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 14:27:41 by mconreau          #+#    #+#             */
/*   Updated: 2023/09/29 15:50:58 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int	main(int agc, char **agv)
{
	// 1. Add the age 42 and the name "Test" to tha Data struct A.

	std::cout
		<< "1. Add the age 42 and the name \"Test\" to tha Data struct A."
		<< std::endl << std::endl;

	Data		A;

	A.age = 42;
	A.name = agc == 2 ? agv[1] : "Test";
	std::cout << "Data A : " << A.name << ", " << A.age << std::endl;

	// 2. Serialize the Data struct A in a data pointer.

	std::cout << std::endl
		<< "2. Serialize the Data struct A in a serialized pointer."
		<< std::endl << std::endl;

	uintptr_t ptr = Serializer::serialize(&A);
	std::cout << "Serialized : " << ptr << std::endl;

	// 3. Deserialize the pointer to the Data struct B.

	std::cout << std::endl
		<< "3. Deserialize the pointer to the Data struct B."
		<< std::endl << std::endl;

	Data* B = Serializer::deserialize(ptr);
	std::cout << "Data B : " << B->name << ", " << B->age << std::endl;
}

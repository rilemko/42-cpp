/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 15:00:57 by mconreau          #+#    #+#             */
/*   Updated: 2024/03/26 21:56:35 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>

int
main(void)
{
	// 1. Create Cat and Dog
	
	std::cout
		<< "1. Create Animal, Cat and Dog"
		<< std::endl << std::endl;

	const AAnimal*	cat	= new Cat();
	const AAnimal*	dog	= new Dog();

	// 2. Try to create Animal

	//const AAnimal	*animal	= new AAnimal();

	// 3. Check their type
	
	std::cout << std::endl
		<< "2. Check their type"
		<< std::endl << std::endl;
	
	std::cout << "Cat type : " << cat->getType() << std::endl;
	std::cout << "Dog type : " << dog->getType() << std::endl;

	// 4. Check their type
	
	std::cout << std::endl
		<< "3. Make everyone make their sound"
		<< std::endl << std::endl;

	cat->makeSound();
	dog->makeSound();

	// 5. Delete all objects

	std::cout << std::endl
		<< "4. Delete all objects"
		<< std::endl << std::endl;

	delete cat;
	delete dog;
}

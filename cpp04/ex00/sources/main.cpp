/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 15:00:57 by mconreau          #+#    #+#             */
/*   Updated: 2024/03/26 21:32:11 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main(void)
{
	// 1. Create Animal, Cat and Dog
	
	std::cout
		<< "1. Create Animal, Cat and Dog"
		<< std::endl << std::endl;

	const Animal*	animal	= new Animal();
	const Animal*	cat		= new Cat();
	const Animal*	dog		= new Dog();

	// 2. Check their type
	
	std::cout << std::endl
		<< "2. Check their type"
		<< std::endl << std::endl;
	
	std::cout << "Cat type : " << cat->getType() << std::endl;
	std::cout << "Dog type : " << dog->getType() << std::endl;

	// 3. Check their type
	
	std::cout << std::endl
		<< "3. Make everyone make their sound"
		<< std::endl << std::endl;

	animal->makeSound();
	cat->makeSound();
	dog->makeSound();

	// 4. Delete all objects

	std::cout << std::endl
		<< "4. Delete all objects"
		<< std::endl << std::endl;

	delete animal;
	delete cat;
	delete dog;

	// 5. Create WrongAnimal and WrongCat
	
	std::cout << std::endl
		<< "5. Create WrongAnimal and WrongCat"
		<< std::endl << std::endl;

	const WrongAnimal*	Wanimal	= new WrongAnimal();
	const WrongAnimal*	Wcat	= new WrongCat();

	// 6. Check their type
	
	std::cout << std::endl
		<< "6. Check their type"
		<< std::endl << std::endl;
	
	std::cout << "Cat type : " << Wcat->getType() << std::endl;

	// 7. Check their type
	
	std::cout << std::endl
		<< "7. Make everyone make their sound"
		<< std::endl << std::endl;

	Wanimal->makeSound();
	Wcat->makeSound();

	// 8. Delete all objects

	std::cout << std::endl
		<< "8. Delete all objects"
		<< std::endl << std::endl;

	delete Wanimal;
	delete Wcat;
}

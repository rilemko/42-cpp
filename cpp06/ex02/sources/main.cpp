/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 14:27:41 by mconreau          #+#    #+#             */
/*   Updated: 2024/03/26 18:00:00 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

void 	identify(Base* p);
void 	identify(Base& p);
Base*	generate();

int		main()
{
	// 1. Creates a random class among A, B or C using the generate()
	// function.

	std::cout
		<< "1. Creates a random class among A, B or C using the generate() "
		<< "function."
		<< std::endl;

	Base* Class = generate();

	// 2. Display the classname by pointer, then by reference, using the
	// identify() function.

	std::cout
		<< "2. Display the classname by pointer, then by reference, using "
		<< "the identify() function."
		<< std::endl << std::endl;

	std::cout << "By pointer   : ";
	identify(Class);
	std::cout << std::endl;
	std::cout << "By reference : ";
	identify(*Class);
	std::cout << std::endl;
	delete Class;
}


void 	identify(Base* p)
{
	std::cout << ((dynamic_cast<A*>(p) != NULL) ? "A"
		: ((dynamic_cast<B*>(p) != NULL) ? "B" : "C"));
}

void 	identify(Base& p)
{
	Base*	Base;
	
	try { return (Base = &dynamic_cast<A&>(p), std::cout << "A", (void) 0); }
	catch(...) {};
	try { return (Base = &dynamic_cast<B&>(p), std::cout << "B", (void) 0); }
	catch(...) {};
	try { return (Base = &dynamic_cast<C&>(p), std::cout << "C", (void) 0); }
	catch(...) {};
}

Base*	generate()
{
	int	random;
	
	srand(time(NULL));
	return (((random = rand() % 3) == 0) ? reinterpret_cast<Base*>(new A)
		: ((random == 1) ? reinterpret_cast<Base*>(new B)
			: reinterpret_cast<Base*>(new C)));
}

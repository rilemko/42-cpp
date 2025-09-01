/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 14:32:16 by mconreau          #+#    #+#             */
/*   Updated: 2024/03/26 22:11:50 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"

int
main(void)
{
	// 1. Create IMateriaSource and learn both Ice and Cure materia
	
	std::cout
		<< "1. Create IMateriaSource and learn both Cure and Ice materia"
		<< std::endl;
	
	AMateria*		M;
	MateriaSource*	source	= new MateriaSource();

	source->learnMateria(new Cure());
	source->learnMateria(new Ice());

	// 2. Create Character "Kevin" and equip 6 materia among existing or
	// non-existent materias

	std::cout
		<< "2. Create Character \"Kevin\" and equip 6 materia among existing "
		<< "or non-existent materias"
		<< std::endl;
	
	Character*		Kevin		= new Character("Kevin");
	
	M = source->createMateria("cure");
	Kevin->equip(M);
	M = source->createMateria("ice");
	Kevin->equip(M);
	M = source->createMateria("aaaaaaaaa");
	Kevin->equip(M);
	M = source->createMateria("cure");
	Kevin->equip(M);
	M = source->createMateria("ice");
	Kevin->equip(M);
	M = source->createMateria("bbbbbbbbb");
	Kevin->equip(M);

	// 3. Create Character "NKevin" by deep copying Character "kevin" and
	// IMateriaSource "NSource" by deep copying "source"

	std::cout
		<< "3. Create ICharacter \"NKevin\" by deep copying \"Kevin\" "
		<< "and IMateriaSource \"NSource\" by deep copying \"source\""
		<< std::endl;
	
	Character*		NKevin		= new Character(*Kevin);
	IMateriaSource*	Nsource 	= new MateriaSource(*source);

	delete Kevin;
	delete source;

	// 4. Create Character "Bobby" and equip 6 materia among existing or
	// non-existent materias with the new "Nsource"

	std::cout
		<< "4. Create Character \"Bobby\" and equip 6 materia among existing "
		<< "or non-existent materias with the new \"Nsource\""
		<< std::endl;

	Character*		Bobby		= new Character("Bobby");
	M = Nsource->createMateria("cure");
	Bobby->equip(M);
	M = Nsource->createMateria("cure");
	Bobby->equip(M);
	M = Nsource->createMateria("aaaaaaaaa");
	Bobby->equip(M);
	M = Nsource->createMateria("cure");
	Bobby->equip(M);
	M = Nsource->createMateria("cure");
	Bobby->equip(M);
	M = Nsource->createMateria("bbbbbbbbb");
	Bobby->equip(M);

	// 5. Use all 4 "NKevin" equiped materia from index 0 to 3 and non-existent
	// indexes -1 and 10

	std::cout
		<< "5. Use all 4 \"NKevin\" equiped materia from index 0 to 3 and "
		<< "non-existent indexes -1 and 10"
		<< std::endl << std::endl;

	NKevin->use(0, *Bobby);
	NKevin->use(1, *Bobby);
	NKevin->use(2, *Bobby);
	NKevin->use(3, *Bobby);
	NKevin->use(-1, *Bobby);
	NKevin->use(10, *Bobby);

	// 6. Unequip materia at index 2, 3, -1 and 10 and try to use them

	std::cout << std::endl
		<< "6. Unequip materia at index 2, 3, -1 and 10 and try to use them"
		<< std::endl;

	M = NKevin->getMateria(2);
	NKevin->unequip(2);
	delete M;
	M = NKevin->getMateria(3);
	NKevin->unequip(3);
	delete M;
	NKevin->unequip(-1);
	NKevin->unequip(10);
	NKevin->use(2, *Bobby);
	NKevin->use(3, *Bobby);

	// 7. Equip new materias in new order and use all 4 equiped materias
	// again

	std::cout
		<< "7. Equip new materias in new order and use all 4 equiped "
		<< "materias again"
		<< std::endl << std::endl;
	
	M = Nsource->createMateria("ice");
	NKevin->equip(M);
	M = Nsource->createMateria("cure");
	NKevin->equip(M);
	NKevin->use(0, *Bobby);
	NKevin->use(1, *Bobby);
	NKevin->use(2, *Bobby);
	NKevin->use(3, *Bobby);

	// 8. Delete all objects

	std::cout << std::endl
		<< "8. Delete all objects"
		<< std::endl;

	delete Nsource;
	delete NKevin;
	delete Bobby;
}

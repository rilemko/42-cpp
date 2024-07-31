/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 15:00:57 by mconreau          #+#    #+#             */
/*   Updated: 2024/03/26 21:51:58 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int
main(void)
{
	const Animal	*animals[2] = {
		new Cat, new Dog
	};
	for (int i = 0; i < 2; i++)
		delete animals[i];
}

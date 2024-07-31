/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 21:00:23 by mconreau          #+#    #+#             */
/*   Updated: 2024/03/26 18:33:42 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Contact.hpp"
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <sstream>

class   PhoneBook
{
	private  :
		Contact			_contacts[8];
		int				_count;

    public   :
    					PhoneBook(void);
						~PhoneBook(void);

		void			add(void);
		void			search(void) const;
};

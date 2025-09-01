/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 21:00:19 by mconreau          #+#    #+#             */
/*   Updated: 2024/03/26 20:18:34 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iomanip>
#include <iostream>
#include <sstream>

class   Contact
{
	private  :
		std::string		_darkestSecret;
		bool			_exists;
		std::string		_firstName;
		int				_index;
		std::string		_lastName;
		std::string		_nickName;
		std::string		_phoneNumber;

    public   :
    					Contact(void);
						~Contact(void);

		void			add(int index);
		void			preview(void) const;
		void			show(void) const;

	private  :
		std::string		format(std::string content) const;
		void			readline(std::string prompt, std::string* buffer);
};

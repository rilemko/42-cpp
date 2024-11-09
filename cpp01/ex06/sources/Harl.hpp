/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 23:28:41 by mconreau          #+#    #+#             */
/*   Updated: 2024/03/26 20:30:32 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class   Harl
{
	private  :
		int				_filter;
		std::string		_keys[4];
		void			(Harl::*_values[4])(void) const;

    public   :
    					Harl(std::string filter);
						~Harl(void);

		void			complain(std::string level);

	private  :
		void			debug(void) const;
		void			error(void) const;
		void			info(void) const;
		void			warning(void) const;
};

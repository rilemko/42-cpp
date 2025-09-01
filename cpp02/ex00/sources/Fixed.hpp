/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 23:28:41 by mconreau          #+#    #+#             */
/*   Updated: 2024/03/26 20:35:13 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class   Fixed
{
	private  :
		int					_value;
		static const int	_fractionBits = 8;

    public   :
    						Fixed(void);
							Fixed(const Fixed& src);
							~Fixed(void);

		int					getRawBits(void) const;
		void				setRawBits(const int raw);

		Fixed&				operator=(const Fixed& rhs);
};

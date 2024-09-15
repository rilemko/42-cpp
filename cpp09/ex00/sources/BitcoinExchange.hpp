/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 14:32:53 by mconreau          #+#    #+#             */
/*   Updated: 2024/05/07 14:29:47 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <sstream>
#include <sys/stat.h>
#include <unistd.h>

class BitcoinExchange
{
	private  :
		std::map<std::string, double>	_database;
	
	public   :
							BitcoinExchange(std::string filename);
							BitcoinExchange(const BitcoinExchange& src);
							~BitcoinExchange();

		void				process(std::string) const;

		BitcoinExchange&	operator=(const BitcoinExchange& rhs);
	
	private  :
		bool				isValidDate(std::string content) const;
		bool				isValidDeli(std::string content) const;
		bool				isValidLine(std::string content, std::string& date, std::string& deli, double& rate) const;
		bool				isValidRate(double content) const;
		void				openFile(std::fstream& istream, std::string filename) const;

	public   :
		class Exception : public std::runtime_error
		{
			public   :
							Exception(const std::string &message = "BitcoinExchangeException occured !");
		};
};

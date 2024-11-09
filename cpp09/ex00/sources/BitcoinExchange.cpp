/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 18:16:28 by mconreau          #+#    #+#             */
/*   Updated: 2024/05/07 14:30:28 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(std::string filename)
{
	std::string		content;
	size_t			index_d;
	std::fstream	istream;

	this->openFile(istream, filename);
	while (std::getline(istream, content, '\n'))
	{
		index_d = content.find(',');
		this->_database[content.substr(0, index_d)]
			= std::strtod(content.substr(index_d + 1).c_str(), NULL);
	}
	istream.close();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& src)
{
	*this = src;
}

BitcoinExchange::~BitcoinExchange()
{
}

bool
BitcoinExchange::isValidDate(std::string content) const
{
	size_t	deli1 = content.find('-'), deli2 = content.rfind('-');
	int		date_d, date_m, date_y;
	
	if (deli1 == std::string::npos || deli1 == deli2 || deli2 - deli1 != 3)
	{
		std::cerr << "Error : Invalid date format." << std::endl;
		return (false);
	}

	std::istringstream	ss_d(content.substr(deli2 + 1));
	std::istringstream	ss_m(content.substr(deli1 + 1, deli2));
	std::istringstream	ss_y(content.substr(0, deli1));

	if ((!(ss_d >> date_d) || !(ss_m >> date_m) || !(ss_y >> date_y)
		|| date_d < 1 || date_d > 31 || date_m < 1 || date_m > 12 || date_y < 0)
		|| ((date_m == 4 || date_m == 6 || date_m == 9 || date_m == 11) && date_d > 30)
		|| (date_m == 2 && ((date_y % 4 == 0 && (date_y % 100 != 0 || date_y % 400 == 0) && date_d > 29) || date_d > 28)))
	{
		std::cerr << "Error : Invalid date format." << std::endl;
		return (false);
	}
	return (true);
}

bool
BitcoinExchange::isValidDeli(std::string content) const
{
	if (content != "|")
	{
		std::cerr << "Error : Expected delimiter \"|\", found \"" << content << "\"." << std::endl;
		return (false);
	}
	return (true);
}

bool
BitcoinExchange::isValidLine(std::string content, std::string& date, std::string& deli, double& rate) const
{
	std::stringstream	stringstream(content);

	if (!(stringstream >> date >> deli >> rate))
	{
		std::cerr << "Error : Invalid line \"" << content << "\"." << std::endl;
		return (false);
	}
	return (true);
}

bool
BitcoinExchange::isValidRate(double content) const
{
	if (content <= 0 || content >= 1000)
	{
		std::cerr << "Error : "
			<< ((content < 0) ? "Not a positive rate." : "Invalid rate value.") << std::endl;
		return (false);
	}
	return (true);
}

void
BitcoinExchange::openFile(std::fstream& istream, std::string filename) const
{
	struct stat		st;

	if (stat(filename.c_str(), &st) != 0)
		throw Exception("FileNotFoundException : Cannot find file at path \"" + filename + "\".");
	if (S_ISREG(st.st_mode) == 0)
		throw Exception("InvalidFileException : File \"" + filename + "\" must be a regular file.");
	if (access(filename.c_str(), X_OK) == 0)
		throw Exception("InvalidFileException : File \"" + filename + "\" cannot be an executable.");
	if (access(filename.c_str(), R_OK) != 0)
		throw Exception("InvalidFileException : File \"" + filename + "\" must be readable.");
	istream.open(filename.c_str(), std::ios::in);
	if (!istream.is_open())
		throw Exception("InvalidFileException : Cannot open file at path \"" + filename + "\".");
	std::getline(istream, filename, '\n');
}

void
BitcoinExchange::process(std::string filename) const
{
	std::fstream	istream;
	std::string		content, date, deli;
	double			rate;

	this->openFile(istream, filename);
	while (std::getline(istream, content, '\n'))
	{
		if (this->isValidLine(content, date, deli, rate) == false
			|| this->isValidDate(date) == false
			|| this->isValidDeli(deli) == false
			|| this->isValidRate(rate) == false)
			continue;
		std::map<std::string, double>::const_iterator it = this->_database.lower_bound(date);
		std::cout << date << "  =>  " << std::setw(3) << rate << "  =  "
			<< rate * (it != this->_database.end() ?
				it->second : (!this->_database.empty()
					? (--it)->second : -1.0)) << std::endl;
	}
	istream.close();
}

BitcoinExchange&
BitcoinExchange::operator=(const BitcoinExchange &rhs)
{
	this->_database = rhs._database;
	return (*this);
}

BitcoinExchange::Exception::Exception(const std::string &message) :
	std::runtime_error(message)
{
}

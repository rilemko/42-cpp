/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mconreau <mconreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 20:01:04 by mconreau          #+#    #+#             */
/*   Updated: 2024/03/26 20:26:21 by mconreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstring>
#include <fstream>
#include <iostream>

static int	process(std::string filename, std::string search, std::string replace);

int
main(int argc, char** argv)
{
	if (argc == 4)
		return (process(argv[1], argv[2], argv[3]));
	std::cerr << "Usage: ./harl [filename] [search] [replace]" << std::endl;
	return (1);
}

static int	process(std::string filename, std::string search, std::string replace)
{
	std::string		content;
	int				index = 0;
	std::fstream	istream;
	std::fstream	ostream;

	istream.open(filename.c_str(), std::ios::in);
	if (istream.is_open())
	{
		if (std::getline(istream, content, '\0'))
		{
			while ((index = content.find(search)) != (int) std::string::npos)
			{
				content.erase(index, search.length());
				content.insert(index, replace);
			}
			ostream.open((filename + ".replace").c_str(), std::ios::out);
			if (ostream.is_open())
			{
				ostream << content;
				ostream.close();
				return (0);
			}
		}
		else
			std::cerr << "[Oooops] File empty : " << filename;
		istream.close();
	}
	else
		std::cerr << "[Oooops] Unable to the file : " << filename;
	std::cerr << std::endl;
	return (1);
}

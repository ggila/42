/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/02 15:45:09 by ggilaber          #+#    #+#             */
/*   Updated: 2015/11/03 15:44:55 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.class.hpp"
#include <cstdlib>

std::string	getline(void)
{
	std::string	str;

	std::getline(std::cin, str);
	if (std::cin.eof())
		std::exit(0);
	return (str);
}

int main(void)
{
	std::string	buf;
	Contact		book[8];
	int			i = 0;
	int			j;
	char		c;

	while (1)
	{
		std::getline(std::cin, buf);

		if (buf.compare("EXIT") == 0)
			break;

		else if (buf.compare("ADD") == 0) {
			book[i % 8].define(i);
			i++;
		}

		else if (buf.compare("SEARCH") == 0) {
			j = -1;
			while (++j < 8 && book[j].index > 0)
				book[j].display();
			std::cout << "look for: ";
			std::cin >> c;
			if (std::cin.eof())
				std::exit(0);
			if (c >= '1' && c <= '8' && book[c - '1'].index > 0)
				book[c - '1'].displayall();
		}
		//ctrl_d // std::cin.clear
	}
	return (0);
}

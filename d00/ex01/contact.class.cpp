/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/02 15:19:17 by ggilaber          #+#    #+#             */
/*   Updated: 2015/11/03 15:40:42 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.class.hpp"

Contact::Contact(void) : index(0) {
}

void	Contact::define(int i)
{
	this->index = i % 8 + 1;
	std::cout << "first name:" << std::endl;
	this->first_name = getline();
	std::cout << "last name:" << std::endl;
	this->last_name = getline();
	std::cout << "nickname:" << std::endl;
	this->nickname = getline();
	std::cout << "login:" << std::endl;
	this->login = getline();
	std::cout << "postal address:" << std::endl;
	this->postal = getline();
	std::cout << "email:" << std::endl;
	this->email = getline();
	std::cout << "phone:" << std::endl;
	this->phone = getline();
	std::cout << "birthday:" << std::endl;
	this->birthday = getline();
	std::cout << "favorite meal:" << std::endl;
	this->meal = getline();
	std::cout << "underwear color:" << std::endl;
	this->underwear = getline();
	std::cout << "darkest secret:" << std::endl;
	this->secret = getline();
	std::cout << std::endl;
}

void	Contact::displayall(void) const
{
	std::cout << std::endl;
	std::cout << "first name: " << this->first_name << std::endl;
	std::cout << "last name: " << this->last_name << std::endl;
	std::cout << "nickname: " << this->nickname << std::endl;
	std::cout << "login: " << this->login << std::endl;
	std::cout << "postal address: " << this->postal << std::endl;
	std::cout << "email: " << this->email << std::endl;
	std::cout << "phone: " << this->phone << std::endl;
	std::cout << "birthday: " << this->birthday << std::endl;
	std::cout << "favorite meal: " << this->meal << std::endl;
	std::cout << "underwear color: " << this->underwear << std::endl;
	std::cout << "darkest secret: " << this->secret << std::endl;
	std::cout << std::endl;
}


void	Contact::_printfield(std::string str) const
{
	int	i = 10;

	if (str.size() > 10) {
		std::cout << str.substr(0, 9) << ".|";
	}
	else {
		i -= str.size();
		while (i--)
			std::cout << " ";
		std::cout << str;
		std::cout << "|";
	}
}

void	Contact::display(void) const
{
	std::cout << "         " << this->index << "|";
	Contact::_printfield(this->first_name);
	Contact::_printfield(this->last_name);
	Contact::_printfield(this->nickname);
	std::cout << std::endl;
}

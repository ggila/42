/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PowerFist.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/07 17:53:17 by ggilaber          #+#    #+#             */
/*   Updated: 2015/11/07 18:02:42 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include "PowerFist.hpp"

std::string const		PowerFist::_defaultName = "Power Fist";
int const				PowerFist::_defaultDamage = 50;
int const				PowerFist::_defaultAPCost = 8;
std::string const		PowerFist::_defaultMsg = "* pschhh... SBAM! *";

PowerFist::PowerFist() :
AWeapon(PowerFist::_defaultName, PowerFist::_defaultAPCost,
	PowerFist::_defaultDamage)
{
	std::cout << "[PowerFist]() constructor called!" << std::endl;
	this->_msg = PowerFist::_defaultMsg;
	return ;
}

PowerFist::PowerFist(PowerFist const &src) :
	AWeapon(src.getName(), src.getAPCost(), src.getDamage())
{
	std::cout << "[PowerFist](src) constructor called!" << std::endl;
	this->_msg = src.getMsg();
	return ;
}

PowerFist::~PowerFist()
{std::cout << "~[PowerFist]() destructor called!" << std::endl;}

PowerFist				&PowerFist::operator=(PowerFist const &rhs)
{
	std::cout << "[PowerFist]= called!" << std::endl;
	AWeapon::operator = (rhs);
	return *this;
}

void					PowerFist::attack(void) const
{std::cout << this->getMsg() << std::endl;}

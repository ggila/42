/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PlasmaRifle.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/07 17:54:00 by ggilaber          #+#    #+#             */
/*   Updated: 2015/11/07 18:04:53 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include "PlasmaRifle.hpp"

std::string const		PlasmaRifle::_defaultName = "Plasma Rifle";
int const				PlasmaRifle::_defaultDamage = 21;
int const				PlasmaRifle::_defaultAPCost = 5;
std::string const		PlasmaRifle::_defaultMsg = "* piouuu piouuu piouuu *";

PlasmaRifle::PlasmaRifle() :
	AWeapon(PlasmaRifle::_defaultName, PlasmaRifle::_defaultAPCost,
	PlasmaRifle::_defaultDamage)
{
	std::cout << "[PlasmaRifle]() constructor called!" << std::endl;
	this->_msg = PlasmaRifle::_defaultMsg;
	return ;
}

PlasmaRifle::PlasmaRifle(PlasmaRifle const &src) :
	AWeapon(src.getName(), src.getAPCost(), src.getDamage())
{
	std::cout << "[PlasmaRifle](src) constructor called!" << std::endl;
	this->_msg = src.getMsg();
	return ;
}

PlasmaRifle::~PlasmaRifle()
{std::cout << "~[PlasmaRifle]() destructor called!" << std::endl;}

PlasmaRifle				&PlasmaRifle::operator=(PlasmaRifle const &rhs)
{
	std::cout << "[PlasmaRifle]= called!" << std::endl;
	AWeapon::operator = (rhs);
	return (*this);
}

void					PlasmaRifle::attack(void) const
{std::cout << this->getMsg() << std::endl;}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperMutant.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/07 17:48:35 by ggilaber          #+#    #+#             */
/*   Updated: 2015/11/07 17:58:52 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include "SuperMutant.hpp"

std::string const	SuperMutant::_typeName = "Super Mutant";
int const			SuperMutant::_baseHp = 170;
std::string const	SuperMutant::_birthMsg = "Gaaah. Me want smash heads !";
std::string const	SuperMutant::_deathMsg = "Aaargh ...";

SuperMutant::SuperMutant() :
	Enemy(SuperMutant::_baseHp, SuperMutant::_typeName)
{std::cout << SuperMutant::_birthMsg << std::endl;}

SuperMutant::SuperMutant(SuperMutant const & src) :
	Enemy(src.getHp(), src.getType())
{std::cout << "[SuperMutant](src) constructor called!" << std::endl;}

SuperMutant::~SuperMutant()
{std::cout << SuperMutant::_deathMsg << std::endl;}

SuperMutant		&SuperMutant::operator=(SuperMutant const &rhs)
{
	std::cout << "[SuperMutant]= called!" << std::endl;
	Enemy::operator = (rhs);
	return *this;
}

void			SuperMutant::takeDamage(int amount)
{
	amount -= 3;
	std::cout << this->_type << " lost ";
	if (amount > 0)
	{
		std::cout << amount;
		this->_hp -= amount;
		if (this->_hp < 0)
			this->_hp = 0;
	}
	else
		std::cout << '0';
	std::cout << "hp. (" << this->_hp << ")" << std::endl;
}

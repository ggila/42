/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/07 16:42:47 by ggilaber          #+#    #+#             */
/*   Updated: 2015/11/07 16:44:40 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include "NinjaTrap.hpp"

NinjaTrap::NinjaTrap() :
	ClapTrap()
{
	std::cout << "Ninja Constructor called" <<
		std::endl;
	this->loadDefaultStats();
	return ;
}
NinjaTrap::NinjaTrap(std::string const &name) :
	ClapTrap(name)
{
	std::cout << "Ninja Constructor(name) called" <<
		std::endl;
	this->loadDefaultStats();
	return ;
}
NinjaTrap::NinjaTrap(NinjaTrap const & src) :
	ClapTrap(src)
{
	std::cout << "Ninja Constructor(copy) called" <<
		std::endl;
	this->loadDefaultStats();
	return ;
}

NinjaTrap::~NinjaTrap()
{
	std::cout << "Destructor called" << std::endl;
	return ;
}
NinjaTrap            &NinjaTrap::operator=(NinjaTrap const &rhs)
{
	std::cout << "= overload called (ninja)" << std::endl;
	ClapTrap::operator = (rhs);
	return (*this);
}

void				NinjaTrap::ninjaShoebox(FragTrap &target)
{
	std::cout << "<NINJ4-TP>"<< this->_name << " quiet steps in the shadows "
		<< target.getName() << " for " <<
		this->getMeleeDamage() + 25 << " damages." << std::endl;
	target.takeDamage(this->getMeleeDamage() + 25);
	return ;
}
void				NinjaTrap::ninjaShoebox(ScavTrap &target)
{
	std::cout << "<NINJ4-TP>"<< this->_name << " cowers in fear seeing " <<
		target.getName() << "'s beauty." << std::endl;
	return ;
}
void				NinjaTrap::ninjaShoebox(NinjaTrap &target)
{
	std::cout << "<NINJ4-TP>"<< this->_name << " throw a nail at " <<
		target.getName() << " for " <<
		this->getRangedDamage() + 3 << " damages." << std::endl;
	target.takeDamage(this->getRangedDamage() + 3);
	return ;
}
void				NinjaTrap::loadDefaultStats(void)
{
	this->_hp = 60;
	this->_hpMax = 60;
	this->_mana = 120;
	this->_manaMax = 120;
	this->_level = 1;
	this->_meleeDamage = 60;
	this->_rangedDamage = 5;
	this->_armorReduction = 0;
	this->_class = "NINJ4";
	return ;
}

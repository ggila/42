/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/07 15:32:50 by ggilaber          #+#    #+#             */
/*   Updated: 2015/11/07 16:31:52 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include "ScavTrap.hpp"

void				ScavTrap::_clg(std::string const &target, std::string const &mess) const
{
	std::cout << "<SC4V-TP>"<< this->_name << ": " << mess << " " << target <<
		"!" << std::endl;
	return;
}
void				ScavTrap::clg_here(std::string const &target) const
{this->_clg(target, "come here !");}
void				ScavTrap::clg_on(std::string const &target) const
{this->_clg(target, "come on !");}
void				ScavTrap::clg_fight(std::string const &target) const
{this->_clg(target, "come and fight !");}
void				ScavTrap::clg_back(std::string const &target) const
{this->_clg(target, "come back !");}

ScavTrap::clg		ScavTrap::clg_tab[4] =
{
	&ScavTrap::clg_here,
	&ScavTrap::clg_on,
	&ScavTrap::clg_fight,
	&ScavTrap::clg_back
};

ScavTrap::ScavTrap() : ClapTrap::ClapTrap()
{
	std::cout << "ScavTrap constructor called" <<
		std::endl;
	return ;
}

ScavTrap::ScavTrap(std::string const &name) : ClapTrap::ClapTrap(name)
{
	std::cout << "ScavTrap constructor(name) called" <<
		std::endl;
	return ;
}

ScavTrap::ScavTrap(ScavTrap const & src) : ClapTrap::ClapTrap(src)
{
	std::cout << "ScavTrap constructor(copy) called" <<
		std::endl;
	return ;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called" << std::endl;
	return ;
}

ScavTrap			&ScavTrap::operator=(ScavTrap const &rhs)
{
	std::cout << "= overload called (scav)" << std::endl;
	this->_hp = rhs.getHp();
	this->_hpMax = rhs.getHpMax();
	this->_mana = rhs.getMana();
	this->_manaMax = rhs.getManaMax();
	this->_level = rhs.getLevel();
	this->_meleeDamage = rhs.getMeleeDamage();
	this->_rangedDamage = rhs.getRangedDamage();
	this->_armorReduction = rhs.getArmorReduction();
	return (*this);
}
void				ScavTrap::challengeNewcomer(std::string const &target)
{
	(this->*ScavTrap::clg_tab[rand() % 4])(target);
	return ;
}

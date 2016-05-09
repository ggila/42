/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/07 15:32:50 by ggilaber          #+#    #+#             */
/*   Updated: 2015/11/07 15:47:38 by ggilaber         ###   ########.fr       */
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

ScavTrap::ScavTrap() :
_name("Unknown"), _hp(100), _hpMax(100), _mana(50), _manaMax(50), _level(1),
_meleeDamage(20), _rangedDamage(15), _armorReduction(3)
{
	std::cout << "Constructor called, Scav operational." <<
		std::endl;
	return ;
}

ScavTrap::ScavTrap(std::string const &name) :
_name(name), _hp(100), _hpMax(100), _mana(50), _manaMax(50), _level(1),
_meleeDamage(20), _rangedDamage(15), _armorReduction(3)
{
	std::cout << "Constructor(name) called, Scav ready to fight!" <<
		std::endl;
	return ;
}

ScavTrap::ScavTrap(ScavTrap const & src) :
	_name(src._name), _hp(src._hp), _hpMax(src._hpMax),
	_mana(src._mana), _manaMax(src._manaMax), _level(src._level),
	_meleeDamage(src._meleeDamage), _rangedDamage(src._rangedDamage),
	_armorReduction(src._armorReduction)
{
	std::cout << "Constructor(copy) called, Scav ready to guard!" <<
		std::endl;
	return ;
}

ScavTrap::~ScavTrap()
{
	std::cout << "Destructor called, It's just a flesh wound!" << std::endl;
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

std::string const	&ScavTrap::getName(void) const
{return (this->_name);}
unsigned int		ScavTrap::getHpMax(void) const
{return (this->_hpMax);}
unsigned int		ScavTrap::getHp(void) const
{return (this->_hp);}
unsigned int		ScavTrap::getMana(void) const
{return (this->_mana);}
unsigned int		ScavTrap::getManaMax(void) const
{return (this->_manaMax);}
unsigned int		ScavTrap::getLevel(void) const
{return (this->_level);}
unsigned int		ScavTrap::getMeleeDamage(void) const
{return (this->_meleeDamage);}
unsigned int		ScavTrap::getRangedDamage(void) const
{return (this->_rangedDamage);}
unsigned int		ScavTrap::getArmorReduction(void) const
{return (this->_armorReduction);}

void				ScavTrap::rangedAttack(std::string const &target) const
{
	std::cout << "<SC4V-TP>"<< this->_name << " ranged attacks " <<
		target << ", for " << this->_rangedDamage << " damages!" <<
		std::endl;
	return ;
}
void				ScavTrap::meleeAttack(std::string const &target) const
{
	std::cout << "<SC4V-TP>"<< this->_name << " melee attacks " <<
		target << ", for " << this->_meleeDamage << " damages!" <<
		std::endl;
	return ;
}
void				ScavTrap::takeDamage(unsigned int amount)
{
	std::cout << "<SC4V-TP>"<< this->_name;
	if (amount <= this->_armorReduction)
		std::cout << " resists ";
	else
	{
		amount -= this->_armorReduction;
		std::cout << " takes " << amount << " damages ";
		if (amount >= this->_hp)
			this->_hp = 0;
		else
			this->_hp -= amount;
	}
	std::cout << "(" << this->_hp << "/" << this->_hpMax << ")" << std::endl;
	return ;
}
void				ScavTrap::beRepaired(unsigned int amount)
{
	this->_hp += amount;
	if (this->_hp > this->_hpMax)
		this->_hp = this->_hpMax;
	std::cout << "<SC4V-TP>"<< this->_name << " gains " << amount <<
		" health points!" << "(" << this->_hp << "/" << this->_hpMax <<
		")" << std::endl;
	return ;
}

void				ScavTrap::challengeNewcomer(std::string const &target)
{
	(this->*ScavTrap::clg_tab[rand() % 4])(target);
	return ;
}

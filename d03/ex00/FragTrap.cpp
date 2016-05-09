/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/07 12:49:48 by ggilaber          #+#    #+#             */
/*   Updated: 2015/11/07 15:19:33 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include "FragTrap.hpp"


FragTrap::func			FragTrap::tab[5] =
{
	&FragTrap::blueAttack,
	&FragTrap::redAttack,
	&FragTrap::greenAttack,
	&FragTrap::whiteAttack,
	&FragTrap::blackAttack
};

void				FragTrap::_randAttack(std::string const &target,
						std::string const &att) const
{
	std::cout << "<FR4G-TP>"<< this->_name << " uses " << att << " attack on " <<
		target << ", for " << this->_meleeDamage << " damages!" <<
		std::endl;
	return ;
}

void	FragTrap::blueAttack(std::string const &target) const
{this->_randAttack(target, "blue");}
void	FragTrap::redAttack(std::string const &target) const
{this->_randAttack(target, "red");}
void	FragTrap::greenAttack(std::string const &target) const
{this->_randAttack(target, "green");}
void	FragTrap::whiteAttack(std::string const &target) const
{this->_randAttack(target, "white");}
void	FragTrap::blackAttack(std::string const &target) const
{this->_randAttack(target, "black");}

FragTrap::FragTrap() : _name("Unknown"), _hp(100), _hpMax(100), _mana(100),
						_manaMax(100), _level(1), _meleeDamage(30),
						_rangedDamage(20), _armorReduction(5)
{
	std::cout << "Constructor called" <<
		std::endl;
	return ;
}

FragTrap::FragTrap(std::string const &name) : _name(name), _hp(100), _hpMax(100),
				_mana(100), _manaMax(100), _level(1), _meleeDamage(30),
				_rangedDamage(20), _armorReduction(5)
{
	std::cout << "Constructor(name) called" <<
		std::endl;
	return ;
}

FragTrap::FragTrap(FragTrap const & src) : _name(src._name), _hp(src._hp),
		_hpMax(src._hpMax),_mana(src._mana), _manaMax(src._manaMax),
		_level(src._level), _meleeDamage(src._meleeDamage),
		_rangedDamage(src._rangedDamage), _armorReduction(src._armorReduction)
{
	std::cout << "Constructor(copy) called" <<
		std::endl;
	return ;
}

FragTrap::~FragTrap()
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

FragTrap			&FragTrap::operator=(FragTrap const &rhs)
{
	std::cout << "= overload called" << std::endl;
	this->_hp = rhs._hp;
	this->_hpMax = rhs._hpMax;
	this->_mana = rhs._mana;
	this->_manaMax = rhs._manaMax;
	this->_level = rhs._level;
	this->_meleeDamage = rhs._meleeDamage;
	this->_rangedDamage = rhs._rangedDamage;
	this->_armorReduction = rhs._armorReduction;
	return (*this);
}

void				FragTrap::toString(void)
{
	std::cout << "hp:" << this->_hp
				<< " hpMax:" << this->_hpMax
				<< " mana:" << this->_mana
				<< " manaMax:" << this->_manaMax
				<< " level:" << this->_level
				<< " meleeDamage:" << this->_meleeDamage
				<< " rangedDamage:" << this->_rangedDamage
				<< " armorReduction:" << this->_armorReduction
				<< std::endl;
}

void				FragTrap::rangedAttack(std::string const &target) const
{
	std::cout << "<FR4G-TP>"<< this->_name << " ranged attacks " <<
		target << ", for " << this->_rangedDamage << " damages!" <<
		std::endl;
	return ;
}

void				FragTrap::meleeAttack(std::string const &target) const
{
	std::cout << "<FR4G-TP>"<< this->_name << " melee attacks " <<
		target << ", for " << this->_meleeDamage << " damages!" <<
		std::endl;
	return ;
}

void				FragTrap::takeDamage(unsigned int amount)
{
	std::cout << "<FR4G-TP>"<< this->_name;
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

void				FragTrap::beRepaired(unsigned int amount)
{
	this->_hp += amount;
	if (this->_hp > this->_hpMax)
		this->_hp = this->_hpMax;
	std::cout << "<FR4G-TP>"<< this->_name << " gains " << amount <<
		" health points!" << "(" << this->_hp << "/" << this->_hpMax <<
		")" << std::endl;
	return ;
}

void				FragTrap::vaulthunter_dot_exe(std::string const &target)
{
	if (this->_mana < 25)
	{
		std::cout << "<FR4G-TP>"<< this->_name << " doesn't have enough energy!"
				  << std::endl;
		return ;
	}
	this->_mana -= 25;
	(this->*FragTrap::tab[rand() % 5])(target);
	return ;
}

std::string const	&FragTrap::getName(void) const
{return (this->_name);}
unsigned int		FragTrap::getHpMax(void) const
{return (this->_hpMax);}
unsigned int		FragTrap::getHp(void) const
{return (this->_hp);}
unsigned int		FragTrap::getMana(void) const
{return (this->_mana);}
unsigned int		FragTrap::getManaMax(void) const
{return (this->_manaMax);}
unsigned int		FragTrap::getLevel(void) const
{return (this->_level);}
unsigned int		FragTrap::getMeleeDamage(void) const
{return (this->_meleeDamage);}
unsigned int		FragTrap::getRangedDamage(void) const
{return (this->_rangedDamage);}
unsigned int		FragTrap::getArmorReduction(void) const
{return (this->_armorReduction);}


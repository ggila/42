/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/07 12:49:48 by ggilaber          #+#    #+#             */
/*   Updated: 2015/11/07 16:34:18 by ggilaber         ###   ########.fr       */
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

FragTrap::FragTrap() : ClapTrap::ClapTrap()
{
	std::cout << "FragTap constructor called" <<
		std::endl;
	return ;
}

FragTrap::FragTrap(std::string const &name) : ClapTrap(name)
{
	std::cout << "FragTap constructor(name) called" <<
		std::endl;
	return ;
}

FragTrap::FragTrap(FragTrap const & src) : ClapTrap(src)
{
	std::cout << "FragTap onstructor(copy) called" <<
		std::endl;
	return ;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap estructor called" << std::endl;
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

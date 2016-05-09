/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/07 17:54:33 by ggilaber          #+#    #+#             */
/*   Updated: 2015/11/07 18:05:35 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include "Enemy.hpp"

Enemy::Enemy(Enemy const & src) :
	_hp(src.getHp()), _type(src.getType())
{std::cout << "[Enemy](src) constructor called!" << std::endl;}

Enemy::Enemy(int hp, std::string const &type) :
	_hp(hp), _type(type)
{std::cout << "[Enemy](hp, type) constructor called!" << std::endl;}

Enemy::~Enemy()
{std::cout << "~[Enemy]() destructor called!" << std::endl;}

Enemy				&Enemy::operator=(Enemy const &rhs)
{
	std::cout << "[Enemy]= called!" << std::endl;
	this->_hp = rhs.getHp();
	this->_type = rhs.getType();
	return (*this);
}

std::string	const	&Enemy::getType(void) const{return (this->_type);}
int					Enemy::getHp(void) const{return (this->_hp);}

void				Enemy::takeDamage(int amount)
{
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
	return ;
}
 

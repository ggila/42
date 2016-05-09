/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AssaultTerminator.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/07 18:07:08 by ggilaber          #+#    #+#             */
/*   Updated: 2015/11/07 18:10:17 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AssaultTerminator.hpp"

std::string const			AssaultTerminator::_birthMgs =
	"* teleports from space *";
std::string const			AssaultTerminator::_battleCryMsg =
	"This code is unclean. PURIFY IT !";
std::string const			AssaultTerminator::_rangedAttackMsg =
	"* does nothing *";
std::string const			AssaultTerminator::_meleeAttackMsg =
	"* attacks with chainfists *";
std::string const			AssaultTerminator::_deathMgs =
	"I’ll be back ...";

AssaultTerminator::AssaultTerminator() :
	ISpaceMarine(),
	_next(NULL)
{std::cout << AssaultTerminator::_birthMgs << std::endl;}

AssaultTerminator::AssaultTerminator(AssaultTerminator const &src) :
	ISpaceMarine(),
	_next(NULL)
{
	std::cout << AssaultTerminator::_birthMgs << std::endl;
	(void)src;
	return ;
}

AssaultTerminator::~AssaultTerminator()
{std::cout << AssaultTerminator::_deathMgs << std::endl;}

AssaultTerminator			&AssaultTerminator::operator=(
	AssaultTerminator const &rhs)
{
	(void)rhs;
	return (*this);
}

ISpaceMarine				*AssaultTerminator::getNext(void)
{return this->_next;}

void						AssaultTerminator::setNext(ISpaceMarine *c)
{this->_next=c;}

ISpaceMarine				*AssaultTerminator::clone() const
{return (new AssaultTerminator(*this));}

void						AssaultTerminator::battleCry() const
{std::cout << AssaultTerminator::_battleCryMsg << std::endl;}
void						AssaultTerminator::rangedAttack() const
{std::cout << AssaultTerminator::_rangedAttackMsg << std::endl;}
void						AssaultTerminator::meleeAttack() const
{std::cout << AssaultTerminator::_meleeAttackMsg << std::endl;}


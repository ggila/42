/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TacticalMarine.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/07 18:10:51 by ggilaber          #+#    #+#             */
/*   Updated: 2015/11/07 18:11:57 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "TacticalMarine.hpp"

std::string const			TacticalMarine::_birthMgs =
	"Tactical Marine ready for battle";
std::string const			TacticalMarine::_battleCryMsg =
	"For the holy PLOT !";
std::string const			TacticalMarine::_rangedAttackMsg =
	"* attacks with bolter *";
std::string const			TacticalMarine::_meleeAttackMsg =
	"* attacks with chainsword *";
std::string const			TacticalMarine::_deathMgs =
	"Aaargh ...";

TacticalMarine::TacticalMarine() :
	ISpaceMarine(),
	_next(NULL)
{std::cout << TacticalMarine::_birthMgs << std::endl;}

TacticalMarine::TacticalMarine(TacticalMarine const &src) :
	ISpaceMarine(),
	_next(NULL)
{
	std::cout << TacticalMarine::_birthMgs << std::endl;
	(void)src;
	return ;
}

TacticalMarine::~TacticalMarine()
{std::cout << TacticalMarine::_deathMgs << std::endl;}

TacticalMarine				&TacticalMarine::operator=(
	TacticalMarine const &rhs)
{
	(void)rhs;
	return (*this);
}

ISpaceMarine				*TacticalMarine::getNext(void)
{return this->_next;}

void						TacticalMarine::setNext(ISpaceMarine *c)
{this->_next=c;}

ISpaceMarine				*TacticalMarine::clone() const
{return (new TacticalMarine(*this));}
void						TacticalMarine::battleCry() const
{std::cout << TacticalMarine::_battleCryMsg << std::endl;	}
void						TacticalMarine::rangedAttack() const
{std::cout << TacticalMarine::_rangedAttackMsg << std::endl;}
void						TacticalMarine::meleeAttack() const
{std::cout << TacticalMarine::_meleeAttackMsg << std::endl;}

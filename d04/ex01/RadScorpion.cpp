/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RadScorpion.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/07 17:51:30 by ggilaber          #+#    #+#             */
/*   Updated: 2015/11/07 17:59:36 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include "RadScorpion.hpp"

std::string const	RadScorpion::_typeName = "RadScorpion";
int const			RadScorpion::_baseHp = 80;
std::string const	RadScorpion::_birthMsg = "* click click click *";
std::string const	RadScorpion::_deathMsg = "* SPROTCH *";

RadScorpion::RadScorpion() :
	Enemy(RadScorpion::_baseHp, RadScorpion::_typeName)
{std::cout << RadScorpion::_birthMsg << std::endl;}
RadScorpion::RadScorpion(RadScorpion const & src) :
	Enemy(src.getHp(), src.getType())
{std::cout << "[RadScorpion](src) constructor called!" << std::endl;}
RadScorpion::~RadScorpion()
{std::cout << RadScorpion::_deathMsg << std::endl;}

RadScorpion		&RadScorpion::operator=(RadScorpion const &rhs)
{
	std::cout << "[RadScorpion]= called!" << std::endl;
	Enemy::operator = (rhs);
	return (*this);
}

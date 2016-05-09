/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Victim.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/07 17:35:05 by ggilaber          #+#    #+#             */
/*   Updated: 2015/11/07 17:35:28 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include "Victim.hpp"

Victim::Victim(Victim const & src) :
_name(src.getName())
{
	std::cout << "[Victim](src) constructor called!" << std::endl;
	return ;
}

Victim::Victim(std::string const name) :
_name(name)
{
	std::cout << "Some random victim called " << name << " just popped !" <<
		std::endl;
	return ;
}

Victim::~Victim()
{
	std::cout << "Victim " << this->_name <<
		" just died for no apparent reason !" << std::endl;
	return ;
}

Victim			&Victim::operator=(Victim const &rhs)
{
	std::cout << "[Victim]= called!" << std::endl;
	this->_name = rhs.getName();
	return (*this);
}
std::ostream		&operator<<(std::ostream & o, Victim const & rhs)
{
	o << "I'm " << rhs.getName() << " and i like otters !" << std::endl;
	return (o);
}

std::string	const	&Victim::getName(void) const{return (this->_name);}

void				Victim::getPolymorphed(void) const
{
	std::cout << this->_name << " has been turned into a cute little sheep !" <<
		std::endl;
	return ;
}

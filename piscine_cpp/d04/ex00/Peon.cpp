/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Peon.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/07 17:34:01 by ggilaber          #+#    #+#             */
/*   Updated: 2015/11/07 17:45:37 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Peon.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/07 17:33:59 by ggilaber          #+#    #+#             */
/*   Updated: 2015/11/07 17:33:59 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include "Peon.hpp"

Peon::Peon(Peon const & src) :
	Victim(src.getName())
{
	std::cout << "[Peon](src) constructor called!" << std::endl;
	return ;
}

Peon::Peon(std::string const name) :
	Victim(name)
{
	std::cout << "Zog zog." << std::endl;
	return ;
}

Peon::~Peon()
{
	std::cout << "Bleuark..." << std::endl;
	return ;
}

Peon			&Peon::operator=(Peon const &rhs)
{
	std::cout << "[Peon]= called!" << std::endl;
	this->_name = rhs.getName();
	return (*this);
}
std::ostream		&operator<<(std::ostream & o, Peon const & rhs)
{
	o << "I'm " << rhs.getName() << " and I like otters !" << std::endl;
	return (o);

}
void				Peon::getPolymorphed(void) const
{
	std::cout << this->_name << " has been turned into a pink pony !" <<
		std::endl;
	return ;
}

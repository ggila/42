/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/05 23:06:54 by ggilaber          #+#    #+#             */
/*   Updated: 2015/11/05 23:06:57 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>
#include "Fixed.class.hpp"


int				Fixed::getRawBits(void) const
{
	return (this->_rawBits);
}

void			Fixed::setRawBits(int const raw)
{
	this->_rawBits = raw;
	return ;
}

int				Fixed::toInt(void) const
{
	return (this->_rawBits >> Fixed::_fb);
}

float			Fixed::toFloat(void) const
{
	return ((float)this->_rawBits / (float)(1 << Fixed::_fb));
}

Fixed::Fixed() : _rawBits(0)
{
	std::cout << "Default constructor called" << std::endl;
	return ;
}

Fixed::Fixed(Fixed const & src) : _rawBits(0)
{
	std::cout << "Copy constructor called" << std::endl;
	this->_rawBits = src.getRawBits();
	return ;
}

Fixed::Fixed(int const raw) : _rawBits(0)
{
	std::cout << "Int constructor called" << std::endl;
	this->_rawBits = raw << Fixed::_fb;
	return ;
}

Fixed::Fixed(float const floating_point) : _rawBits(0)
{
	std::cout << "Float constructor called" << std::endl;
	this->_rawBits = (int)roundf(floating_point * (float)(1 << Fixed::_fb));
	return ;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

Fixed			&Fixed::operator=(Fixed const & rhs)
{
	std::cout << "Assignation operator called" << std::endl;
	this->_rawBits = rhs.getRawBits();
	return (*this);
}

std::ostream	&operator<<(std::ostream & o, Fixed const & rhs)
{
	o << rhs.toFloat();
	return (o);
}

int const	Fixed::_fb = 8;

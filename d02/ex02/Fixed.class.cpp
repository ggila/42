/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/05 23:07:33 by ggilaber          #+#    #+#             */
/*   Updated: 2015/11/05 23:11:24 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>
#include "Fixed.class.hpp"

int const					Fixed::_fb = 8;


Fixed::Fixed() : _rawBits(0)
{return;}

Fixed::Fixed(Fixed const & src) : _rawBits(0) {
	this->_rawBits = src.getRawBits();
	return ;
}

Fixed::Fixed(int const raw) : _rawBits(0) {
	this->_rawBits = raw << Fixed::_fb;
	return ;
}

Fixed::Fixed(float const floating_point) : _rawBits(0) {
	this->_rawBits = (int)roundf(floating_point * (float)(1 << Fixed::_fb));
	return ;
}

Fixed::~Fixed()
{return;}

Fixed			&Fixed::operator=(Fixed const & rhs) {
	this->_rawBits = rhs.getRawBits();
	return (*this);
}

// comparaison
bool			Fixed::operator>(Fixed const & rhs) const
{return (this->_rawBits > rhs.getRawBits());}

bool			Fixed::operator<(Fixed const & rhs) const
{return (this->_rawBits < rhs.getRawBits());}

bool			Fixed::operator>=(Fixed const & rhs) const
{return (this->_rawBits >= rhs.getRawBits());}

bool			Fixed::operator<=(Fixed const & rhs) const
{return (this->_rawBits <= rhs.getRawBits());}

bool			Fixed::operator==(Fixed const & rhs) const
{return (this->_rawBits == rhs.getRawBits());}

bool			Fixed::operator!=(Fixed const & rhs) const
{return (this->_rawBits != rhs.getRawBits());}

// min|max
Fixed const		&Fixed::max(Fixed const &f1, Fixed const &f2)
{return (f1.getRawBits() > f2.getRawBits() ? f1 : f2);}

Fixed const		&Fixed::min(Fixed const &f1, Fixed const &f2)
{return (f1.getRawBits() < f2.getRawBits() ? f1 : f2);}

Fixed			&Fixed::max(Fixed &f1, Fixed &f2)
{return (f1.getRawBits() > f2.getRawBits() ? f1 : f2);}

Fixed			&Fixed::min(Fixed &f1, Fixed &f2)
{return (f1.getRawBits() < f2.getRawBits() ? f1 : f2);}

// +|-
Fixed			Fixed::operator+(Fixed const & rhs) const
{return Fixed(this->toFloat() + rhs.toFloat());}

Fixed			Fixed::operator-(Fixed const & rhs) const
{return Fixed(this->toFloat() - rhs.toFloat());}

Fixed			Fixed::operator*(Fixed const & rhs) const
{return Fixed(this->toFloat() * rhs.toFloat());}

Fixed			Fixed::operator/(Fixed const & rhs) const
{return Fixed(this->toFloat() / rhs.toFloat());}

Fixed			&Fixed::operator++(void)
{this->_rawBits++; return (*this);}

Fixed			Fixed::operator++(int)
{Fixed	cpy(*this); this->_rawBits++; return (cpy);}

int				Fixed::getRawBits(void) const
{return (this->_rawBits);}

void			Fixed::setRawBits(int const raw) {
	this->_rawBits = raw;
	return ;
}

int				Fixed::toInt(void) const
{return (this->_rawBits >> Fixed::_fb);}

float			Fixed::toFloat(void) const
{return ((float)this->_rawBits / (float)(1 << Fixed::_fb));}

std::ostream	&operator<<(std::ostream & o, Fixed const & rhs) {
	o << rhs.toFloat();
	return (o);
}

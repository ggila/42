/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/05 23:11:33 by ggilaber          #+#    #+#             */
/*   Updated: 2015/11/05 23:12:04 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_CLASS_HPP
# define FIXED_CLASS_HPP

# include <iostream>

class Fixed
{

public:
	Fixed				&operator=(Fixed const & rhs);
	bool				operator>(Fixed const & rhs) const;
	bool				operator<(Fixed const & rhs) const;
	bool				operator>=(Fixed const & rhs) const;
	bool				operator<=(Fixed const & rhs) const;
	bool				operator==(Fixed const & rhs) const;
	bool				operator!=(Fixed const & rhs) const;
	Fixed				operator+(Fixed const & rhs) const;
	Fixed				operator-(Fixed const & rhs) const;
	Fixed				operator*(Fixed const & rhs) const;
	Fixed				operator/(Fixed const & rhs) const;
	Fixed				&operator++(void);
	Fixed				operator++(int);

	int					getRawBits(void) const;
	void				setRawBits(int const raw);
	float				toFloat(void) const;
	int					toInt(void) const;
	
	static Fixed const	&max(Fixed const &f1, Fixed const &f2);
	static Fixed		&max(Fixed &f1, Fixed &f2);
	static Fixed const	&min(Fixed const &f1, Fixed const &f2);
	static Fixed		&min(Fixed &f1, Fixed &f2);

	Fixed();
	~Fixed();
	Fixed(Fixed const & src);
	Fixed(int const raw);
	Fixed(float const raw);

private:
	int					_rawBits;
	static int const	_fb;
	
};

std::ostream			&operator<<(std::ostream & o, Fixed const & rhs);

#endif

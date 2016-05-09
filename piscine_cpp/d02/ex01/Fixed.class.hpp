/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/05 23:07:05 by ggilaber          #+#    #+#             */
/*   Updated: 2015/11/05 23:07:08 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_CLASS_HPP
# define FIXED_CLASS_HPP

# include <iostream>

class Fixed
{
public:
	int					getRawBits(void) const;
	void				setRawBits(int const raw);
	float				toFloat(void) const;
	int					toInt(void) const;

	Fixed();
	~Fixed();
	Fixed				&operator=(Fixed const & rhs);
	Fixed(Fixed const & src);
	Fixed(int const raw);
	Fixed(float const raw);

private:
	int					_rawBits;
	static int const	_fb;
};

std::ostream			&operator<<(std::ostream & o, Fixed const & rhs);

#endif

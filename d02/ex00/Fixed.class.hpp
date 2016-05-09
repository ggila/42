/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/05 23:06:28 by ggilaber          #+#    #+#             */
/*   Updated: 2015/11/05 23:06:30 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_CLASS_HPP
# define FIXED_CLASS_HPP

class Fixed
{
public:
	Fixed	&operator=(Fixed const & rhs);
	int		getRawBits(void) const;
	void	setRawBits(int const raw);

	Fixed();
	~Fixed();
	Fixed(Fixed const & src);

private:
	static int const	_fb;
	int					_rawBits;
};

#endif

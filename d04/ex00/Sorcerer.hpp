/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sorcerer.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/07 17:37:17 by ggilaber          #+#    #+#             */
/*   Updated: 2015/11/07 17:37:21 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORCERER_HPP
# define SORCERER_HPP

# include <iostream>
# include "Victim.hpp"

class Sorcerer
{
public:
	Sorcerer(std::string const name, std::string const title);
	Sorcerer(Sorcerer const &rhs);
	~Sorcerer();
	
	std::string	const		&getName(void) const;
	std::string const		&getTitle(void) const;
	void					polymorph(Victim const &v) const;
	
private:
	std::string				_name;
	std::string				_title;
	Sorcerer				&operator=(Sorcerer const &rhs);
	Sorcerer();
};

std::ostream			&operator<<(std::ostream & o, Sorcerer const & rhs);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Peon.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/07 17:34:06 by ggilaber          #+#    #+#             */
/*   Updated: 2015/11/07 17:40:23 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PEON_HPP
# define PEON_HPP

# include <iostream>
# include "Victim.hpp"

class Peon : public Victim
{
public:
	Peon(std::string const name);
	Peon(Peon const &rhs);
	~Peon();
	
	void			getPolymorphed(void) const;
	
private:
	Peon					&operator=(Peon const &rhs);
	Peon();
};

std::ostream			&operator<<(std::ostream & o, Peon const & rhs);

#endif

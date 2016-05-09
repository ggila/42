/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Victim.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/07 17:35:07 by ggilaber          #+#    #+#             */
/*   Updated: 2015/11/07 17:36:10 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VICTIM_HPP
# define VICTIM_HPP

# include <iostream>

class Victim
{
public:
	Victim(std::string const name);
	Victim(Victim const &rhs);
	~Victim();
	
	std::string const		&getName(void) const;
	virtual void			getPolymorphed(void) const;
	
protected:
	std::string				_name;
private:
	Victim					&operator=(Victim const &rhs);
	Victim();
};

std::ostream			&operator<<(std::ostream & o, Victim const & rhs);

#endif

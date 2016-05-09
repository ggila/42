/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Squad.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/07 18:12:01 by ggilaber          #+#    #+#             */
/*   Updated: 2015/11/07 18:12:19 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SQUAD_HPP
# define SQUAD_HPP

# include <iostream>
# include "ISquad.hpp"
# include "ISpaceMarine.hpp"

class Squad : public ISquad
{
public:
	Squad();
	Squad(Squad const &src);
	Squad						&operator=(Squad const &rhs);
	~Squad();
	int							getCount() const;
	ISpaceMarine				*getUnit(int id);
	ISpaceMarine				*getUnit(int id) const;
	int							push(ISpaceMarine* ptr);

protected:
private:
	void						deleteUnits(void);
	
	int							_count;
	ISpaceMarine				*_aUnit;
};

#endif

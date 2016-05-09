/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ISquad.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/07 18:13:06 by ggilaber          #+#    #+#             */
/*   Updated: 2015/11/07 18:13:12 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ISQUAD_HPP
# define ISQUAD_HPP

# include "ISpaceMarine.hpp"

class ISquad
{
public:
	virtual ~ISquad() {}
	virtual int					getCount() const = 0;
	virtual ISpaceMarine*		getUnit(int id) = 0;
	virtual int					push(ISpaceMarine* ptr) = 0;

};

#endif

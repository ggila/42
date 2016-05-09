/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ISpaceMarine.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/07 18:13:41 by ggilaber          #+#    #+#             */
/*   Updated: 2015/11/07 18:13:44 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ISPACEMARINE_HPP
# define ISPACEMARINE_HPP

class ISpaceMarine
{
public:
	virtual ~ISpaceMarine(){}
	virtual ISpaceMarine*		clone() const = 0;
	virtual void				battleCry() const = 0;
	virtual void				rangedAttack() const = 0;
	virtual void				meleeAttack() const = 0;
	
	virtual ISpaceMarine*		getNext() = 0;
	virtual void				setNext(ISpaceMarine*) = 0;
	
};

#endif // ************************************************** ISPACEMARINE_HPP //

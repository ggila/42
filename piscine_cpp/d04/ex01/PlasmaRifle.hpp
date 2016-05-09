/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PlasmaRifle.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/07 17:53:40 by ggilaber          #+#    #+#             */
/*   Updated: 2015/11/07 17:53:56 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLASMA_RIFLE_HPP
# define PLASMA_RIFLE_HPP

# include <iostream>
# include "AWeapon.hpp"

class PlasmaRifle : public AWeapon
{
public:
	PlasmaRifle(PlasmaRifle const &rhs);
	~PlasmaRifle();
	PlasmaRifle					&operator=(PlasmaRifle const &rhs);
	PlasmaRifle();	
	void				attack(void) const;
	
protected:
	static std::string const	_defaultName;
	static int const			_defaultDamage;
	static int const			_defaultAPCost;
	static std::string const	_defaultMsg;
private:
	
};

#endif

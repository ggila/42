/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/07 17:55:33 by ggilaber          #+#    #+#             */
/*   Updated: 2015/11/07 17:55:41 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <iostream>
# include "AWeapon.hpp"
# include "Enemy.hpp"

class Character
{
public:
	Character(std::string const &name);
	virtual ~Character();
	
	std::string const			&getName(void) const;
	int							getAP(void) const;
	int							getAPMax(void) const;
	const AWeapon				*getWeapon(void) const;
	
	void						recoverAP(void);
	void						equip(AWeapon *wptr);
	void						attack(Enemy *eptr);
	
	
protected:
	Character();
	Character						&operator=(Character const &rhs);
	Character(Character const &rhs);
	
	std::string					_name;
	int							_aP;
	int							_aPMax;
	AWeapon						*_weaponPtr;
	static int const			_defaultAPMax;
	static int const			_defaultAPRecover;
};

std::ostream			&operator<<(std::ostream & o, Character const &rhs);

#endif

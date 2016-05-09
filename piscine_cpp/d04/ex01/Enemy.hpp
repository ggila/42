/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/07 17:54:21 by ggilaber          #+#    #+#             */
/*   Updated: 2015/11/07 17:54:29 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_HPP
# define ENEMY_HPP

# include <iostream>

class Enemy
{
public:
	Enemy(int hp, std::string const &type);
	Enemy(Enemy const &rhs);
	virtual ~Enemy();
	Enemy					&operator=(Enemy const &rhs);
	
	int						getHp(void) const;
	std::string const		&getType(void) const;
	
	virtual void			takeDamage(int amount);
	
protected:
	Enemy();
	int						_hp;
	std::string				_type;
};

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RadScorpion.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/07 17:49:00 by ggilaber          #+#    #+#             */
/*   Updated: 2015/11/07 17:51:26 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAD_SCORPION_HPP
# define RAD_SCORPION_HPP

# include <iostream>
# include "Enemy.hpp"

class RadScorpion : public Enemy
{
public:
	RadScorpion();
	RadScorpion(RadScorpion const &rhs);
	~RadScorpion();
	RadScorpion 				&operator=(RadScorpion const &rhs);
	
private:
	static std::string const	_typeName;
	static int const			_baseHp;
	static std::string const	_birthMsg;
	static std::string const	_deathMsg;
};

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperMutant.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/07 17:48:24 by ggilaber          #+#    #+#             */
/*   Updated: 2015/11/07 17:57:55 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUPER_MUTANT_HPP
# define SUPER_MUTANT_HPP

# include <iostream>
# include "Enemy.hpp"

class SuperMutant : public Enemy
{
public:
	SuperMutant();
	SuperMutant(SuperMutant const &rhs);
	~SuperMutant();
	SuperMutant 				&operator=(SuperMutant const &rhs);
	
	void						takeDamage(int amount);
	
private:
	static std::string const	_typeName;
	static int const			_baseHp;
	static std::string const	_birthMsg;
	static std::string const	_deathMsg;
};

#endif

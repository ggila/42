/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/07 15:31:35 by ggilaber          #+#    #+#             */
/*   Updated: 2015/11/07 16:21:04 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAV_TRAP_HPP
# define SCAV_TRAP_HPP

# include <iostream>
#include "ClapTrap.hpp"

class ScavTrap: public ClapTrap
{
public:
	typedef void			(ScavTrap::*clg)(std::string const &target) const;
	static ScavTrap::clg	clg_tab[4];

	ScavTrap();
	ScavTrap(ScavTrap const &src);
	ScavTrap(std::string const &name);
	~ScavTrap();
	ScavTrap				&operator=(ScavTrap const &rhs);

	void					clg_here(std::string const &target) const;
	void					clg_on(std::string const &target) const;
	void					clg_fight(std::string const &target) const;
	void					clg_back(std::string const &target) const;
	void					challengeNewcomer(std::string const &target);
	
private:
void					_clg(std::string const &target, std::string const &mess) const;
};

#endif

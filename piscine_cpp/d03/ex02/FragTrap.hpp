/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/07 12:49:51 by ggilaber          #+#    #+#             */
/*   Updated: 2015/11/07 16:21:06 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAG_TRAP_HPP
# define FRAG_TRAP_HPP

# include <iostream>
#include "ClapTrap.hpp"

class FragTrap: public ClapTrap
{
public:
	typedef void 					(FragTrap::*func)(std::string const &) const;

	FragTrap();
	FragTrap(FragTrap const &src);
	FragTrap(std::string const &name);
	~FragTrap();
	FragTrap				&operator=(FragTrap const &rhs);

	void					vaulthunter_dot_exe(std::string const &target);
	void					blueAttack(std::string const &target) const;
	void					greenAttack(std::string const &target) const;
	void					redAttack(std::string const &target) const;
	void					blackAttack(std::string const &target) const;
	void					whiteAttack(std::string const &target) const;
	void					toString(void);

private:
	void					_randAttack(std::string const &target,
	 						std::string const &att) const;

	static func				tab[5];
};

#endif

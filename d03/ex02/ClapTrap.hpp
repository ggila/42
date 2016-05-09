/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/07 15:52:19 by ggilaber          #+#    #+#             */
/*   Updated: 2015/11/07 16:16:44 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAP_TRAP_HPP
# define CLAP_TRAP_HPP

# include <iostream>

class ClapTrap
{
public:
	ClapTrap();
	ClapTrap(ClapTrap const &src);
	ClapTrap(std::string const &name);
	virtual ~ClapTrap();
	ClapTrap				&operator=(ClapTrap const &rhs);

	void					rangedAttack(std::string const &target) const;
	void					meleeAttack(std::string const &target) const;
	void					takeDamage(unsigned int amount);
	void					beRepaired(unsigned int amount);
	
	std::string const		&getName(void)  const;
	unsigned int			getHp(void)  const;
	unsigned int			getHpMax(void)  const;
	unsigned int			getMana(void)  const;
	unsigned int			getManaMax(void)  const;
	unsigned int			getLevel(void)  const;
	unsigned int			getMeleeDamage(void)  const;
	unsigned int			getRangedDamage(void)  const;
	unsigned int			getArmorReduction(void)  const;
	
protected:
	std::string const		_name;
	unsigned int			_hp;
	unsigned int			_hpMax;
	unsigned int			_mana;
	unsigned int			_manaMax;
	unsigned int			_level;
	unsigned int			_meleeDamage;
	unsigned int			_rangedDamage;
	unsigned int			_armorReduction;
	std::string				_class;
};

#endif

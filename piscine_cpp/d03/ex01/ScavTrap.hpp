/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/07 15:31:35 by ggilaber          #+#    #+#             */
/*   Updated: 2015/11/07 15:48:09 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAV_TRAP_HPP
# define SCAV_TRAP_HPP

# include <iostream>

class ScavTrap
{
public:
	typedef void			(ScavTrap::*clg)(std::string const &target) const;
	static ScavTrap::clg	clg_tab[4];

	ScavTrap();
	ScavTrap(ScavTrap const &src);
	ScavTrap(std::string const &name);
	~ScavTrap();
	ScavTrap				&operator=(ScavTrap const &rhs);

	std::string const		&getName(void)  const;
	unsigned int			getHp(void)  const;
	unsigned int			getHpMax(void)  const;
	unsigned int			getMana(void)  const;
	unsigned int			getManaMax(void)  const;
	unsigned int			getLevel(void)  const;
	unsigned int			getMeleeDamage(void)  const;
	unsigned int			getRangedDamage(void)  const;
	unsigned int			getArmorReduction(void)  const;
	
	void					rangedAttack(std::string const &target) const;
	void					meleeAttack(std::string const &target) const;
	void					takeDamage(unsigned int amount);
	void					beRepaired(unsigned int amount);

	void					clg_here(std::string const &target) const;
	void					clg_on(std::string const &target) const;
	void					clg_fight(std::string const &target) const;
	void					clg_back(std::string const &target) const;
	void					challengeNewcomer(std::string const &target);
	
private:
	std::string const		_name;
	unsigned int			_hp;
	unsigned int			_hpMax;
	unsigned int			_mana;
	unsigned int			_manaMax;
	unsigned int			_level;
	unsigned int			_meleeDamage;
	unsigned int			_rangedDamage;
	unsigned int			_armorReduction;

void					_clg(std::string const &target, std::string const &mess) const;
};

#endif

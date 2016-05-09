/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/07 12:49:51 by ggilaber          #+#    #+#             */
/*   Updated: 2015/11/07 15:16:37 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAG_TRAP_HPP
# define FRAG_TRAP_HPP

# include <iostream>

class FragTrap
{
public:
	typedef void 					(FragTrap::*func)(std::string const &) const;

	FragTrap();
	FragTrap(FragTrap const &src);
	FragTrap(std::string const &name);
	~FragTrap();
	FragTrap				&operator=(FragTrap const &rhs);

	void					rangedAttack(std::string const &target) const;
	void					meleeAttack(std::string const &target) const;
	void					takeDamage(unsigned int amount);
	void					beRepaired(unsigned int amount);
	void					vaulthunter_dot_exe(std::string const &target);
	void					blueAttack(std::string const &target) const;
	void					greenAttack(std::string const &target) const;
	void					redAttack(std::string const &target) const;
	void					blackAttack(std::string const &target) const;
	void					whiteAttack(std::string const &target) const;
	void					toString(void);

	std::string const		&getName(void) const;
	unsigned int			getHp(void) const;
	unsigned int			getHpMax(void) const;
	unsigned int			getMana(void) const;
	unsigned int			getManaMax(void) const;
	unsigned int			getLevel(void) const;
	unsigned int			getMeleeDamage(void) const;
	unsigned int			getRangedDamage(void) const;
	unsigned int			getArmorReduction(void) const;


private:
	void					_tabinit(void);
	void					_randAttack(std::string const &target,
	 						std::string const &att) const;

	std::string const		_name;
	unsigned int			_hp;
	unsigned int			_hpMax;
	unsigned int			_mana;
	unsigned int			_manaMax;
	unsigned int			_level;
	unsigned int			_meleeDamage;
	unsigned int			_rangedDamage;
	unsigned int			_armorReduction;
	static func				tab[5];
};

#endif

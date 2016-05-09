/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TacticalMarine.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/07 18:10:26 by ggilaber          #+#    #+#             */
/*   Updated: 2015/11/07 18:10:46 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TACTICALMARINE_HPP
# define TACTICALMARINE_HPP

# include <iostream>
# include "ISpaceMarine.hpp"

class TacticalMarine : public ISpaceMarine
{
public:
	TacticalMarine();
	TacticalMarine(TacticalMarine const &src);
	TacticalMarine				&operator=(TacticalMarine const &rhs);
	~TacticalMarine();

	ISpaceMarine*				clone() const;
	void						battleCry() const;
	void						rangedAttack() const;
	void						meleeAttack() const;

	ISpaceMarine				*getNext();
	void						setNext(ISpaceMarine *next);
	
private:
	ISpaceMarine				*_next;
	
	static std::string const	_birthMgs;
	static std::string const	_battleCryMsg;
	static std::string const	_rangedAttackMsg;
	static std::string const	_meleeAttackMsg;
	static std::string const	_deathMgs;
};

#endif

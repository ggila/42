/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AssaultTerminator.hpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/07 18:13:49 by ggilaber          #+#    #+#             */
/*   Updated: 2015/11/07 18:14:05 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASSAULTTERMINATOR_HPP
# define ASSAULTTERMINATOR_HPP

# include <iostream>
# include "ISpaceMarine.hpp"

class AssaultTerminator : public ISpaceMarine
{
public:
	AssaultTerminator();
	AssaultTerminator(AssaultTerminator const &src);
	AssaultTerminator			&operator=(AssaultTerminator const &rhs);
	~AssaultTerminator();

	ISpaceMarine*				clone() const;
	void						battleCry() const;
	void						rangedAttack() const;
	void						meleeAttack() const;

	ISpaceMarine				*getNext();
	void						setNext(ISpaceMarine *next);
	
protected:
private:
	ISpaceMarine				*_next;

	static std::string const	_birthMgs;
	static std::string const	_battleCryMsg;
	static std::string const	_rangedAttackMsg;
	static std::string const	_meleeAttackMsg;
	static std::string const	_deathMgs;
};

#endif // ********************************************* ASSAULTTERMINATOR_HPP //

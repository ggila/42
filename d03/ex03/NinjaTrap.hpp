/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/07 16:42:32 by ggilaber          #+#    #+#             */
/*   Updated: 2015/11/07 16:42:34 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NINJA_TRAP_HPP
# define NINJA_TRAP_HPP

# include <iostream>
# include "ClapTrap.hpp"
# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class NinjaTrap : public ClapTrap
{
public:
	NinjaTrap();
	NinjaTrap(NinjaTrap const &src);
	NinjaTrap(std::string const &name);
	virtual ~NinjaTrap();
	NinjaTrap				&operator=(NinjaTrap const &rhs);

	void					ninjaShoebox(FragTrap &target);
	void					ninjaShoebox(ScavTrap &target);
	void					ninjaShoebox(NinjaTrap &target);
private:
	void					loadDefaultStats(void);
};

#endif

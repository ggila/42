
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/10 22:07:11 by ggilaber          #+#    #+#             */
/*   Updated: 2015/11/10 22:28:51 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

AForm	*Intern::makeForm(std::string name, std::string target)
{
	AForm	*ptr = NULL;

	if (!name.compare("robotomy request"))
		ptr = new RobotomyRequestForm(target);
	else if (!name.compare("presidential pardon"))
		ptr = new PresidentialPardonForm(target);
	else if (!name.compare("shrubbery creation"))
		ptr = new ShruberryCreationForm(target);
	else
	{
		std::cout << "Unknown form" << std::endl;
		return ptr;
	}
	std::cout << "Intern creates " << name << std::endl;
	return ptr;
}

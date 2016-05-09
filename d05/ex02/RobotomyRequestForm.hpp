
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/10 08:48:03 by ggilaber          #+#    #+#             */
/*   Updated: 2015/11/10 20:47:26 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMY_REQUESTFORM_HPP
# define ROBOTOMY_REQUESTFORM_HPP

# include <iostream>
# include <stdexcept>
# include <string>
# include <fstream>
# include "Form.hpp"

class RobotomyRequestForm: public AForm
{
	public:
int			getExec(void) const;
std::string	getTarget(void) const;
			RobotomyRequestForm(std::string target);
void		execute(Bureaucrat const &B) const;

	private:
			std::string			_target;
			int					_exec;

			RobotomyRequestForm();
			RobotomyRequestForm(RobotomyRequestForm &S);
			RobotomyRequestForm	&operator=(RobotomyRequestForm &S);
};

std::ostream				&operator<<(std::ostream &o, 
									RobotomyRequestForm const &S);

#endif

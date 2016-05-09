/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/10 08:48:50 by ggilaber          #+#    #+#             */
/*   Updated: 2015/11/10 21:46:47 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include "RobotomyRequestForm.hpp"

int			RobotomyRequestForm::getExec(void) const {return this->_exec;}
std::string	RobotomyRequestForm::getTarget(void) const {return this->_target;}

RobotomyRequestForm::RobotomyRequestForm(std::string target): 
		AForm("RobotomyRequestForm", 72), _target(target), _exec(45) {}

void				RobotomyRequestForm::execute(Bureaucrat const &B) const
{
	if (!this->_signed)
		throw AForm::FormNotSigned();
	if (this->_exec < B.getGrade())
		throw AForm::GradeTooLowException();
	std::cout << "UUUUUOouiouiUOIUOUOUIUuiouiOUOUUIuioIUoiuOIUIOUouuuuiii...  "
		<< std:: endl << this->_target <<  (rand() % 2 == 1 ? " has " : " has not ")
		<< "been lobotommized" << std::endl;
}

std::ostream				&operator<<(std::ostream &o, 
									RobotomyRequestForm const &F)
{
	o << "Form '" << F.getName()
		<< "' (" << F.getGrade()
		<< "/" << F.getExec() << ") on "
		<< F.getTarget() << ": "
		<< (F.getSigned() ? "done" : "to be done");

	return o;
}

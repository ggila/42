/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/10 08:48:50 by ggilaber          #+#    #+#             */
/*   Updated: 2015/11/10 21:06:32 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

int			ShruberryCreationForm::getExec(void) const {return this->_exec;}
std::string	ShruberryCreationForm::getTarget(void) const {return this->_target;}

ShruberryCreationForm::ShruberryCreationForm(std::string target): 
		AForm("ShruberryCreationForm", 145), _target(target), _exec(137) {}

void				ShruberryCreationForm::execute(Bureaucrat const &B) const
{
	if (!this->_signed)
		throw AForm::FormNotSigned();
	if (this->_exec < B.getGrade())
		throw AForm::GradeTooLowException();
	std::ofstream	f(this->_target + "_shruberry");
	f << ASCII_tree;
	f.close();
}

std::ostream				&operator<<(std::ostream &o, 
									ShruberryCreationForm const &F)
{
	o << "Form '" << F.getName()
		<< "' (" << F.getGrade()
		<< "/" << F.getExec() << ") on "
		<< F.getTarget() << ": "
		<< (F.getSigned() ? "done" : "to be done");

	return o;
}

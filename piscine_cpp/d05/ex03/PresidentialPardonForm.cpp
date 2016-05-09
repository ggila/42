/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/10 08:48:50 by ggilaber          #+#    #+#             */
/*   Updated: 2015/11/10 21:42:02 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

int			PresidentialPardonForm::getExec(void) const {return this->_exec;}
std::string	PresidentialPardonForm::getTarget(void) const {return this->_target;}

PresidentialPardonForm::PresidentialPardonForm(std::string target): 
		AForm("PresidentialPardonForm", 25), _target(target), _exec(5) {}

void				PresidentialPardonForm::execute(Bureaucrat const &B) const
{
	if (!this->_signed)
		throw AForm::FormNotSigned();
	if (this->_exec < B.getGrade())
		throw AForm::GradeTooLowException();
	std::cout << "His highness Zafod Beeblebrox has pardonned " << this->_target
		<< std::endl;
}

std::ostream				&operator<<(std::ostream &o, 
									PresidentialPardonForm const &F)
{
	o << "Form '" << F.getName()
		<< "' (" << F.getGrade()
		<< "/" << F.getExec() << ") on "
		<< F.getTarget() << ": "
		<< (F.getSigned() ? "done" : "to be done");

	return o;
}

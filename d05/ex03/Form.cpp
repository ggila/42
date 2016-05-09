/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/09 17:33:43 by ggilaber          #+#    #+#             */
/*   Updated: 2015/11/10 21:05:06 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

const char	*AForm::FormNotSigned::what() const throw(){
	return "Form has to be signed";
}

const char	*AForm::GradeTooHighException::what() const throw(){
	return "AForm high exception";
}

const char	*AForm::GradeTooLowException::what() const throw(){
	return "AForm low exception";
}

const std::string		&AForm::getName(void) const {return this->_name;}
bool			AForm::getSigned(void) const {return this->_signed;}
int				AForm::getGrade(void) const {return this->_grade;}

void		AForm::beSigned(Bureaucrat &B)
{
	if (this->_grade < B.getGrade())
		throw AForm::GradeTooLowException();
	this->_signed = true;
}

AForm::AForm(void) : _name(""), _signed(false), _grade(150) {}
AForm::AForm(std::string n, int g) : _name(n), _signed(false), _grade(g)
{
	if (g < 1)
		throw AForm::GradeTooHighException();
	else if (g > 150)
		throw AForm::GradeTooLowException();
}
AForm::AForm(AForm &F) :_name(""), _grade(150) {
	*this = F;
}

AForm				&AForm::operator=(AForm &F)
{
	this->_signed = F.getSigned();

	return *this;
}

std::ostream				&operator<<(std::ostream &o, AForm const &F)
{
	o << "AForm '" << F.getName()
		<< "' (" << F.getGrade() << "): "
		<< (F.getSigned() ? "done" : "to be done");

	return o;
}

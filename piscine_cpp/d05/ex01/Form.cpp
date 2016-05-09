/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/09 17:33:43 by ggilaber          #+#    #+#             */
/*   Updated: 2015/11/10 23:28:00 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

const char	*Form::GradeTooHighException::what() const throw(){
	return "Form high exception";
}

const char	*Form::GradeTooLowException::what() const throw(){
	return "Form low exception";
}

const std::string	&Form::getName(void) const {return this->_name;}
bool				Form::getSigned(void) const {return this->_signed;}
int			Form::getGrade(void) const {return this->_grade;}

void		Form::beSigned(Bureaucrat &B)
{
	if (this->_grade < B.getGrade())
		throw Form::GradeTooLowException();
	this->_signed = true;
}

Form::Form(void) : _name(""), _signed(false), _grade(150) {}
Form::Form(std::string n, int g) : _name(n), _signed(false), _grade(g)
{
	if (g < 1)
		throw Form::GradeTooHighException();
	else if (g > 150)
		throw Form::GradeTooLowException();
}
Form::Form(Form &F) :_name(""), _grade(150) {
	*this = F;
}

Form				&Form::operator=(Form &F)
{
	this->_signed = F.getSigned();

	return *this;
}

std::ostream				&operator<<(std::ostream &o, Form const &F)
{
	o << "Form '" << F.getName()
		<< "' (" << F.getGrade() << "): "
		<< (F.getSigned() ? "done" : "to be done")
		<< std::endl;

	return o;
}

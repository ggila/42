/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/09 14:55:51 by ggilaber          #+#    #+#             */
/*   Updated: 2015/11/10 08:28:28 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

const char	*Bureaucrat::GradeTooHighException::what() const throw(){
	return "Bureaucrat grade cannot exceed 1";
}

const char	*Bureaucrat::GradeTooLowException::what() const throw(){
	return "Bureaucrat grade cannot be beneath 150";
}

Bureaucrat::Bureaucrat(void) : _name(""), _grade(150) {}
Bureaucrat::Bureaucrat(std::string str, int c) : _name(str)
{
	if (c < 1)
	{
		throw Bureaucrat::GradeTooHighException();
		this->_grade = 1;
	}
	else if (c > 150)
	{
		throw Bureaucrat::GradeTooLowException();
		this->_grade = 150;
	}
	else
		this->_grade = c;
}

Bureaucrat::Bureaucrat(Bureaucrat &B) {*this = B;}

const std::string	&Bureaucrat::getName(void) const {return this->_name;}
int					Bureaucrat::getGrade(void) const {return this->_grade;}

void				Bureaucrat::incGrade(void)
{
	if (this->_grade == 1)
		throw Bureaucrat::GradeTooHighException();
	else
		this->_grade -= 1;
}

void				Bureaucrat::signForm(Form &F)
{
	try  {F.beSigned(*this);}
	catch (Form::GradeTooLowException &e)
		{
			std::cout << this->_name
				<< " is under-graded, he cannot sign task : '" 
				<< F.getName() << "'" << std::endl;
		}
}

void				Bureaucrat::decGrade(void)
{
	if (this->_grade == 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade += 1;
}

Bureaucrat			&Bureaucrat::operator=(Bureaucrat &B)
{
	this->_grade = B.getGrade();

	return *this;
}

std::ostream	&operator<<(std::ostream &o, Bureaucrat const &B)
{
	o << "Hi there, I am " << B.getName()
		<< " and my grade is " << B.getGrade()
		<< std::endl;

	return o;
}

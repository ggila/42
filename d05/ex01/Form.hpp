/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/09 17:33:54 by ggilaber          #+#    #+#             */
/*   Updated: 2015/11/10 23:27:28 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <stdexcept>
#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	public:
		class GradeTooHighException: public std::exception {
			public:
				virtual const char	*what() const throw();
		};
	
		class GradeTooLowException: public std::exception {
			public:
				virtual const char	*what() const throw();
		};

		const std::string	&getName(void) const;
		bool				getSigned(void) const;
		int			getGrade(void) const;

		void				beSigned(Bureaucrat &B);

							Form(void);
							Form(std::string n, int g);
							Form(Form &F);
		Form				&operator=(Form &F);

	private:
		const std::string	_name;
		bool				_signed;
		const int			_grade;
};

std::ostream				&operator<<(std::ostream &o, Form const &F);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/09 17:33:54 by ggilaber          #+#    #+#             */
/*   Updated: 2015/11/10 21:05:13 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#include <stdexcept>
#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	public:
		class FormNotSigned: public std::exception {
			public:
				virtual const char	*what() const throw();
		};

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
		virtual void		execute(Bureaucrat const &B) const = 0;

							AForm(void);
							AForm(std::string n, int g);
							AForm(AForm &F);
		AForm				&operator=(AForm &F);

	protected:
		const std::string	_name;
		bool				_signed;
		const int			_grade;
};

std::ostream				&operator<<(std::ostream &o, AForm const &F);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/09 14:56:02 by ggilaber          #+#    #+#             */
/*   Updated: 2015/11/09 16:50:12 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdexcept>
#include <iostream>
#include <string>

class Bureaucrat
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
		int					getGrade(void) const;

		void				incGrade(void);
		void				decGrade(void);

							Bureaucrat(void);
							Bureaucrat(std::string str, int c);
							Bureaucrat(Bureaucrat &B);
		Bureaucrat			&operator=(Bureaucrat &B);

	private:
		const std::string	_name;
		int					_grade;
};

std::ostream				&operator<<(std::ostream &o, Bureaucrat const &B);

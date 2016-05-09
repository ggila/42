/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/02 14:57:54 by ggilaber          #+#    #+#             */
/*   Updated: 2015/11/02 19:14:11 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_CLASS_HPP
# define CONTACT_CLASS_HPP

#include <iostream>

std::string	getline(void);

class	Contact
{
	public:
		int			index;
		std::string	first_name;
		std::string	last_name;
		std::string	nickname;
		std::string	login;
		std::string	postal;
		std::string	email;
		std::string	phone;
		std::string	birthday;
		std::string	meal;
		std::string	underwear;
		std::string	secret;

		Contact(void);
		void	define(int i);
		void	display(void) const;
		void	displayall(void) const;

	private:
		void	_printfield(std::string str) const;
};

#endif

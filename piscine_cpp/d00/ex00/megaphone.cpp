/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/02 13:32:06 by ggilaber          #+#    #+#             */
/*   Updated: 2015/11/02 14:22:03 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#define MSG "* LOUD AND UNBEARABLE FEEDBACK NOISE *"

int		main(int ac, char **av)
{
	int		i;
	char	*msg;

	if (ac == 1) {
		std::cout << MSG << std::endl;
		return (1);
	}

	while (--ac)
	{
		msg = *(++av);
		i = -1;

		while (msg[++i]) {
			if (msg[i] >= 'a' && msg[i] <= 'z')
				msg[i] += 'A' - 'a';
		}

		std::cout << msg << ' ';
	}

	std::cout << std::endl;
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serialization.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/11 23:13:07 by ggilaber          #+#    #+#             */
/*   Updated: 2015/11/11 23:15:44 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>
#include <cstdlib>

struct Data { std::string s1; int n; std::string s2; };

static char					getChar(int val)
{
	if (val < 10)
		return ('0' + val);
	else if (val < 26 + 10)
		return ('a' + val - 10);
	return ('A' + val - 36);
}

void						*serialize(void)
{
	char	*start = new char[sizeof(char) * 20];
	size_t	i;

	for (i = 0; i < 8; i++)
		start[i] = getChar(std::rand() % 62);
	*reinterpret_cast<int*>(start + i) = rand();
	i += 4;
	for (; i < 20; i++)
		start[i] = getChar(std::rand() % 62);
	return (start);
}

Data						*unserialize(void *raw)
{
	char	*c1 = reinterpret_cast<char*>(raw);
	int		*n = reinterpret_cast<int*>(raw) + 2;
	char	*c2 = reinterpret_cast<char*>(raw) + 12;
	char	buf[9];
	size_t	i;
	Data	*D = new Data;

	buf[8] = '\0';
	for (i = 0; i < 8; i++)
		buf[i] = *(c1 + i) ;
	D->s1 = buf;
	for (i = 0; i < 8; i++)
		buf[i] = *(c2 + i) ;
	D->s2 = buf;
	D->n = *n;
	return (D);
}

int							main(void)
{
	void	*add;
	std::string str;
	Data	*D;

	srand(time(NULL));
	add = serialize();
	std::cout << "On heap: " << std::string((char*)add, 8) << "        "
		<< *((int*)((char*)add + 8)) << "        " 
		<< std::string((char*)add + 12, 8) << std::endl << std::endl;
		
	D = unserialize(add);
	std::cout << "Data:"<< std::endl <<"\ts1: " << D->s1 << std::endl;
	std::cout << "\t\t\t\t\ts2: " << D->s2 << std::endl;
	std::cout << "\t\t\tn: " << D->n << std::endl;
	delete [] reinterpret_cast<char*>(add);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/12 17:21:10 by ggilaber          #+#    #+#             */
/*   Updated: 2015/11/12 18:32:44 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

namespace ex01 {

	template<typename T>
	void iter(T arr[], size_t len, void (*f)(T&))
	{
		for (size_t i=0; i<len; ++i)
			f(arr[i]);
	}

};

template<typename T>
void disp(T t) {std::cout << t << '\t';}

template<typename T>
void inc(T t) {std::cout << (t + 1) << '\t';}

int main()
{
	std::cout << "int I[5] = {0,1,2,3,4}" <<std::endl;
	int I[5] = {0,1,2,3,4};
	std::cout << "iter<int>(I, 5, disp)" <<std::endl;
	ex01::iter<int>(I, 5, disp);
	std::cout <<std::endl;
	std::cout << "inc<int>(I, 3, inc)" <<std::endl;
	ex01::iter<int>(I, 3, inc);
	std::cout <<std::endl;
	std::cout <<std::endl;

	std::cout << "std::string S[3] = {\"00\",\"11\",\"22\"}" <<std::endl;
	std::string S[3] = {"00","11","22"};
	std::cout <<" iter<std::string>(S, 3, disp)" <<std::endl;
	ex01::iter<std::string>(S, 3, disp);
	std::cout <<std::endl;
	std::cout <<std::endl;

	std::cout << "char C[7] = {'0','1','2','3','4','5','6'}" <<std::endl;
	char C[7] = {'0','1','2','3','4','5','6'};
	std::cout << "iter(C, 4, disp)" <<std::endl;
	ex01::iter(C, 4, disp);
	std::cout <<std::endl;
	std::cout << "iter(C, 7, inc)" <<std::endl;
	ex01::iter(C, 7, inc);
	std::cout <<std::endl;
	std::cout <<std::endl;
	return 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/12 19:38:50 by ggilaber          #+#    #+#             */
/*   Updated: 2015/11/12 21:40:11 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.hpp"

template <typename T>
void test(T t1, T t2)
{
	std::cout << "init" <<std::endl;
	Array<T> a;
	try {a[0];}
	catch (std::out_of_range &e) {std::cout << e.what() << std::endl;}

	std::cout <<std::endl;

	std::cout << "init(n)" <<std::endl;
	Array<T> b(4);
	std::cout << b[0] << ' ' << b[1] << ' '
		<< b[2] << ' ' << b[3]  << std::endl;
	try {a[5];}
	catch (std::out_of_range &e) {std::cout << e.what() << std::endl;}
	b[1] = t1;
	std::cout << b[0] << ' ' << b[1] << ' '
		<< b[2] << ' ' << b[3]  << ' ' << std::endl;

	std::cout <<std::endl;

	std::cout << "init(Array)" <<std::endl;
	Array<T> c(b);
	std::cout << c[0] << ' ' << c[1]
		<< ' ' << c[2] << ' ' << c[3]  << std::endl;
	b[3] = t2;
	std::cout << b[0] << ' ' << b[1] << ' '
		<< b[2] << ' ' << b[3]  << std::endl;
	std::cout << c[0] << ' ' << c[1] << ' '
		<< c[2] << ' ' << c[3]  << std::endl;
}

int main()
{
	test<int>(4, 8);
	std::cout << "------------------------------" <<std::endl;
	test<float>(4.01f, 8.02f);
	std::cout << "------------------------------" <<std::endl;
	test<bool>(true, true);
	std::cout << "------------------------------" <<std::endl;
	test<std::string>("flip", "flap");
	return 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/12 14:54:45 by ggilaber          #+#    #+#             */
/*   Updated: 2015/11/12 17:02:00 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

namespace ex00 {

	template<typename T>
	void swap(T &t1, T &t2)
	{
		T	tmp;

		tmp = t2;
		t2 = t1;
		t1 = tmp;
	}

	template<typename T>
	T max(T const &t1, T const &t2)
	{
		return (t1 > t2 ? t1 : t2);
	}

	template<typename T>
	T min(T const &t1, T const &t2)
	{
		return (t1 < t2 ? t1 : t2);
	}

};

template<typename T>
void test_swap(T &t1, T &t2)
{
	std::cout << "a:" << t1 << std::endl;
	std::cout << "b:" << t2 << std::endl;
	std::cout << "min: " << ex00::min(t1, t2)
		<< "    max: " << ex00::max(t1, t2) << std::endl;
	std::cout << "swap(a, b): ";
	ex00::swap<T>(t1, t2);
	std::cout << "\ta:" << t1;
	std::cout << "   b:" << t2 << std::endl;
}

int main()
	{
		std::cout << "INT:" <<std::endl;
		int	a=1;
		int	b=10;
		test_swap<int>(a, b);

		std::cout << std::endl;

		std::cout << "STR:" << std::endl;
		std::string	c("tic");
		std::string	d("tac");
		test_swap<std::string>(c, d);

		std::cout << std::endl;

		std::cout << "BOOL:" <<std::endl;
		bool	e = true;
		bool	f = false;
		test_swap<bool>(e, f);

		std::cout << std::endl;

		std::cout << "FLOAT:" <<std::endl;
		float	g = 0.1f;
		float	h = 10.1f;
		test_swap<float>(g, h);

		return 1;
	}


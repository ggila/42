/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/11 23:16:34 by ggilaber          #+#    #+#             */
/*   Updated: 2015/11/11 23:34:47 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Base
{
	public:
		virtual ~Base() {};
};

class A : public Base{};
class B : public Base{};
class C : public Base{};

void						identify_from_pointer(Base *p)
{
	A *pa = dynamic_cast<A*>(p);
	if (pa)
		std::cout << "ptr: A" << std::endl;	
	B *pb = dynamic_cast<B*>(p);
	if (pb)
		std::cout << "ptr: B" << std::endl;
	C *pc = dynamic_cast<C*>(p);
	if (pc)
		std::cout << "ptr: C" << std::endl;	
	return ;
}
void						identify_from_reference(Base &p)
{
	try
	{
		p = dynamic_cast<A&>(p);
		std::cout << "ref A" << std::endl;	
	}
	catch (const std::bad_cast&){}
	try
	{
		p = dynamic_cast<B&>(p);
		std::cout << "ref B" << std::endl;
	}
	catch (const std::bad_cast&){}
	try
	{
		p = dynamic_cast<C&>(p);
		std::cout << "ref C" << std::endl;	
	}
	catch (const std::bad_cast&){}
	return ;
}


Base						*getRandClass(void)
{
	if (std::rand() % 3 == 0)
	{
		std::cout << "create A" << std::endl;
		return (new A);
	}
	if (std::rand() % 2 == 0)
	{
		std::cout << "create B" << std::endl;
		return (new B);
	}
	std::cout << "create C" << std::endl;
	return (new C);
}


int							main(void)
{
	Base		*p;

	srand(time(NULL));
	for (char i = 0; i<10; ++i)
	{
		p = getRandClass();
		identify_from_pointer(p);
		identify_from_reference(*p);
		delete p;
	}

	return (0);
}

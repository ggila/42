/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/07 17:47:39 by ggilaber          #+#    #+#             */
/*   Updated: 2015/11/07 17:48:20 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Enemy.hpp"
#include "SuperMutant.hpp"
#include "RadScorpion.hpp"
#include "PlasmaRifle.hpp"
#include "PowerFist.hpp"
#include "Character.hpp"
#include <iostream>

void 	enemies_tests(void);


int main()
{
	enemies_tests();
	return (0);
	
	Character* zaz = new Character("zaz");
	
	std::cout << *zaz;
	
	Enemy* b = new RadScorpion();
	
	AWeapon* pr = new PlasmaRifle();
	AWeapon* pf = new PowerFist();
	
	zaz->equip(pr);
	std::cout << *zaz;
	zaz->equip(pf);
	
	zaz->attack(b);
	std::cout << *zaz;
	zaz->equip(pr);
	std::cout << *zaz;
	zaz->attack(b);
	std::cout << *zaz;
	zaz->attack(b);
	std::cout << *zaz;
	
	return 0;
}

void 	enemies_tests(void)
{
	{
		std::cout << ">Start of Block: SuperMutant" << std::endl << std::endl;
	
		std::cout << "Creation par default dans SuperMutant* a1" << std::endl;
		SuperMutant*	a1 = new SuperMutant();
		std::cout << std::endl;
		std::cout << "Creation par default dans Enemy* a2" << std::endl;
		Enemy*			a2 = new SuperMutant();
		std::cout << std::endl;
		std::cout << "Creation par copie dans SuperMutant a3" << std::endl;
		SuperMutant		a3(*a1);
		std::cout << std::endl;
		
		std::cout << std::endl;
		std::cout << "a3 takes 42 damage: " << std::endl;
		a3.takeDamage(42);
		std::cout << std::endl;
		std::cout << "Assignation a3 = *a1" << std::endl;
		a3 = *a1;
		std::cout << std::endl;
		std::cout << "a3 takes 0 damage: " << std::endl;
		a3.takeDamage(0);
		std::cout << std::endl;
		std::cout << std::endl;
		
		std::cout << std::endl;
		std::cout << "*a2 takes 42 damage: " << std::endl;
		a2->takeDamage(42);
		std::cout << std::endl;
		std::cout << std::endl;
		
		std::cout << "Deleting a1 & a2:" << std::endl;
		delete a1;
		delete a2;
		std::cout << std::endl;
		std::cout << "End of block." << std::endl;
	}
	std::cout << "************************************************"<< std::endl;
	{
		std::cout << ">Start of Block: RadScorpion" << std::endl << std::endl;
	
		std::cout << "Creation par default dans RadScorpion* a1" << std::endl;
		RadScorpion*	a1 = new RadScorpion();
		std::cout << std::endl;
		std::cout << "Creation par default dans Enemy* a2" << std::endl;
		Enemy*			a2 = new RadScorpion();
		std::cout << std::endl;
		std::cout << "Creation par copie dans RadScorpion a3" << std::endl;
		RadScorpion		a3(*a1);
		std::cout << std::endl;
		
		std::cout << std::endl;
		std::cout << "a3 takes 42 damage: " << std::endl;
		a3.takeDamage(42);
		std::cout << std::endl;
		std::cout << "Assignation a3 = *a1" << std::endl;
		a3 = *a1;
		std::cout << std::endl;
		std::cout << "a3 takes 0 damage: " << std::endl;
		a3.takeDamage(0);
		std::cout << std::endl;
		std::cout << std::endl;
		
		std::cout << "Deleting a1 & a2:" << std::endl;
		delete a1;
		delete a2;
		std::cout << std::endl;
		std::cout << "End of block." << std::endl;
	}
	return ;
}

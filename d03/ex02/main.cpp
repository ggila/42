#include <iostream>
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int			main(void)
{
	std::cout << "Tests part 1" << std::endl;
	{
		FragTrap	p0;
		p0.takeDamage(10);
		std::cout << std::endl;
		
		FragTrap	p1("Dewie");
		p1.takeDamage(20);
		std::cout << std::endl;
		
		FragTrap	p2(p0);
		p2.takeDamage(30);
		std::cout << std::endl;
		
		std::cout << "p2 hp:" << p2.getHp() << std::endl;
		p2 = p1;
		std::cout << "p2 hp:" << p2.getHp() << std::endl;
		std::cout << std::endl;
	}
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "Tests part 2" << std::endl;
	{
		ScavTrap	player2("Reese");
		FragTrap	player3("Malcolm");

		player3.rangedAttack(player2.getName());
		player2.takeDamage(player3.getRangedDamage());
		
		player3.meleeAttack(player2.getName());
		player2.takeDamage(player3.getMeleeDamage());
		
		player2.meleeAttack(player3.getName());
		player3.takeDamage(player2.getMeleeDamage());
		player2.meleeAttack(player3.getName());
		player3.takeDamage(player2.getMeleeDamage());
		player2.meleeAttack(player3.getName());
		player3.takeDamage(player2.getMeleeDamage());
		player2.meleeAttack(player3.getName());
		player3.takeDamage(player2.getMeleeDamage());
		player2.meleeAttack(player3.getName());
		player3.takeDamage(player2.getMeleeDamage());
		player2.meleeAttack(player3.getName());
		player3.takeDamage(player2.getMeleeDamage());
		
		player2.challengeNewcomer(player3.getName());
		player2.challengeNewcomer(player3.getName());
		player2.challengeNewcomer(player3.getName());
		player2.challengeNewcomer(player3.getName());
		player2.challengeNewcomer(player3.getName());
		player2.challengeNewcomer(player3.getName());
		
		player2.meleeAttack(player3.getName());
		player3.takeDamage(player2.getMeleeDamage());
		
		player2.beRepaired(100);
	}
	return (0);
}

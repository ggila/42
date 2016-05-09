#include <iostream>
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "NinjaTrap.hpp"

int			main(void)
{
	std::cout << "Tests part 1" << std::endl;
	{
		NinjaTrap	p0;
		p0.takeDamage(10);
		std::cout << std::endl;
		
		NinjaTrap	p1("Dewie");
		p1.takeDamage(20);
		std::cout << std::endl;
		
		NinjaTrap	p2(p0);
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
		ScavTrap	player2("Malcolm");
		FragTrap	player3("Reese");

		NinjaTrap	player1("Francis");
		
		player1.ninjaShoebox(player3);
		player1.ninjaShoebox(player3);
		
		player1.ninjaShoebox(player2);
		
		player2.meleeAttack(player1.getName());
		player1.takeDamage(player2.getMeleeDamage());
		player2.meleeAttack(player1.getName());
		player1.takeDamage(player2.getMeleeDamage());
		player2.meleeAttack(player1.getName());
		player1.takeDamage(player2.getMeleeDamage());
		
		player2.challengeNewcomer(player1.getName());
		player2.challengeNewcomer(player1.getName());
		player2.challengeNewcomer(player1.getName());
		player2.challengeNewcomer(player1.getName());
		player2.challengeNewcomer(player1.getName());
		player2.challengeNewcomer(player1.getName());
		
		player2.beRepaired(100);
	}
	return (0);
}

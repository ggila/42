#include <iostream>
#include <cstdlib>
#include "FragTrap.hpp"

int			main(void)
{
	FragTrap	player2("Malcolm");
	FragTrap	player3("Reese");

	srand(time(NULL));
	std::cout << std::endl;	
	player3.rangedAttack(player2.getName());
	player2.takeDamage(player3.getRangedDamage());
	std::cout << std::endl;
	player3.meleeAttack(player2.getName());
	player2.takeDamage(player3.getMeleeDamage());
	std::cout << std::endl;	
	
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
	std::cout << std::endl;	
	player2.vaulthunter_dot_exe(player3.getName());
	player2.vaulthunter_dot_exe(player3.getName());
	player2.vaulthunter_dot_exe(player3.getName());
	player2.vaulthunter_dot_exe(player3.getName());
	player2.vaulthunter_dot_exe(player3.getName());
	player2.vaulthunter_dot_exe(player3.getName());
	
	
	player2.beRepaired(100);
	return (0);
}

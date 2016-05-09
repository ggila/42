#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main(void)
{
	Bureaucrat B("Riri", 1);

	Intern I;

	ShruberryCreationForm *T = (ShruberryCreationForm*)I.makeForm("shrubbery creation", "bob");
	
	B.signForm(*T);
	B.executeForm(*T);

	std::cout << std::endl;

	RobotomyRequestForm *U = (RobotomyRequestForm*)I.makeForm("robotomy request", "bob");
	
	B.signForm(*U);
	B.executeForm(*U);

	std::cout << std::endl;

	PresidentialPardonForm *V = (PresidentialPardonForm*)I.makeForm("presidential pardon", "bob");
	
	B.signForm(*V);
	B.executeForm(*V);

	std::cout << std::endl;

	I.makeForm("whatever", "bob");
	return 1;
}

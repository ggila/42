#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main(void)
{
	Bureaucrat B2("Riri", 1);
	Bureaucrat B3("Fifi", 142);
	Bureaucrat B4("Riri", 150);

	ShruberryCreationForm	T("Picsou's locker");
	std::cout << std::endl << B2 << B3 << T << std::endl;

	try {T.beSigned(B4);}
	catch (AForm::GradeTooLowException &e) {std::cout << e.what() << std::endl;}

	B4.signForm(T);
	B3.signForm(T);
	std::cout << T << std::endl;

	try {T.execute(B3);}
	catch (AForm::GradeTooLowException &e) {std::cout << e.what() << std::endl;}

	B2.signForm(T);
	std::cout << T << std::endl;

	try {T.execute(B4);}
	catch (AForm::GradeTooLowException &e) {std::cout << e.what() << std::endl;}

	B3.executeForm(T);
	B2.executeForm(T);
	
	std::cout << std::endl;

	PresidentialPardonForm	P("Bob");
	B3.signForm(P);
	B3.executeForm(P);
	B2.signForm(P);
	B2.executeForm(P);

	std::cout << std::endl;

	RobotomyRequestForm	R("Bob");
	B3.signForm(R);
	B3.executeForm(R);
	B2.signForm(R);
	B2.executeForm(R);
	B2.executeForm(R);
	B2.executeForm(R);
	B2.executeForm(R);
	B2.executeForm(R);
	B2.executeForm(R);

	return 1;
}

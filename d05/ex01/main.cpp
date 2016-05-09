#include "Bureaucrat.hpp"
#include <iostream>

int main(void)
{

	Bureaucrat B2("Riri", 10);
	Bureaucrat B3("Fifi", 50);
	Bureaucrat B4("Riri", 70);


	Form *ptr;

	Form T("Task", 30);
	std::cout << T;

	try {ptr = new Form("task1", 0);}
	catch (Form::GradeTooHighException &e) {std::cout << e.what() << std::endl;}

	try {ptr = new Form("task1", 158);}
	catch (Form::GradeTooLowException &e) {std::cout << e.what() << std::endl;}

	std::cout << std::endl << std::endl << B2 << B3 << T << std::endl;

	B3.signForm(T);
	std::cout << T;
	B2.signForm(T);
	std::cout << T << std::endl;
	
	try {T.beSigned(B4);}
	catch (Form::GradeTooLowException &e) {std::cout << e.what() << std::endl;}

	return 1;
}

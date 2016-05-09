#include "Bureaucrat.hpp"
#include <iostream>

int main(void)
{
	Bureaucrat	*ptr;

	try 
	{
		ptr = new Bureaucrat("Riri", 12);
		std::cout << *ptr;
		delete ptr;
	}
	catch (Bureaucrat::GradeTooLowException &e) {std::cout << e.what() << std::endl;}
	catch (Bureaucrat::GradeTooHighException &e) {std::cout << e.what() << std::endl;}

	std::cout << std::endl;

	try
	{
		ptr = new Bureaucrat("Fifi", 2);
		std::cout << *ptr;
		ptr->incGrade();
		std::cout << *ptr;
		ptr->incGrade();
		std::cout << *ptr;
		delete ptr;
	}
	catch (Bureaucrat::GradeTooLowException &e) {std::cout << e.what() << std::endl;}
	catch (Bureaucrat::GradeTooHighException &e) {std::cout << e.what() << std::endl;}

	std::cout << std::endl;

	try
	{
		ptr = new Bureaucrat("Loulou", 149);
		std::cout << *ptr;
		ptr->decGrade();
		std::cout << *ptr;
		ptr->decGrade();
		std::cout << *ptr;
		delete ptr;
	}
	catch (Bureaucrat::GradeTooLowException &e) {std::cout << e.what() << std::endl;}
	catch (Bureaucrat::GradeTooHighException &e) {std::cout << e.what() << std::endl;}

	return 1;
}

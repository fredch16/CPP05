/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fredchar <fredchar@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 22:09:08 by fredchar          #+#    #+#             */
/*   Updated: 2026/02/23 18:48:23 by fredchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <ctime>

#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"

int main()
{
	std::srand(std::time(NULL));

	Intern intern;

	Bureaucrat boss("Boss", 1);
	Bureaucrat manager("Manager", 40);
	Bureaucrat internLevel("InternLevel", 150);

	std::cout << "\n=== VALID FORM CREATION ===\n";

	AForm* shrub = intern.makeForm("shrubbery creation", "garden");
	AForm* robot = intern.makeForm("robotomy request", "Bender");
	AForm* pardon = intern.makeForm("presidential pardon", "Arthur Dent");

	std::cout << "\n=== INVALID FORM CREATION ===\n";

	AForm* invalid = intern.makeForm("coffee request", "Office");

	std::cout << "\n=== SIGN + EXECUTE TESTS ===\n";

	if (shrub)
	{
		boss.signForm(*shrub);
		boss.executeForm(*shrub);
		delete shrub;
	}

	if (robot)
	{
		manager.signForm(*robot);     // Should succeed (sign grade 72)
		manager.executeForm(*robot);  // Should fail (exec grade 45 required)
		boss.executeForm(*robot);     // Should succeed
		delete robot;
	}

	if (pardon)
	{
		internLevel.signForm(*pardon); // Should fail (grade too low)
		boss.signForm(*pardon);        // Should succeed
		boss.executeForm(*pardon);     // Should succeed
		delete pardon;
	}

	delete invalid; // safe even if NULL

	std::cout << "\n=== DONE ===\n";

	return 0;
}
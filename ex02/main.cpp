/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fredchar <fredchar@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 22:09:08 by fredchar          #+#    #+#             */
/*   Updated: 2026/02/05 17:32:39 by fredchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <iostream>

int main() {
	std::cout << "=== PHASE 1: FORM CONSTRUCTOR TESTS ===" << std::endl;
	try {
		std::cout << "Creating a form with grade 0 (Too High)..." << std::endl;
		AForm f1("Tax Return", 0, 50);
	} catch (const std::exception& e) {
		std::cerr << "Caught: " << e.what() << std::endl;
	}

	try {
		std::cout << "\nCreating a form with grade 151 (Too Low)..." << std::endl;
		AForm f2("Parking Ticket", 151, 150);
	} catch (const std::exception& e) {
		std::cerr << "Caught: " << e.what() << std::endl;
	}

	std::cout << "\n=== PHASE 2: SIGNING INTERACTION TESTS ===" << std::endl;

	Bureaucrat boss("The Boss", 1);
	Bureaucrat intern("The Intern", 150);
	AForm topSecret("Top Secret Document", 5, 1);
	AForm basicForm("Lunch Request", 150, 150);

	std::cout << "\n--- Current States ---" << std::endl;
	std::cout << boss << std::endl;
	std::cout << intern << std::endl;
	std::cout << topSecret << std::endl;
	std::cout << basicAForm << std::endl;

	std::cout << "\n--- Action: Intern tries to sign Top Secret ---" << std::endl;
	// This will internally call topSecret.beSigned(intern)
	// Intern's grade 150 is > AForm's required 5, so it throws.
	intern.signAForm(topSecret); 

	std::cout << "\n--- Action: Boss tries to sign Top Secret ---" << std::endl;
	// Boss's grade 1 is <= AForm's required 5, so it succeeds.
	boss.signAForm(topSecret);

	std::cout << "\n--- Action: Intern tries to sign Basic AForm ---" << std::endl;
	// Intern's grade 150 is <= AForm's required 150.
	intern.signAForm(basicForm);

	std::cout << "\n--- Final States ---" << std::endl;
	std::cout << topSecret << std::endl;
	std::cout << basicAForm << std::endl;

	return 0;
}
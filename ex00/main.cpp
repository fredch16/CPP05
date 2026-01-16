/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fredchar <fredchar@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 22:09:08 by fredchar          #+#    #+#             */
/*   Updated: 2026/01/16 16:12:39 by fredchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

#include "Bureaucrat.hpp"
#include <iostream>

void testBureaucrat(const std::string& name, int grade) {
	std::cout << "--- Attempting to create " << name << " with grade " << grade << " ---" << std::endl;
	try {
		Bureaucrat b(name, grade);
		std::cout << "Success: " << b << std::endl;
	} catch (const std::exception& e) {
		std::cerr << "Constructor Error: " << e.what() << std::endl;
	}
	std::cout << std::endl;
}

int main() {
	// 1. Testing Constructor Exceptions
	std::cout << "=== PHASE 1: CONSTRUCTOR TESTS ===" << std::endl;
	testBureaucrat("TooHigh", 0);    // Should fail
	testBureaucrat("TooLow", 151);  // Should fail
	testBureaucrat("Perfect", 75);  // Should succeed

	// 2. Testing Increment/Decrement Exceptions
	std::cout << "=== PHASE 2: GRADE MODIFICATION TESTS ===" << std::endl;
	
	try {
		std::cout << "Creating Elite Bureaucrat..." << std::endl;
		Bureaucrat elite("HighRank", 2);
		std::cout << elite << std::endl;
		
		std::cout << "Incrementing..." << std::endl;
		elite.incrementGrade(); // Now grade 1
		std::cout << elite << std::endl;
		
		std::cout << "Incrementing again (should fail)..." << std::endl;
		elite.incrementGrade(); // Should throw GradeTooHighException
	} catch (const std::exception& e) {
		std::cerr << "Modification Error: " << e.what() << std::endl;
	}

	std::cout << std::endl;

	try {
		std::cout << "Creating Lowly Bureaucrat..." << std::endl;
		Bureaucrat lowly("Intern", 149);
		std::cout << lowly << std::endl;
		
		std::cout << "Decrementing..." << std::endl;
		lowly.decrementGrade(); // Now grade 150
		std::cout << lowly << std::endl;
		
		std::cout << "Decrementing again (should fail)..." << std::endl;
		lowly.decrementGrade(); // Should throw GradeTooLowException
	} catch (const std::exception& e) {
		std::cerr << "Modification Error: " << e.what() << std::endl;
	}

	return 0;
}
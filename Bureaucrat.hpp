/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fredchar <fredchar@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 12:46:06 by fredchar          #+#    #+#             */
/*   Updated: 2025/12/09 16:49:33 by fredchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

#pragma once

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat {
private:
	const std::string _name;
	int _grade;

	// C++17 allows inline static constexpr for easy constant management
	static constexpr int HIGHEST_GRADE = 1;
	static constexpr int LOWEST_GRADE = 150;

public:
	// Orthodox Canonical Form
	Bureaucrat();
	Bureaucrat(const std::string& name, int grade);
	Bureaucrat(const Bureaucrat& other);
	Bureaucrat& operator=(const Bureaucrat& other);
	~Bureaucrat();

	// Getters
	// Nodiscard will give a warning if the result of getters is not used. Because why request it if you don't need it.
	[[nodiscard]] std::string getName() const;
	[[nodiscard]] int getGrade() const;

	// Grade modification
	void incrementGrade();
	void decrementGrade();

	// Exceptions
	class GradeTooHighException : public std::exception {
	public:
		const char* what() const noexcept override {
			return "Bureaucrat grade is too high!";
		}
	};

	class GradeTooLowException : public std::exception {
	public:
		const char* what() const noexcept override {
			return "Bureaucrat grade is too low!";
		}
	};
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);
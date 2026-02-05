/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fredchar <fredchar@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 12:46:06 by fredchar          #+#    #+#             */
/*   Updated: 2026/02/05 17:31:44 by fredchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include <exception>

class Bureaucrat;

class AForm {
private:
	const std::string	_name;
	bool				_signed;
	const int			_signatureGrade;
	const int			_executionGrade;

	static constexpr int HIGHEST_GRADE = 1;
	static constexpr int LOWEST_GRADE = 150;

public:
	// Orthodox Canonical AForm
	AForm(); 
	AForm(const std::string& name, const int signGrade, const int execGrade);
	AForm(const AForm& other);
	AForm& operator=(const AForm& other);
	~AForm();

	// Getters
	[[nodiscard]] std::string getName() const;
	[[nodiscard]] int getSignGrade() const;
	[[nodiscard]] int getExecGrade() const;
	[[nodiscard]] bool getSigned() const;

	// Grade modification
	virtual void incrementGrade() const = 0;
	void decrementGrade();

	// Exceptions
	class GradeTooHighException : public std::exception {
	public:
		const char* what() const noexcept override;
	};

	class GradeTooLowException : public std::exception {
	public:
		const char* what() const noexcept override;
	};

	// Member Functions
	void	beSigned(Bureaucrat& b);
};

std::ostream& operator<<(std::ostream& os, const AForm& f);
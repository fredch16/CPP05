/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fredchar <fredchar@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 16:23:52 by fredchar          #+#    #+#             */
/*   Updated: 2026/02/05 17:27:01 by fredchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

//  Exceptions abort construction this way we circumvent assigning grades only after checking
AForm::AForm(const std::string& name, const int signGrade, const int execGrade)
	: _name(name),
	_signed(false),
	_signatureGrade(signGrade),
	_executionGrade(execGrade)
{
	if (signGrade < HIGHEST_GRADE || execGrade < HIGHEST_GRADE)
		throw GradeTooHighException();
	else if (signGrade > LOWEST_GRADE || execGrade > LOWEST_GRADE)
		throw GradeTooLowException();
	
	std::cout << "AForm constructor called" << std::endl;
}

AForm::AForm(const AForm& other)
	: _name(other._name),
	_signed(other._signed),
	_signatureGrade(other._signatureGrade),
	_executionGrade(other._executionGrade)

{
	std::cout << "AForm Copy constructor called" << std::endl;
}

AForm& AForm::operator=(const AForm& other)
{
	// Note this is only partial assignment given the nature of the const name
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->_signed = other._signed;
	}
	return *this;
}

int AForm::getExecGrade() const{
	return this->_executionGrade;
}

int AForm::getSignGrade() const{
	return this->_signatureGrade;
}

bool AForm::getSigned() const{
	return this->_signed;
}

std::string AForm::getName() const{
	return this->_name;
}

AForm::~AForm()
{
	std::cout << "AForm destructor called" << std::endl;
}

std::ostream& operator<<(std::ostream& os, const AForm& f) {
	os << "AForm: " << f.getName() 
	<< " | Signed: " << (f.getSigned() ? "Yes" : "No")
	<< " | Required Sign Grade: " << f.getSignGrade()
	<< " | Required Exec Grade: " << f.getExecGrade();
	return os;
}

const char* AForm::GradeTooHighException::what() const noexcept {
	return "Grade is too high!";
}

const char* AForm::GradeTooLowException::what() const noexcept {
	return "Grade is too low!";
}

void AForm::beSigned(Bureaucrat& b)
{
	if (b.getGrade() > this->_signatureGrade)
		throw AForm::GradeTooLowException();
	this->_signed = true;
}
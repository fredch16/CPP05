/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fredchar <fredchar@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 16:52:59 by fredchar          #+#    #+#             */
/*   Updated: 2026/02/23 18:16:24 by fredchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string & target)
: AForm("ShrubberyCreationForm", 145, 137, target)
{}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

void ShrubberyCreationForm::executeAction() const
{
	std::ofstream file((getTarget() + "_shrubbery").c_str());

	if (!file)
		return;

	file <<
		"       _-_\n"
		"    /`       '\\\n"
		"   /           \\\n"
		"  /   \\       /   \\\n"
		" /      \\     /      \\\n"
		"/        \\   /        \\\n"
		"-----------\n";

	file.close();
}
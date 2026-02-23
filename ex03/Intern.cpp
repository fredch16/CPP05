/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fredchar <fredchar@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 18:33:06 by fredchar          #+#    #+#             */
/*   Updated: 2026/02/23 18:39:36 by fredchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

AForm* Intern::makeForm(const std::string& name,
						const std::string& target) const
{
	std::string formNames[3] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};

	AForm* forms[3] = {
		new ShrubberyCreationForm(target),
		new RobotomyRequestForm(target),
		new PresidentialPardonForm(target)
	};

	for (int i = 0; i < 3; i++)
	{
		if (name == formNames[i])
		{
			std::cout << "Intern creates " << formNames[i] << std::endl;

			// delete unused forms
			for (int j = 0; j < 3; j++)
			{
				if (j != i)
					delete forms[j];
			}

			return forms[i];
		}
	}

	// If not found, delete all allocated memory
	for (int i = 0; i < 3; i++)
		delete forms[i];

	std::cout << "Intern cannot create form: "
			  << name << std::endl;

	return NULL;
}

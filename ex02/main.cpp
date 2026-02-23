/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fredchar <fredchar@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 22:09:08 by fredchar          #+#    #+#             */
/*   Updated: 2026/02/23 18:20:39 by fredchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <ctime>

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    std::srand(std::time(NULL));

    Bureaucrat boss("Boss", 1);

    AForm* forms[3];

    forms[0] = new ShrubberyCreationForm("garden");
    forms[1] = new RobotomyRequestForm("Bender");
    forms[2] = new PresidentialPardonForm("Arthur Dent");

    for (int i = 0; i < 3; i++)
    {
        boss.signForm(*forms[i]);
        boss.executeForm(*forms[i]);
        std::cout << "-------------------\n";
    }

    for (int i = 0; i < 3; i++)
        delete forms[i];

    return 0;
}
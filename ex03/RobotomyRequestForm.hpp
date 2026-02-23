/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fredchar <fredchar@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 17:04:40 by fredchar          #+#    #+#             */
/*   Updated: 2026/02/23 18:06:23 by fredchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AForm.hpp"
#include <fstream>

class RobotomyRequestForm : public AForm {
public:
	RobotomyRequestForm(const std::string& target);
	~RobotomyRequestForm();
	
	void executeAction() const;
};
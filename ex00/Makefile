# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fredchar <fredchar@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/27 16:31:00 by fredchar          #+#    #+#              #
#    Updated: 2026/01/16 16:12:33 by fredchar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := Bureaucrats
CC := c++
CFLAGS := -Wall -Wextra -Werror -g -std=c++17
OBJD := obj

# Colors
GREEN := \033[0;32m
YELLOW := \033[0;33m
RED := \033[0;31m
NC := \033[0m # No Color

SRCS :=			main.cpp \
				Bureaucrat.cpp

OBJS := $(SRCS:%.cpp=$(OBJD)/%.o)

all: $(NAME)

$(OBJD)/%.o: %.cpp | $(OBJD)
	@printf "$(YELLOW)Compiling $<...$(NC)\n"
	@$(CC) $(CFLAGS) -I . -c $< -o $@
	@printf "$(GREEN)Compiled $< successfully!$(NC)\n"

$(OBJD):
	mkdir -p $(OBJD)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)
	@printf "$(GREEN)Executable $(NAME) built successfully!$(NC)\n"

clean:
	@printf "$(RED)Cleaning object files...$(NC)\n"
	rm -rf $(OBJD)
	@printf "$(GREEN)Object files cleaned!$(NC)\n"

fclean: clean
	@printf "$(RED)Cleaning library and executable...$(NC)\n"
	rm -f $(NAME)
	@printf "$(GREEN)Executable cleaned!$(NC)\n"

re: fclean all

.PHONY: all clean fclean re
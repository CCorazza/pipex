# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccorazza <ccorazza@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/30 12:41:58 by ccorazza          #+#    #+#              #
#    Updated: 2013/12/30 13:49:17 by ccorazza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

SRCS =	./ft_str.c \
		./ft_mem.c \
		./get_next_line.c \

OBJS =	./ft_str.o \
		./ft_mem.o \
		./get_next_line.o \

RM = rm -rf

all: $(OBJS)
	@echo "Debut de la compilation..."
	@gcc -Wall -Wextra -Werror -o $(NAME) $(OBJS)
	@echo -e "\033[0mCompilation \033[38;5;34m terminee\033[0m."

clean:
	@echo "\033[38;5;32m Suppression des .o\033[0m"
	@$(RM) $(OBJS)

fclean: clean
	@echo "\033[38;31m Suppression de l'executable.\033[0m"
	@$(RM) $(NAME)

re: fclean all

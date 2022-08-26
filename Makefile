# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nhanafi <nhanafi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/03 10:54:07 by nhanafi           #+#    #+#              #
#    Updated: 2022/08/26 02:31:11 by nhanafi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

LDFLAGS= -L/Users/nhanafi/.brew/opt/readline/lib
CPPFLAGS= -I/Users/nhanafi/.brew/opt/readline/include

CFLAGS = $(CPPFLAGS) -Wall -Werror -Wextra

INC = -I./include

HEADERS = include/minishell.h include/utils.h include/ast.h

ODIR = obj
FILES = main ft_parcing utils/ft_join utils/ft_strlen utils/instr\
	ast/add_node utils/ft_split utils/ft_strdup utils/ft_substr utils/ft_strcmp utils/ft_putstr_fd

OBJ = $(addprefix $(ODIR)/, $(FILES:=.o))
NAME = minishell

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) -lreadline $(LDFLAGS) $^ -o $@
	@echo " ____ _______ _____ _    _  "
	@echo "|  _ \__   __/ ____| |  | | "
	@echo "| |_) | | | | (___ | |__| | " 
	@echo "|  _ <  | |  \___ \|  __  | "
	@echo "| |_) | | |  ____) | |  | | "
	@echo "|____/  |_| |_____/|_|  |_| "                        

$(ODIR)/%.o: src/%.c $(HEADERS)
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	rm -rf $(ODIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY : re fclean clean all
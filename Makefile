# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nhanafi <nhanafi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/03 10:54:07 by nhanafi           #+#    #+#              #
#    Updated: 2022/08/31 01:43:07 by nhanafi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
RLP=$(shell brew --prefix readline)
LDFLAGS= -L$(RLP)/lib
CPPFLAGS= -I$(RLP)/include

CFLAGS = $(CPPFLAGS) -Wall -Werror -Wextra

INC = -I./include

HEADERS = include/minishell.h include/utils.h include/ast.h include/env.h

ODIR = obj
FILES = main pars/check_err pars/ft_comp pars/ft_parsing pars/ft_comp\
	list/list\
	utils/ft_atoi utils/ft_join utils/ft_putstr_fd utils/ft_split utils/ft_memset\
	utils/ft_strcmp utils/ft_strdup utils/ft_strlen utils/ft_substr utils/instr\
	excu/ft_cd excu/ft_echo excu/ft_exit excu/ft_pwd excu/exec_ast excu/ft_or_and\
	excu/ft_pipe excu/get_path excu/ft_drr excu/ft_rr excu/ft_dlr excu/ft_lr\
	ast/add_node ast/ft_cmd ast/ft_lvl1 ast/ft_lvl2 ast/ft_lvl3 ast/read_eof

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
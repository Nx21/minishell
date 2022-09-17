# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nhanafi <nhanafi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/03 10:54:07 by nhanafi           #+#    #+#              #
#    Updated: 2022/09/16 14:11:35 by nhanafi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
RLP=$(shell brew --prefix readline)
LDFLAGS= -L$(RLP)/lib
CPPFLAGS= -I$(RLP)/include

CFLAGS = $(CPPFLAGS) -Wall -Werror -Wextra -g

INC = -I./include

HEADERS = include/minishell.h include/utils.h include/env.h include/ast.h

ODIR = obj
FILES = main free_ast handler pars/check_error pars/ft_comp pars/ft_parsing pars/ft_comp\
	list/list list/list_split list/list_join list/list_expand list/list_append\
	list/wc_cmp list/wc_handler list/wc_creat excu/ft_word list/sort_list list/append_one\
	utils/ft_atoi utils/ft_join utils/ft_putstr_fd utils/ft_split utils/ft_memset list/q_handler\
	utils/ft_strcmp utils/ft_strdup utils/ft_strlen utils/ft_substr utils/instr list/var_handler\
	utils/ft_strstr utils/ft_isalnum utils/ft_calloc utils/ft_strcat utils/ft_itoa list/find_var\
	excu/ft_cd excu/ft_echo excu/ft_exit excu/ft_pwd excu/exec_ast excu/ft_or_and excu/ft_env\
	excu/ft_pipe excu/get_path excu/ft_drr excu/ft_rr excu/ft_dlr excu/ft_lr excu/ft_unset\
	ast/add_node ast/ft_cmd ast/ft_lvl1 ast/ft_lvl2 ast/ft_lvl3 ast/read_eof excu/ft_export

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
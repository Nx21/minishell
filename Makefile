# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nhanafi <nhanafi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/03 10:54:07 by nhanafi           #+#    #+#              #
#    Updated: 2022/08/04 09:37:59 by nhanafi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

LDFLAGS= -L/Users/nhanafi/.brew/opt/readline/lib
CPPFLAGS= -I/Users/nhanafi/.brew/opt/readline/include

CFLAGS = $(CPPFLAGS) -Wall -Werror -Wextra -g

INC = -I./include

HEADERS = include/minishell.h include/utils.h

ODIR = obj
FILES = main ft_parcing utils/ft_join utils/ft_strlen utils/instr

OBJ = $(addprefix $(ODIR)/, $(FILES:=.o))
NAME = minishell

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -lreadline $(LDFLAGS) $^ -o $@

$(ODIR)/%.o: src/%.c $(HEADERS)
	mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	rm -rf $(ODIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all
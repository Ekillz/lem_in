# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emammadz <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/27 15:04:55 by emammadz          #+#    #+#              #
#    Updated: 2015/12/01 13:51:40 by emammadz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

EXEC = lem-in

SRCC =	main.c\
		get_next_line.c\
		parsing.c\
		ft_lsts.c\
		error.c\
		data_struct.c\

SRCO = $(SRCC:%.c=%.o)

FLAG = -Wall -Werror -Wextra -ggdb

.PHONY: all fast clean fclean

all: lem-in

%.o: %.c
	@make -C libft
	@echo -n  $< :
	@gcc -o $@ -c $< $(FLAG) 
	@echo

lem-in: $(SRCO)
	@gcc -o $(EXEC) $(FLAG) $(SRCO) libft/libft.a

clean:
	@make clean -C libft
	@rm -f $(SRCO)

fclean: clean
	@make fclean -C libft
	@rm $(EXEC)

re: fclean all

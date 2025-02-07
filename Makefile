# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gfrancoi <gfrancoi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/03 18:44:36 by gfrancoi          #+#    #+#              #
#    Updated: 2025/02/07 12:45:32 by gfrancoi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		push_swap
CFLAGS =	-Wall -Wextra -Werror
LIBFT =		./libft/libft.a

SRCS = \
	main.c\
	stack_utils.c\
	stack.c\
	push_swap.c\
	push.c\
	reverse_rotate.c\
	rotate.c\
	swap.c

OBJ_DIR = obj
OBJS = $(addprefix $(OBJ_DIR)/, $(notdir $(SRCS:.c=.o)))

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	cc $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)
	
$(LIBFT):
	make -C ./libft/

$(OBJ_DIR)/%.o: %.c
	mkdir -p $(OBJ_DIR)
	cc $(CFLAGS) -c -o $@ $^

clean:
	make clean -C ./libft/
	rm -fr $(OBJ_DIR)

fclean: clean
	make fclean -C ./libft/
	rm -f $(NAME)

re: fclean all

.PHONY: all fclean clean re
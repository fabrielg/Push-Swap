# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gfrancoi <gfrancoi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/03 18:44:36 by gfrancoi          #+#    #+#              #
#    Updated: 2025/02/03 19:22:15 by gfrancoi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		push_swap
CC =		cc
CFLAGS =	-Wall -Wextra -Werror
LIBFT =		libft/libft.a
INCLUDES =	-Ilibft/

SRCS = \
	stack_utils.c\
	stack.c\
	push_swap.c\
	push.c\
	reverse_rotate.c\
	rotate.c\
	swap.c

OBJ_DIR = obj

OBJS = $(addprefix $(OBJ_DIR)/, $(addsuffix .o, $(basename $(SRCS))))

LIB_FLAGS = $(addprefix -L, $(dir $(LIBFT))) $(addprefix -l, $(patsubst lib%.a, %, $(notdir $(LIBFT))))

all: $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: %.c
	cc $(CFLAGS) -o $@ -c $< $(INCLUDES)
	
%.a:
	make -C $(dir $@)

$(NAME): $(OBJ_DIR) $(LIBFT) $(OBJS)
	cc -o $(NAME) $(OBJS) $(LIB_FLAGS)

clean:
	make clean -C ./libft/
	rm -fr $(OBJ_DIR)

fclean: clean
	make fclean -C ./libft/
	rm -f $(NAME)

re: fclean all

.PHONY: re fclean clean all
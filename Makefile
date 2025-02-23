# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gfrancoi <gfrancoi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/03 18:44:36 by gfrancoi          #+#    #+#              #
#    Updated: 2025/02/23 12:59:14 by gfrancoi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =				push_swap
NAME_CHECKER =		checker
CFLAGS =			-Wall -Wextra -Werror
LIBFT =				./libft/libft.a

SRCS = \
	main.c\
	optimizer.c\
	parsing.c\
	stack_display.c\
	stack_get_min_max.c\
	stack_size.c\
	stack_update.c\
	stack_utils.c\
	stack.c\
	push_swap.c\
	push.c\
	reverse_rotate.c\
	rotate.c\
	sort_utils.c\
	sort.c\
	swap.c\
	targets_b.c\
	targets_a.c

SRCS_CHECKER = \
	main_checker.c\
	parsing.c\
	stack_display.c\
	stack_get_min_max.c\
	stack_size.c\
	stack_update.c\
	stack_utils.c\
	stack.c\
	push_swap.c\
	push.c\
	reverse_rotate.c\
	rotate.c\
	swap.c

OBJ_DIR = obj

OBJS = $(addprefix $(OBJ_DIR)/, $(notdir $(SRCS:.c=.o)))
OBJS_CHECKER = $(addprefix $(OBJ_DIR)/, $(notdir $(SRCS_CHECKER:.c=.o)))

all: $(NAME)

bonus: $(NAME_CHECKER)

$(NAME): $(LIBFT) $(OBJS)
	cc -g3 $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)
	
$(NAME_CHECKER): $(LIBFT) $(OBJS_CHECKER)
	cc -g3 $(CFLAGS) -o $(NAME_CHECKER) $(OBJS_CHECKER) $(LIBFT)
	
$(LIBFT):
	make -C ./libft/

$(OBJ_DIR)/%.o: %.c
	mkdir -p $(OBJ_DIR)
	cc -g3 $(CFLAGS) -c -o $@ $^

clean:
	make clean -C ./libft/
	rm -fr $(OBJ_DIR)

fclean: clean
	make fclean -C ./libft/
	rm -f $(NAME) $(NAME_CHECKER)

re: fclean all

.PHONY: all fclean clean re bonus
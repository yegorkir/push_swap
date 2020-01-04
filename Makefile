# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdeanne <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/04 21:45:26 by mdeanne           #+#    #+#              #
#    Updated: 2020/01/04 21:45:27 by mdeanne          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_CHECKER_FILE = checker
NAME_PUSH_SWAP_FILE = push_swap
LIB_NAME = ./libft/libft.a

FLAGS = -Wall -Wextra -Werror

SRC_GEN = ./stack/
SRC_CHECKER = ./checker_dir/
SRC_PUSH_SWAP = ./push_swap_dir/
HEAD_PATH = ./includes/
LIB_PATH = ./libft/

SRC_FILES_GEN = checking.c ft_ll_atoi.c ft_stack.c go_exit.c
SRC_FILES_CHECKER = check_result.c do_rules_checker.c main_checker.c \
					perform_rules.c read_n_execute.c
SRC_FILES_PUSH_SWAP = do_rules_ps.c find_min_max_thirds.c indexing_list.c \
					main_push_swap.c sort_in_three_groups.c sort_triples.c \
					sort_triples_choose_rules.c triple_basic_algorithms.c \
					triple_a_bottom_algorithms.c triple_a_top_algorithms.c \
					triple_b_bottom_algorithms.c triple_b_top_algorithms.c \
					sorter.c

SRCS_GEN = $(addprefix $(SRC_GEN),$(SRC_FILES_GEN))
SRCS_CHECKER = $(addprefix $(SRC_CHECKER),$(SRC_FILES_CHECKER))
SRCS_PUSH_SWAP = $(addprefix $(SRC_PUSH_SWAP),$(SRC_FILES_PUSH_SWAP))

OBJS_GEN = $(SRC_FILES_GEN:.c=.o)
OBJS_CHECKER = $(SRC_FILES_CHECKER:.c=.o)
OBJS_PUSH_SWAP = $(SRC_FILES_PUSH_SWAP:.c=.o)


all: $(NAME_CHECKER_FILE) $(NAME_PUSH_SWAP_FILE)

$(NAME_CHECKER_FILE): $(LIB_NAME) $(OBJS_GEN) $(OBJS_CHECKER)
	@gcc -o $(NAME_CHECKER_FILE) $(OBJS_GEN) $(OBJS_CHECKER) -L$(LIB_PATH) -lft

$(NAME_PUSH_SWAP_FILE): $(LIB_NAME) $(OBJS_GEN) $(OBJS_PUSH_SWAP)
	@gcc -o $(NAME_PUSH_SWAP_FILE) $(OBJS_GEN) $(OBJS_PUSH_SWAP) -L$(LIB_PATH) -lft

$(OBJS_GEN):
	@gcc -c $(SRCS_GEN) $(FLAGS) -I$(HEAD_PATH) -I$(LIB_PATH)

$(OBJS_CHECKER):
	@gcc -c $(SRCS_CHECKER) $(FLAGS) -I$(HEAD_PATH) -I$(LIB_PATH)

$(OBJS_PUSH_SWAP):
	@gcc -c $(SRCS_PUSH_SWAP) $(FLAGS) -I$(HEAD_PATH) -I$(LIB_PATH)

$(LIB_NAME):
	@make -C $(LIB_PATH) re

clean:
	@rm -f $(OBJS_GEN)
	@rm -f $(OBJS_CHECKER)
	@rm -f $(OBJS_PUSH_SWAP)
	@make -C $(LIB_PATH) clean

fclean: clean
	@rm -f $(NAME_CHECKER_FILE)
	@rm -f $(NAME_PUSH_SWAP_FILE)
	@make -C $(LIB_PATH) fclean

re: fclean all
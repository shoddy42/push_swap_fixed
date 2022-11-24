# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: wkonings <wkonings@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/10/29 16:21:56 by wkonings      #+#    #+#                  #
#    Updated: 2022/11/24 16:25:41 by wkonings      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #


# --------------- VARIABLES ---------------#

NAME		:=	push_swap
CC			:=	gcc
FLAGS		:=	-Wall -Wextra -Werror

# --------------- DIRECTORIES ------------ #

BIN_DIR		:=
INCLUDE_DIR	:=	include
LIBS_DIR	:=	libft
OBJS_DIR	:= 	obj
SRC_DIR		:=	src

# --------------- FILES -------------------#

HEADERS		:=	$(addprefix $(INCLUDE_DIR)/, push_swap.h)
FILES		:=	main algo utils ps_reverse ps_rotate ps_swap atol_split
SRCS		:=	$(addprefix $(SRC_DIR)/,$(FILES:%=%.c))
OBJS		:=	$(addprefix $(OBJS_DIR)/,$(notdir $(SRCS:%.c=%.o)))
LIB_LIST	:=	$(LIBS_DIR)/libft.a
LIB_FT		:=	libft
INC			:=	-I include

all: $(NAME)

$(NAME): $(OBJS) $(LIB_LIST)
	$(CC) $(FLAGS) $(INC) -o $(NAME) $^

$(OBJS_DIR)/%.o:$(SRC_DIR)/%.c | $(HEADERS)
	@mkdir -p $(dir $@)
	$(CC) $(FLAGS) $(INC) -c $< -o $@ 

$(LIB_LIST):
	@make -C $(LIBS_DIR)

clean:
	/bin/rm -rf $(OBJS_DIR)

fclean:	clean
	/bin/rm -f $(NAME)

libclean:
	@make -C $(LIBS_DIR) fclean

mrclean: libclean fclean

re: fclean all


.PHONY: all clean fclean re libclean flclean
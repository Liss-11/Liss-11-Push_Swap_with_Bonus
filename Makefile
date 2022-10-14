# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afrolova <afrolova@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/12 00:19:49 by afrolova          #+#    #+#              #
#    Updated: 2022/10/14 23:30:41 by afrolova         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
#COLORS

END_COLOR = \033[0;0m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

#PROGRAMM NAMES

NAME = push_swap
CHECKER = checker

#DIRECTORIES

DIR_SRCS = SRCS
DIR_INC = INC
DIR_PS = $(DIR_SRCS)/Push_Swap
DIR_CH = $(DIR_SRCS)/Checker

DIR_SRCS_PS = $(DIR_PS)/SRCS_PS
DIR_SRCS_CH = $(DIR_CH)/SRCS_CH

DIR_OBJ_PS = $(DIR_PS)/OBJ_PS
DIR_OBJ_CH = $(DIR_CH)/OBJ_CH

DIR_LIBFT = $(DIR_SRCS)/Libft

#LIBRARY

LIBFT =	$(DIR_LIBFT)/libft.a

#HEADERS

HEADER_LIBFT = $(DIR_LIBFT)/INC/libft.h
HEADER_PS = $(DIR_INC)/push_swap.h
HEADER_CH = $(DIR_INC)/checker.h
	
#PUSH_SWAP FILES

FILES_PS = 	main.c \
			check_errors.c \
			initializer.c \
			swap_mov_and_actions.c \
			push_mov_and_actions.c \
			rotate_mov_and_actions.c \
			reverse_mov_and_actions.c \
			two_three_algorithm.c \
			four_five_algorithm.c \
			from_six_algorithm.c \
			smart_rotate.c 

#CHECKER FILES

FILES_CH = main.c \
		   check_errors.c \
		   ininializer.c \
		   instructions_reader.c \
		   push_mov_and_actions.c \
		   reverse_mov_and_actions.c \
		   rotate_mov_and_actions.c \
		   swap_mov_and_actions.c

#VARIABLES

CFLAGS =	-Wall -Werror -Wextra
CC =		gcc 
RM =		rm -rf
MKDIR = 	mkdir -p

#OBJECTS VARIABLES

OBJ_PS = $(addprefix $(DIR_OBJ_PS)/, $(FILES_PS:.c=.o))
OBJ_CH = $(addprefix $(DIR_OBJ_CH)/, $(FILES_CH:.c=.o))


all:
			@$(MAKE) -C $(DIR_LIBFT)
			@$(MAKE) $(NAME)

#Compiling Rules for PUSH_SWAP


$(NAME)::	$(DIR_OBJ_PS) $(OBJ_PS) $(LIBFT) Makefile
			@$(CC) $(CFLAGS) $(OBJ_PS) $(LIBFT) -o $(NAME)
			@echo "$(BLUE)Compiling push_swap...$(END_COLOR)"

$(NAME)::
			@echo "$(GREEN)Push_Swap is Compiled!$(END_COLOR)"

$(DIR_OBJ_PS)/%.o:	$(DIR_SRCS_PS)/%.c $(HEADER_PS)
					@$(CC) $(CFLAGS) -I $(DIR_INC) -I $(DIR_LIBFT) -c $< -o $@
					@echo "$(YELLOW)Compiling $<"

$(DIR_OBJ_PS):
					@-mkdir $(DIR_OBJ_PS)

#Compiling Ruler for CHECKER

bonus::		$(DIR_OBJ_CH) $(OBJ_CH) $(LIBFT) Makefile
			@$(MAKE) -C $(DIR_LIBFT)
			@$(CC) $(CFLAGS) $(OBJ_CH) $(LIBFT) -o $(CHECKER)
			@echo "$(BLUE)Compiling checker...$(END_COLOR)"

bonus::
			@echo "$(GREEN)Checker is COMPILED!$(END_COLOR)"

$(DIR_OBJ_CH)/%.o:	$(DIR_SRCS_CH)/%.c $(HEADER_CH)
					@$(CC) $(CFLAGS) -I $(DIR_INC) -I $(DIR_LIBFT) -c $< -o $@
					@echo "$(YELLOW)Compiling $<"

$(DIR_OBJ_CH):
					@-mkdir $(DIR_OBJ_CH)


#CLEANING RULES


clean:	
		@$(RM) $(OBJ_PS)
		@$(RM) $(OBJ_CH)
		@make clean -C $(DIR_LIBFT)
		@$(RM) $(DIR_OBJ_PS)
		@$(RM) $(DIR_OBJ_CH)
		@echo "${BLUE}All Objects are removed!${END_COLOR}"

fclean:
		@$(MAKE) clean
		@$(RM) $(NAME)
		@$(RM) $(CHECKER)
		@make fclean -C $(DIR_LIBFT)
		@echo "${BLUE}ALL CLEANED!${END_COLOR}"

re:
		@$(MAKE) fclean
		@$(MAKE) all
		@echo "${YELLOW}Cleaned und rebuilt everything for push_swap${END_COLOR}" 
		
		
		
.PHONY:	all clean fclean re 

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/02 21:44:36 by wportilh          #+#    #+#              #
#    Updated: 2022/09/19 20:02:22 by wportilh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCES =		minishell.c	main.c ft_msg_erro.c handle_spaces.c \
				ft_str_swap_chr.c ft_lstadd_back_t.c ft_lstnew_t.c \
				lexer.c signals.c executor.c\

NAME =			minishell

CC =			cc
CFLAGS =		-g3 -Wall -Wextra -Werror
RM =			rm -f
RM_ALL =		rm -rf

VAL =			valgrind --leak-check=full --show-leak-kinds=all

LIBFT =			./libft/libft.a

LIB =			./libft
PRINT =			./printf
INC =			./inc

SRC_PATH =		src/
OBJ_PATH =		obj/

SRCS =			${addprefix ${SRC_PATH}, ${SOURCES}}
OBJS =			${addprefix ${OBJ_PATH}, ${SOURCES:.c=.o}}

ITALIC =		\033[3m
BLACK =			\033[30m
RED =			\033[31m
GREEN =			\033[32m
YELLOW =		\033[33m
BLUE =			\033[34m
PURPLE =		\033[35m
CYAN =			\033[36m
WHITE =			\033[37m
RESET =			\033[0m

all:			${NAME}

${NAME}:		${LIBFT} ${OBJS}
				@echo "${CYAN}=========="
				@echo "OBJS OK!!!"
				@echo "=========="
				@${CC} -lreadline ${OBJS} ${LIBFT} -o ${NAME}
				@echo "============================"
				@echo "MINISHELL PROGRAM CREATED!!!"
				@echo "============================${RESET}"

${OBJ_PATH}%.o:	${SRC_PATH}%.c
				@mkdir -p obj
				@${CC} ${CFLAGS} -c $< -o $@

${LIBFT}:
				@make -C ./libft
				@make -C ./printf

ac:				${NAME}
				@make clean
				clear

clean:		
				@${RM_ALL} ${OBJ_PATH}
				@make clean -C ./libft/
				@make clean -C ./printf/
				@echo "${CYAN}=================="
				@echo "CLEAN COMPLETED!!!"
				@echo "==================${RESET}"
				@sleep 1

fclean:			clean
				@${RM} ${NAME}
				@make fclean -C ./libft/
				@make fclean -C ./printf/
				@echo "${CYAN}==================="
				@echo "FCLEAN COMPLETED!!!"
				@echo "===================${RESET}"
				@sleep 1

re:				fclean all
				@echo "${CYAN}==============="
				@echo "RE COMPLETED!!!"
				@echo "===============${RESET}"

norm:
				norminette ${SRCS} ${LIB} ${INC}

.PHONY:			all clean fclean re norm ac

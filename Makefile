# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/02 21:44:36 by wportilh          #+#    #+#              #
#    Updated: 2022/09/21 00:15:19 by wportilh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCES =		minishell.c	main.c signals.c		
LEXER =			lexer.c handle_spaces.c
LIST =			ft_lstadd_back_t.c ft_lstnew_t.c ft_lstfoward_free_t.c
PARSER =		parser.c
EXECUTOR =		exec_clean.c pipe.c redirects.c executor.c

NAME =			minishell

CC =			cc
CFLAGS =		-g3 -Wall -Wextra -Werror
READ_LINE =		-lreadline #-lft
RM =			rm -f
RM_ALL =		rm -rf

VAL =			valgrind --leak-check=full --show-leak-kinds=all

LIBFT =			./libft/libft.a

LIB =			./libft
PRINT =			./printf
INC =			./inc

SRC_PATH =		src/
SRC_EXEC =		src/executor/
SRC_LEXER =		src/lexer/
SRC_PARSER =	src/parser/
SRC_LIST =		src/list/

OBJ_PATH =		obj/

SRCS =			${addprefix ${SRC_PATH}, ${SOURCES}}

OBJS_EXEC =		${addprefix ${OBJ_PATH}, ${EXECUTOR:.c=.o}}
OBJS_LEXER =	${addprefix ${OBJ_PATH}, ${LEXER:.c=.o}}
OBJS_PARSER =	${addprefix ${OBJ_PATH}, ${PARSER:.c=.o}}
OBJS_LIST =		${addprefix ${OBJ_PATH}, ${LIST:.c=.o}}
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

${NAME}:		${LIBFT} ${OBJS} ${OBJS_EXEC} ${OBJS_PARSER} ${OBJS_LEXER} ${OBJS_LIST}
				@echo "${CYAN}=========="
				@echo "OBJS OK!!!"
				@echo "=========="
				@${CC} ${READ_LINE} ${OBJS} ${OBJS_EXEC} ${OBJS_PARSER} ${OBJS_LEXER} ${OBJS_LIST} ${LIBFT} -o ${NAME}
				@echo "============================"
				@echo "MINISHELL PROGRAM CREATED!!!"
				@echo "============================${RESET}"

${OBJ_PATH}%.o:	${SRC_EXEC}%.c
				@mkdir -p obj
				@${CC} ${CFLAGS} -c $< -o $@

${OBJ_PATH}%.o:	${SRC_LIST}%.c
				@mkdir -p obj
				@${CC} ${CFLAGS} -c $< -o $@

${OBJ_PATH}%.o:	${SRC_PARSER}%.c
				@mkdir -p obj
				@${CC} ${CFLAGS} -c $< -o $@

${OBJ_PATH}%.o:	${SRC_LEXER}%.c
				@mkdir -p obj
				@${CC} ${CFLAGS} -c $< -o $@

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
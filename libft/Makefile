# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/02 21:44:36 by wportilh          #+#    #+#              #
#    Updated: 2022/09/19 23:21:00 by wportilh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCES	=										\
						ft_isalpha.c			\
						ft_isdigit.c			\
						ft_isalnum.c			\
						ft_isascii.c			\
						ft_isprint.c			\
						ft_strlen.c				\
						ft_memset.c				\
						ft_bzero.c				\
						ft_memcpy.c				\
						ft_memmove.c			\
						ft_strlcpy.c			\
						ft_strlcat.c			\
						ft_toupper.c			\
						ft_tolower.c			\
						ft_strchr.c				\
						ft_strrchr.c			\
						ft_strcmp.c				\
						ft_strncmp.c			\
						ft_memchr.c				\
						ft_memcmp.c				\
						ft_strnstr.c			\
						ft_atoi.c				\
						ft_calloc.c				\
						ft_strdup.c				\
						ft_substr.c				\
						ft_strjoin.c			\
						ft_strtrim.c			\
						ft_split.c				\
						ft_itoa.c				\
						ft_strmapi.c			\
						ft_striteri.c			\
						ft_putchar_fd.c			\
						ft_putstr_fd.c			\
						ft_putendl_fd.c			\
						ft_putnbr_fd.c			\
						get_next_line.c			\
						get_next_line_utils.c	\
						ft_lstnew.c				\
						ft_lstadd_front.c		\
						ft_lstsize.c			\
						ft_lstlast.c			\
						ft_lstadd_back.c		\
						ft_lstdelone.c			\
						ft_lstclear.c			\
						ft_lstiter.c			\
						ft_lstmap.c

SOURCES_EXTRA =									\
						ft_atol.c               \
						ft_str_insert_free.c	\
						ft_str_is_equal.c       \
						ft_free_int_array.c     \
						ft_free_vector.c

NAME =					libft.a

CC =					cc
CREATE =				ar rc
CFLAGS =				-g3 -Wall -Wextra -Werror
RM =					rm -f
RM_ALL =				rm -rf

INC =					../inc

SRC_PATH =				./src/
SRC_EXTRA_PATH =		./src_extra/
OBJ_PATH =				./obj/
OBJ_EXTRA_PATH =		./obj/

OBJS =					${addprefix ${OBJ_PATH}, ${SOURCES:.c=.o}}
OBJS_EXTRA =			${addprefix ${OBJ_EXTRA_PATH}, ${SOURCES_EXTRA:.c=.o}}

ITALIC =				\033[3m
BLACK =					\033[30m
RED =					\033[31m
GREEN =					\033[32m
YELLOW =				\033[33m
BLUE =					\033[34m
PURPLE =				\033[35m
CYAN =					\033[36m
WHITE =					\033[37m
RESET =					\033[0m

${NAME}:				${OBJS} ${OBJS_EXTRA}
						@${CREATE} ${NAME} ${OBJS} ${OBJS_EXTRA}
						@echo "${CYAN}================="
						@echo "LIBFT COMPILED!!!"
						@echo "=================${RESET}"

${OBJ_PATH}%.o:			${SRC_PATH}%.c
						@mkdir -p obj
						@${CC} ${CFLAGS} -c $< -o $@

${OBJ_EXTRA_PATH}%.o:	${SRC_EXTRA_PATH}%.c
						@mkdir -p obj
						@${CC} ${CFLAGS} -c $< -o $@

all:					${NAME}

clean:		
						@${RM_ALL} ${OBJ_PATH}

fclean:					clean
						@${RM} ${NAME}

re:						fclean all

.PHONY:					all clean fclean re
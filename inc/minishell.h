/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 23:11:52 by wportilh          #+#    #+#             */
/*   Updated: 2022/09/15 19:06:18 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "./libft.h"
# include "./ft_printf.h"
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>

# define TEMP_VALUE	1

typedef struct s_envp
{
	char			*key;
	char			*value;
	struct s_envp	*next;
}					t_envp;

typedef struct s_tokens
{
	char			*str;
	int				token;
	t_bool			error;
	struct s_tokens	*next;
}					t_tokens;

/**
 * @brief List of tokens to help lexer and parser
 * 
 * @param B_SLASH \
 * @param COMMAND ls -a (example)
 * @param S_QUOTE '
 * @param D_QUOTE "
 * @param S_COLON ;
 * @param PIPE |
 * @param I_REDIRECT <
 * @param O_REDIRECT >
 * @param APP_O_REDIRECT >>
 * @param DELIMITER <<
 * @param EXPANDABLE "$hi" (example)
 * @param NOT_EXPANDABLE '$hi' (example)
 */
enum e_tokens
{
	D_QUOTE = 34,
	DOLAR = 36,
	S_QUOTE = 39,
	S_COLON = 59,
	I_REDIRECT = 60,
	O_REDIRECT = 62,
	B_SLASH = 92,
	PIPE = 124,
	COMMAND = 666,
	APP_O_REDIRECT = 667,
	DELIMITER = 668,
	NOT_EXPANDABLE = 669,
	EXPANDABLE = 670,
};

/**
 * @brief Print an msg to a given fd and give an erro return
 * 
 * @param msg Msg to be printed
 * @param erro Erro to be returned
 * @param fd FD where msg will be printed
 * @return int the return can be used as exit_status, as boolean,
 * signal trigger and others
 */
int			ft_msg_er(char *msg, int erro, int fd);
/**
 * @brief Iterates through some string address and swap the
 * indicated old character by the new one
 * 
 * @param str pointer to a string
 * @param old character of the string to be switched
 * @param new character to be added
 */
void		ft_str_swap_chr(char **str, char old, char new);

/**
 * @brief start the prompt and REPL
 * 
 */
void		minishell(void);
/**
 * @brief Under construction
 * 
 * @param tks 
 * @param str 
 */
void		lexer(t_tokens **tks, char **str);

/* ---------------------------------------------------------------------*\
|	handle_spaces.c														 |
\* ---------------------------------------------------------------------*/
void		clean_space(char *str);
void		add_space(char **str);

void		ft_lstadd_back_t(t_tokens **lst, t_tokens *new);
t_tokens	*ft_lstnew_t(char *str);

#endif
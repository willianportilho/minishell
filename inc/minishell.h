/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 23:11:52 by wportilh          #+#    #+#             */
/*   Updated: 2022/09/13 19:17:03 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "./libft.h"
# include "./ft_printf.h"
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>

/**
 * @brief List of tokens to help lexer and parser
 * @param BACKSLASH \
 * @param COMMAND ls -a (example)
 * @param S_QUOTE '
 * @param D_QUOTE "
 * @param SEMICOLON ;
 * @param PIPE |
 * @param I_REDIRECT <
 * @param O_REDIRECT >
 * @param APP_O_REDIRECT >>
 * @param DELIMITER <<
 */
typedef enum e_tokens
{
	D_QUOTE = 34,
	DOLAR = 36,
	S_QUOTE = 39,
	SEMICOLON = 59,
	I_REDIRECT = 60,
	O_REDIRECT = 62,
	BACKSLASH = 92,
	PIPE = 124,
	COMMAND = 666,
	APP_O_REDIRECT = 667,
	DELIMITER = 668,
}	t_tokens;

/**
 * @brief Print an msg to a given fd and give an erro return
 * 
 * @param msg Msg to be printed
 * @param erro Erro to be returned
 * @param fd FD where msg will be printed
 * @return int the return can be used as exit_status, as boolean,
 * signal trigger and others
 */
int		ft_msg_er(char *msg, int erro, int fd);

/**
 * @brief start the prompt and REPL
 * 
 */
void	minishell(void);

#endif
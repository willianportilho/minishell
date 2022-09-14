/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 16:59:56 by ralves-b          #+#    #+#             */
/*   Updated: 2022/09/14 20:25:37 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

static int	check_semicolon_and_backslash(char *buff)
{
	int		i;
	t_bool	btwn_s_quotes;
	t_bool	btwn_d_quotes;

	btwn_s_quotes = FALSE;
	btwn_d_quotes = FALSE;
	i = -1;
	while (buff[++i])
	{
		if (buff[i] == D_QUOTE && !btwn_d_quotes && !btwn_s_quotes)
			btwn_d_quotes = TRUE;
		else if (buff[i] == D_QUOTE && btwn_d_quotes)
			btwn_d_quotes = FALSE;
		else if (buff[i] == S_QUOTE && !btwn_s_quotes && !btwn_d_quotes)
			btwn_s_quotes = TRUE;
		else if (buff[i] == S_QUOTE && btwn_s_quotes)
			btwn_s_quotes = FALSE;
		if ((buff[i] == SEMICOLON || buff[i] == BACKSLASH)
			&& !btwn_d_quotes && !btwn_s_quotes)
			return (ft_msg_er("invalid ; or \\\n", EXIT_FAILURE, STDOUT_FILENO));
	}
	if (btwn_d_quotes || btwn_s_quotes)
		return (ft_msg_er("unclosed quotes\n", EXIT_FAILURE, STDOUT_FILENO));
	return (EXIT_SUCCESS);
}

/*	D_QUOTE = 34,
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
	NOT_EXPANDABLE = 669,
	EXPANDABLE = 670*/



void	lexer(t_tokens **tks, char **str)
{
	(void)tks;
	char	**tks_aux;
	int i;

	i = 0;
	clean_space(*str);
	add_space(str);
	tks_aux = ft_split(*str, SPACE);
	while (tks_aux[i])
	{
		ft_str_swap_chr(&tks_aux[i], TEMP_VALUE, SPACE);
		i++;		
	}

}

void	minishell(void)
{
	char		*buff;
	t_tokens	*tokens;

	while (TRUE)
	{
		buff = readline(">>");
		if (buff != NULL && *buff != '\0')
		{
			add_history(buff);
		}
		if (check_semicolon_and_backslash(buff))
			continue ;
		else
		{
			lexer(&tokens, &buff);
		}
	}
}

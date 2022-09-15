/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 16:59:56 by ralves-b          #+#    #+#             */
/*   Updated: 2022/09/15 15:00:47 by ralves-b         ###   ########.fr       */
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

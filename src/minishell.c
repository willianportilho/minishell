/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 16:59:56 by ralves-b          #+#    #+#             */
/*   Updated: 2022/09/20 16:24:38 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

static void	reset_tab(t_table **tab)
{
	t_table	*aux;
	t_table	*temp;
	int		i;

	i = -1;
	aux = *tab;
	while (aux)
	{
		while (aux->path[++i])
			aux->path[i] = ft_strtrim_free(aux->path[i], aux->cmd_line[0]);
		i = -1;
		while (aux->cmd_line[++i])
			free(aux->cmd_line[i]);
		free(aux->cmd_line);
		temp = aux->next;
		free(aux);
		aux = temp;
	}
	*tab = malloc(sizeof(t_table));
}

static int	check_semicolon_and_backslash(char *buff)
{
	int		i;
	t_bool	bt_s_qt;
	t_bool	bt_d_qt;

	if (!buff)
		return (EXIT_SUCCESS);
	bt_s_qt = FALSE;
	bt_d_qt = FALSE;
	i = -1;
	while (buff[++i])
	{
		if (buff[i] == D_QUOTE && !bt_d_qt && !bt_s_qt)
			bt_d_qt = TRUE;
		else if (buff[i] == D_QUOTE && bt_d_qt)
			bt_d_qt = FALSE;
		else if (buff[i] == S_QUOTE && !bt_s_qt && !bt_d_qt)
			bt_s_qt = TRUE;
		else if (buff[i] == S_QUOTE && bt_s_qt)
			bt_s_qt = FALSE;
		if ((buff[i] == S_COLON || buff[i] == B_SLASH) && !bt_d_qt && !bt_s_qt)
			return (ft_msg_er("invalid ; or \\\n", EXIT_FAILURE, STDOUT_FILENO));
	}
	if (bt_d_qt || bt_s_qt)
		return (ft_msg_er("unclosed quotes\n", EXIT_FAILURE, STDOUT_FILENO));
	return (EXIT_SUCCESS);
}

void	minishell(t_table **tab)
{
	char		*buff;
	t_tokens	*tokens;

	while (TRUE)
	{
		buff = readline(">>");
		if (buff != NULL)
		{
			if (*buff != '\0')
				add_history(buff);
		}
		else
		{
			ft_printf(" exit\n");
			exit (EXIT_SUCCESS);
		}
		if (!check_semicolon_and_backslash(buff))
			lexer(&tokens, &buff, tab);
		executor(tab);
		reset_tab(tab);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 16:59:56 by ralves-b          #+#    #+#             */
/*   Updated: 2022/09/28 19:55:40 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	not_ful_space(char *buff)
{
	int	i;

	i = 0;
	while (buff[i])
	{
		if ((buff[i] >= 9 && buff[i] <= 13) || (buff[i] == ' '))
			i++;
		else
			return (1);
	}
	free(buff);
	return (0);
}

static void	reset_tab(char *buff)
{
	char	**envp;

	envp = ft_array_dup(global()->envp);
	clean_exit(buff);
	hard_init(envp);
	ft_free_array(envp);
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
			return (free(buff), ft_msg_er("invalid ; or \\\n", 1, 1));
	}
	if (bt_d_qt || bt_s_qt)
		return (ft_msg_er("unclosed quotes\n", EXIT_FAILURE, STDOUT_FILENO));
	return (EXIT_SUCCESS);
}

void	minishell(t_table **tab)
{
	char		*buff;
	t_tokens	*tokens;

	global()->test = FALSE;
	while (TRUE)
	{
		global()->control = FALSE;
		signal_main();
		buff = readline(">>");
		if (buff != NULL)
		{
			if (*buff != '\0')
				add_history(buff);
		}
		else
			exit(msg_n_exit_function("exit\n", &clean_exit, buff));
		if (!check_semicolon_and_backslash(buff) && not_ful_space(buff))
			lexer(&tokens, &buff, tab);
		if (global()->control)
		{
			executor(tab);
			reset_tab(ft_strdup("cavalinho"));
		}
	}
}

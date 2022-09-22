/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 12:44:27 by ralves-b          #+#    #+#             */
/*   Updated: 2022/09/22 13:54:50 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	simple_init(t_table *tab)
{
	tab->next = NULL;
	tab->envp = NULL;
}

void	get_path(char **envp, t_table *p, int i)
{
	char	**temp;

	temp = NULL;
	while (envp[i])
	{
		if (ft_strnstr(envp[i], "PATH=", 5))
		{
			temp = ft_split(envp[i] + 5, ':');
			break ;
		}
		i++;
	}
	if (temp == NULL)
		ft_msg_er("PATH not found", 0, 2);
	i = 0;
	while (temp[i])
		i++;
	p->path = (char **)malloc((i + 1) * sizeof(*temp));
	p->path[i] = NULL;
	while (i--)
		p->path[i] = ft_strjoin_free(temp[i], "/");
	free(temp);
}

static int	is_something_that_i_didnt_named_yet(int tk)
{
	if (tk != I_REDIRECT && tk != O_REDIRECT && tk != PIPE
		&& tk != DELIMITER && tk != APP_O_REDIRECT)
		return (1);
	return (0);
}

static void	is_redirect(t_tokens **tks, t_bool *boolean, char **file)
{
	*boolean = TRUE;
	ft_lstfoward_free_t(tks);
	*file = ft_strdup((*tks)->str);
	ft_lstfoward_free_t(tks);
}

void	parser(t_tokens **tks, t_table *tab, char **envp)
{
	int	i;

	i = -1;
	if ((*tks) && (*tks)->token == I_REDIRECT)
		is_redirect(tks, &tab->in_red, &tab->in_file);
	if ((*tks) && (*tks)->token == O_REDIRECT)
		is_redirect(tks, &tab->out_red, &tab->out_file);
	if ((*tks) && (*tks)->token == DELIMITER)
		heredoc_caller(tks, &tab, envp);
	if ((*tks) && (*tks)->token == APP_O_REDIRECT)
		is_redirect(tks, &tab->out_append, &tab->out_file);
	while ((*tks) && is_something_that_i_didnt_named_yet((*tks)->token))
	{
		tab->cmd = ft_strjoin_free(tab->cmd, (*tks)->str);
		tab->cmd = ft_strjoin_free(tab->cmd, " ");
		ft_lstfoward_free_t(tks);
	}
	if ((*tks) && (*tks)->token == PIPE)
	{
		tab->pipe = TRUE;
		ft_lstfoward_free_t(tks);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 12:44:27 by ralves-b          #+#    #+#             */
/*   Updated: 2022/09/28 20:23:14 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	simple_init(t_table *tab)
{
	tab->envp = NULL;
	tab->next = NULL;
}

void	get_path(t_table *p, int i)
{
	char	**temp;

	temp = NULL;
	while (global()->envp[i])
	{
		if (ft_strnstr(global()->envp[i], "PATH=", 5))
			temp = ft_split(global()->envp[i] + 5, ':');
		i++;
	}
	if (temp == NULL)
	{
		temp = ft_create_blank_array();
		return ;
	}
	i = 0;
	while (temp[i])
		i++;
	ft_free_array(p->path);
	p->path = (char **)malloc((i + 1) * sizeof(*temp));
	p->path[i] = NULL;
	while (i--)
		p->path[i] = ft_strjoin_free(temp[i], "/");
	free(temp);
	global()->control = TRUE;
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
	char	*msg_erro;

	msg_erro = ft_strdup("newline");
	ft_lstfoward_free_t(tks);
	if (!(*tks) || !is_something_that_i_didnt_named_yet((*tks)->token))
	{
		if (*tks)
		{
			free(msg_erro);
			msg_erro = ft_strdup((*tks)->str);
			while (*tks)
				ft_lstfoward_free_t(tks);
		}
		ft_putstr_fd(SYNTXERR, 2);
		ft_putstr_fd(msg_erro, 2);
		ft_putstr_fd("'\n", 2);
		free(msg_erro);
		global()->control = FALSE;
		global()->exit = 2;
		return ;
	}
	*boolean = TRUE;
	free(*file);
	*file = ft_strdup((*tks)->str);
	ft_lstfoward_free_t(tks);
}

void	parser(t_tokens **tks, t_table *tab)
{
	int	i;

	i = -1;
	if ((*tks) && (*tks)->token == I_REDIRECT)
		is_redirect(tks, &tab->in_red, &tab->in_file);
	if ((*tks) && (*tks)->token == O_REDIRECT)
		is_redirect(tks, &tab->out_red, &tab->out_file);
	if ((*tks) && (*tks)->token == DELIMITER)
		heredoc_caller(tks, &tab);
	if ((*tks) && (*tks)->token == APP_O_REDIRECT)
		is_redirect(tks, &tab->out_append, &tab->out_file);
	while ((*tks) && is_something_that_i_didnt_named_yet((*tks)->token))
	{
		expand(tks);
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

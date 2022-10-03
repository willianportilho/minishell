/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 12:44:27 by ralves-b          #+#    #+#             */
/*   Updated: 2022/10/03 17:39:24 by ralves-b         ###   ########.fr       */
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
		temp = ft_create_blank_array();
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

void	teste_open(int red, char **file, t_table **tab)
{
	int	fd;

	if ((*tab)->error)
		free(*file);
	else if (red == I_REDIRECT && !(*tab)->error)
	{
		(*tab)->in_red = TRUE;
		free((*tab)->in_file);
		(*tab)->in_file = *file;
		fd = open(*file, O_RDONLY);
		if (fd == -1)
			(*tab)->error = TRUE;
		else
			close(fd);
	}
	else if (red == O_REDIRECT && !(*tab)->error)
	{
		(*tab)->out_red = TRUE;
		free((*tab)->out_file);
		(*tab)->out_file = *file;
		fd = open((*tab)->out_file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (fd == -1)
			(*tab)->error = TRUE;
		else
			close(fd);
	}
	else if (red == APP_O_REDIRECT && !(*tab)->error)
	{
		(*tab)->out_append = TRUE;
		free((*tab)->out_file);
		(*tab)->out_file = *file;
		fd = open((*tab)->out_file, O_WRONLY | O_CREAT | O_APPEND, 0644);
		if (fd == -1)
			(*tab)->error = TRUE;
		else
			close(fd);
	}
}

static void	is_redirect(t_tokens **tks, t_table **tab)
{
	char	*file;
	int		red;

	red = (*tks)->token;
	ft_lstfoward_free_t(tks);
	if (!(*tks) || !is_something_that_i_didnt_named_yet((*tks)->token))
	{
		tkn_error(tks);
		return ;
	}
	file = ft_strdup((*tks)->str);
	expand(&file);
	bring_temp_values_back(&file);
	teste_open(red, &file, tab);
	ft_lstfoward_free_t(tks);
}

void	parser(t_tokens **tks, t_table *tab)
{
	if ((*tks) && (*tks)->token == I_REDIRECT)
		is_redirect(tks, &tab);
	if ((*tks) && (*tks)->token == O_REDIRECT)
		is_redirect(tks, &tab);
	if ((*tks) && (*tks)->token == DELIMITER)
		heredoc_caller(tks, &tab);
	if ((*tks) && (*tks)->token == APP_O_REDIRECT)
		is_redirect(tks, &tab);
	while ((*tks) && is_something_that_i_didnt_named_yet((*tks)->token))
	{
		expand(&(*tks)->str);
		tab->cmd = ft_strjoin_free(tab->cmd, (*tks)->str);
		tab->cmd = ft_strjoin_free(tab->cmd, " ");
		ft_lstfoward_free_t(tks);
	}
	if ((*tks) && (*tks)->token == PIPE)
	{
		tab->pipe = TRUE;
		ft_lstfoward_free_t(tks);
		if (!(*tks))
		{
			tkn_error(tks);
			return ;
		}
	}
}

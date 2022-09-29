/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 13:39:38 by ralves-b          #+#    #+#             */
/*   Updated: 2022/09/29 17:57:40 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	false_all(t_table *tab)
{
	tab->pipe = FALSE;
	tab->in_red = FALSE;
	tab->infile_fd = -1;
	tab->out_red = FALSE;
	tab->outfile_fd = -1;
	tab->path_done = FALSE;
	tab->out_append = FALSE;
	tab->in_delimiter = FALSE;
}

void	init_new_tab(t_table *tab)
{
	tab->cmd = ft_strdup("");
	tab->cmd_line = ft_create_blank_array();
	tab->path = ft_create_blank_array();
	tab->envp = NULL;
	tab->envp = ft_create_blank_array();
	tab->next = NULL;
	tab->in_file = ft_strdup("");
	tab->out_file = ft_strdup("");
}

void	hard_init(char **envp)
{
	global()->test = 0;
	global()->heredoc = 0;
	global()->envp = ft_array_dup(envp);
	global()->tabble = malloc(sizeof(t_table));
	init_new_tab(global()->tabble);
}

t_test	*global(void)
{
	static t_test	test;

	return (&test);
}

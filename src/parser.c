/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 12:44:27 by ralves-b          #+#    #+#             */
/*   Updated: 2022/09/20 14:56:45 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

static int	is_something_that_i_didnt_named_yet(int tk)
{
	if (tk != I_REDIRECT && tk != O_REDIRECT && tk != PIPE)
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

void	parser(t_tokens **tks, t_table *tab)
{
	int	i;

	i = -1;
	if ((*tks)->token == I_REDIRECT)
		is_redirect(tks, &tab->in_red, &tab->in_file);
	if ((*tks)->token == O_REDIRECT)
		is_redirect(tks, &tab->out_red, &tab->out_file);
	while ((*tks) && is_something_that_i_didnt_named_yet((*tks)->token))
	{
		tab->cmd = ft_strjoin_free(tab->cmd, (*tks)->str);
		tab->cmd = ft_strjoin_free(tab->cmd, " ");
		ft_lstfoward_free_t(tks);
	}
	// clean_space(tab->cmd);
	// tab->cmd_line = ft_split(tab->cmd, ' ');
	// ft_str_swap_chr(&tab->cmd, TEMP_VALUE, SPACE);
	// while (tab->cmd_line[++i])
	// 	ft_str_swap_chr(&tab->cmd_line[i], TEMP_VALUE, SPACE);
	if ((*tks) && (*tks)->token == PIPE)
	{
		tab->pipe = TRUE;
		tab->next = malloc(sizeof(tab));
		ft_lstfoward_free_t(tks);
	}
	if (!(*tks))
		tab->next = NULL;
}

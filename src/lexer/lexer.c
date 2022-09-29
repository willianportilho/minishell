/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 15:00:31 by ralves-b          #+#    #+#             */
/*   Updated: 2022/09/29 15:41:49 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static void	lst_tokenizer(t_tokens **tks)
{
	t_tokens	*aux;

	aux = *tks;
	while (aux)
	{
		aux->error = FALSE;
		if (aux->str[0] == S_QUOTE || aux->str[0] == D_QUOTE
			|| ft_strlen(aux->str) == 1)
			aux->token = aux->str[0];
		else if (aux->str[0] != I_REDIRECT && aux->str[0] != O_REDIRECT)
			aux->token = TEMP_VALUE;
		else if (ft_strlen(aux->str) > 2)
			aux->error = TRUE;
		else if (aux->str[0] == I_REDIRECT)
			aux->token = DELIMITER;
		else if (aux->str[0] == O_REDIRECT)
			aux->token = APP_O_REDIRECT;
		else
			aux->token = TEMP_VALUE;
		aux = aux->next;
	}
}

static void	fill_lst_content(t_tokens **tks, char **aux)
{
	int	i;

	i = 0;
	while (aux[i])
	{
		ft_str_swap_chr(&aux[i], TEMP_VALUE, SPACE);
		if (i == 0)
			*tks = ft_lstnew_t(aux[i]);
		else
			ft_lstadd_back_t(tks, ft_lstnew_t(aux[i]));
		i++;
	}
	ft_free_array(aux);
}

void	create_cmd_line_and_path(t_table *tab)
{
	int		i;

	if (!global()->control)
		return ;
	i = -1;
	clean_space(tab->cmd);
	ft_free_array(tab->cmd_line);
	tab->cmd_line = ft_split(tab->cmd, ' ');
	if (!(*tab->cmd_line))
		tab->cmd_line = ft_create_blank_array();
	ft_str_swap_chr(&tab->cmd, TEMP_VALUE, SPACE);
	ft_str_swap_chr(&tab->cmd, TEMP_SQUOT, S_QUOTE);
	while (tab->cmd_line[++i])
	{
		ft_str_swap_chr(&tab->cmd_line[i], TEMP_VALUE, SPACE);
		ft_str_swap_chr(&tab->cmd_line[i], TEMP_SHILD, SPACE);
		ft_str_swap_chr(&tab->cmd_line[i], TEMP_SQUOT, S_QUOTE);
		ft_str_swap_chr(&tab->cmd_line[i], I_REDIRECT_TEMP, I_REDIRECT);
		ft_str_swap_chr(&tab->cmd_line[i], O_REDIRECT_TEMP, O_REDIRECT);
	}
	i = -1;
	while (tab->path[++i])
		tab->path[i] = ft_strjoin_free(tab->path[i], tab->cmd_line[0]);
}

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

void	lexer(t_tokens **tks, char **str, t_table **tab)
{
	char	**tks_aux;
	t_table	*aux_tab;

	if (!ft_strlen(*str))
		return ;
	clean_space(*str);
	add_space(str);
	tks_aux = ft_split_free(*str, SPACE);
	fill_lst_content(tks, tks_aux);
	lst_tokenizer(tks);
	aux_tab = *tab;
	while (*tks)
	{
		get_path(aux_tab, 0);
		false_all(aux_tab);
		while (!aux_tab->pipe && (*tks))
			parser(tks, aux_tab);
		create_cmd_line_and_path(aux_tab);
		if (*tks)
		{
			aux_tab->next = malloc(sizeof(t_table));
			aux_tab = aux_tab->next;
			init_new_tab(aux_tab);
		}
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 15:00:31 by ralves-b          #+#    #+#             */
/*   Updated: 2022/09/19 21:09:23 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

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
}

void	easy_parsing(t_tokens **tks, t_table *tab)
{
	tab->pipe = FALSE;
	tab->cmd = ft_strdup("");
	if ((*tks)->token == I_REDIRECT)
	{
		tab->in_red = TRUE;
		(*tks) = (*tks)->next;
		tab->in_file = (*tks)->str;
		(*tks) = (*tks)->next;
	}
	if ((*tks)->token == O_REDIRECT)
	{
		tab->out_red = TRUE;
		(*tks) = (*tks)->next;
		tab->out_file = (*tks)->str;
		(*tks) = (*tks)->next;
	}
	while ((*tks) && (*tks)->token != PIPE)
	{
		tab->cmd = ft_strjoin_free(tab->cmd, (*tks)->str);
		tab->cmd = ft_strjoin_free(tab->cmd, " ");
		(*tks) = (*tks)->next;
	}
	clean_space(tab->cmd);
	tab->cmd_line = ft_split(tab->cmd, ' ');
	int i = -1;
	ft_str_swap_chr(&tab->cmd, TEMP_VALUE, SPACE);
	while (tab->cmd_line[++i])
		ft_str_swap_chr(&tab->cmd_line[i], TEMP_VALUE, SPACE);
	if ((*tks) && (*tks)->token == PIPE)
	{
		tab->pipe = TRUE;
		tab->next = malloc(sizeof(tab));
	}
	if ((*tks))
		(*tks) = (*tks)->next;
	else
		tab->next = NULL;
}

void	complete_path_with_command(t_table *tab)
{
	int		i;

	i = -1;
	while (tab->path[++i])
		tab->path[i] = ft_strjoin_free(tab->path[i], tab->cmd_line[0]);
}

void	lexer(t_tokens **tks, char **str, t_table **tab)
{
	char	**tks_aux;
	t_table	*aux_tab;

	if (!ft_strlen(*str))
		return ;
	clean_space(*str);
	add_space(str);
	tks_aux = ft_split(*str, SPACE);
	free(*str);
	fill_lst_content(tks, tks_aux);
	lst_tokenizer(tks);
	aux_tab = *tab;
	while (*tks)
	{
		easy_parsing(tks, aux_tab);
		complete_path_with_command(aux_tab);
		if (*tks)
		{
			aux_tab = aux_tab->next;
			get_path((*tab)->envp, &aux_tab, 0);
		}
	}

	//testes
	/*
	int i;
	int j;
	
	j = 0;
	while ((*tab))
	{
		j++;
		ft_printf("\n==== TABELA %d ====\n", j);
		ft_printf("infile = %s\n", (*tab)->in_file);
		ft_printf("infile_fd = %d\n", (*tab)->infile_fd);
		ft_printf("outfile = %s\n", (*tab)->out_file);
		ft_printf("outfile_fd = %d\n", (*tab)->outfile_fd);
		ft_printf("command = %s\n", (*tab)->cmd);
		i = -1;
		while ((*tab)->path[++i])
			ft_printf("path[%d] = %s\n", i, (*tab)->path[i]);
		i = -1;
		while ((*tab)->cmd_line[++i])
			ft_printf("cmd line[%d] = %s\n", i, (*tab)->cmd_line[i]);
		(*tab) = (*tab)->next;
	}
	*/
}

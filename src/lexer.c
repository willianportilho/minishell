/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 15:00:31 by ralves-b          #+#    #+#             */
/*   Updated: 2022/09/20 16:29:47 by ralves-b         ###   ########.fr       */
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
	ft_free_array(aux);
}

void	create_cmd_line_and_path(t_table *tab)
{
	int		i;

	i = -1;
	clean_space(tab->cmd);
	tab->cmd_line = ft_split(tab->cmd, ' ');
	ft_str_swap_chr(&tab->cmd, TEMP_VALUE, SPACE);
	while (tab->cmd_line[++i])
		ft_str_swap_chr(&tab->cmd_line[i], TEMP_VALUE, SPACE);
	i = -1;
	while (tab->path[++i])
		tab->path[i] = ft_strjoin_free(tab->path[i], tab->cmd_line[0]);
}

static void	TESTE_print_tab(t_table **tab)
{
	t_table	*aux;
	int contador_tabela = 0;
	int i = -1;
	aux = *tab;

	while (aux)
	{
		contador_tabela++;
		ft_printf("==== TABELA %d ====\n", contador_tabela);
		ft_printf("cmd = %s\n", aux->cmd);
		ft_printf("in_file = %s\n", aux->in_file);
		ft_printf("out_file = %s\n", aux->out_file);
		while (aux->path[++i])
			ft_printf("path[%d] = %s\n", i, aux->path[i]);
		i = -1;
		while (aux->cmd_line[++i])
			ft_printf("cmd_line[%d] = %s\n", i, aux->cmd_line[i]);
		aux = aux->next;
	}
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
		aux_tab->pipe = FALSE;
		aux_tab->cmd = ft_strdup("");
		while (!aux_tab->pipe && (*tks))
			parser(tks, aux_tab);
		create_cmd_line_and_path(aux_tab);
		if (*tks)
		{
			aux_tab = aux_tab->next;
			get_path((*tab)->envp, &aux_tab, 0);
		}
	}
	TESTE_print_tab(tab);
}

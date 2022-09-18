/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 15:00:31 by ralves-b          #+#    #+#             */
/*   Updated: 2022/09/18 19:39:40 by ralves-b         ###   ########.fr       */
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

void	easy_parsing(t_tokens *tks, t_table *tb)
{
	t_table	*aux;

	aux = tb;
	aux->cmd = ft_strdup("");
	if (tks->token == I_REDIRECT)
	{
		aux->in_red = TRUE;
		tks = tks->next;
		aux->in_file = tks->str;
		tks = tks->next;
	}
	if (tks->token == O_REDIRECT)
	{
		aux->out_red = TRUE;
		tks = tks->next;
		aux->out_file = tks->str;
		tks = tks->next;
	}
	while (tks->token != PIPE)
	{
		aux->cmd = ft_strjoin(aux->cmd, tks->str);
		aux->cmd = ft_strjoin(aux->cmd, " ");
		tks = tks->next;
	}
	if (tks->token == PIPE)
	{
		aux->next = malloc(sizeof(t_table));
		aux = aux->next;
		aux = NULL;
		tks = tks->next;
	}
}

void	lexer(t_tokens **tks, char **str)
{
	char	**tks_aux;

	g_table = malloc(sizeof(t_table));
	if (!ft_strlen(*str))
		return ;
	clean_space(*str);
	add_space(str);
	tks_aux = ft_split(*str, SPACE);
	free(*str);
	fill_lst_content(tks, tks_aux);
	lst_tokenizer(tks);
	easy_parsing(*tks, g_table);
	ft_printf("infile = %s\n", g_table->in_file);
	ft_printf("outfile = %s\n", g_table->out_file);
	ft_printf("command = %s\n", g_table->cmd);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 18:06:25 by ralves-b          #+#    #+#             */
/*   Updated: 2022/09/23 02:40:57 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

char	*simple_expander(char *variable)
{
	char	*expanded;
	int		i;

	i = 1;
	expanded = ft_strdup("");
	variable = ft_strjoin(variable, "=");
	while ((global()->envp[i] != NULL) != 0)
	{
		if (ft_strnstr(global()->envp[i], variable, ft_strlen(variable)))
		{
			expanded = ft_strdup(global()->envp[i] + ft_strlen(variable));
			break ;
		}
		i++;
	}
	return (expanded);
}

static void	deal_with_a_very_complicated_thing_that_i_dont_even_fully_understand_yet(char **str, char *s, int count)
{
	int		i;
	int		start; 
	char	*new_str;
	char	*temp;
	int		size;

	i = -1;
	start = 0;
	size = 0;
	new_str = ft_strdup("");
	while (s[++i] && count)
	{
		if (s[i] == DOLAR)
		{
			count--;
			start = i;
			new_str = ft_strjoin_free(new_str, ft_substr(s + size, 0, ft_strlen_til_chr(s + size, DOLAR)));
			i++;
			while (s[i] && s[i] != D_QUOTE && s[i] != SPACE && s[i] != DOLAR)
				i++;
			temp = ft_substr(s, start, i - start);
			temp = simple_expander(temp + 1);
			new_str = ft_strjoin_free(new_str, temp);
			size = i;
		}
		if (s[i] == DOLAR)
			i--;
	}
	if (s + i)
		new_str = ft_strjoin_free(new_str, s + i - 1);
	*str = ft_strjoin_free(*str, new_str);
}

static void	simple_trim(char **str, char c)
{
	char	*new_str;
	char	**temp;
	int		i;
	int		n_dolars;

	n_dolars = ft_count_c_in_str(*str, DOLAR);
	i = -1;
	temp = ft_split(*str, c);
	new_str = ft_strdup("");
	while (temp[++i])
	{
		if (!ft_strchr(temp[i], DOLAR) && c == D_QUOTE)
			new_str = ft_strjoin_free(new_str, temp[i]);
		else if (c == D_QUOTE)
			deal_with_a_very_complicated_thing_that_i_dont_even_fully_understand_yet(&new_str, temp[i], n_dolars);
		else
			new_str = ft_strjoin_free(new_str, temp[i]);
	}
	free(temp);
	free(*str);
	*str = new_str;
}

static void	expand_dolars(char **str)
{
	char	*new_str;

	new_str = simple_expander(*str + 1);
	free(*str);
	*str = new_str;
}

void	expand(t_tokens **t)
{
	if ((*t)->token == S_QUOTE)
	{
		simple_trim(&(*t)->str, S_QUOTE);
		ft_str_swap_chr(&(*t)->str, SPACE, TEMP_SHILD);
	}
	else if ((*t)->token == D_QUOTE)
		simple_trim(&(*t)->str, D_QUOTE);
	else
	{
		if (ft_strchr((*t)->str, DOLAR))
			expand_dolars(&(*t)->str);
		ft_str_swap_chr(&(*t)->str, SPACE, TEMP_SHILD);
	}
}

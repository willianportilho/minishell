/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 18:06:25 by ralves-b          #+#    #+#             */
/*   Updated: 2022/09/28 04:01:09 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

char	*expand_query(char *rest)
{
	char	*expanded;

	expanded = ft_strjoin(ft_itoa(global()->exit), rest);
	return (expanded);
}

char	*simple_expander(char *variable)
{
	char	*expanded;
	char	*rest;
	int		i;

	i = 1;
	expanded = ft_strdup("");
	if (*variable == QUERY)
	{
		rest = ft_strdup(variable + 1);
		return (expand_query(rest));
	}
	variable = ft_strjoin(variable, "=");
	while ((global()->envp[i] != NULL) != 0)
	{
		if (ft_strnstr(global()->envp[i], variable, ft_strlen(variable)))
		{
			free(expanded);
			expanded = ft_strdup(global()->envp[i] + ft_strlen(variable));
			break ;
		}
		i++;
	}
	free(variable);
	return (expanded);
}

static void	handle_dquote_dolars(char **str, char *s, int count, t_utils u)
{
	while (count && s[++u.i])
	{
		if (s[u.i] == DOLAR)
		{
			count--;
			u.start = u.i;
			u.str = ft_strjoin_free(u.str, ft_substr(s + u.size, 0, \
			ft_strlen_til_chr(s + u.size, DOLAR)));
			u.i++;
			while (s[u.i] && s[u.i] != D_QUOTE && s[u.i] != SPACE
				&& s[u.i] != DOLAR && s[u.i] != S_QUOTE)
				u.i++;
			u.tmp = ft_substr(s, u.start, u.i - u.start);
			u.aux = simple_expander(u.tmp + 1);
			free(u.tmp);
			u.str = ft_strjoin_free(u.str, u.aux);
			free(u.aux);
			u.size = u.i;
		}
		if (s[u.i] == DOLAR)
			u.i--;
	}
	if ((int)ft_strlen(s) > u.i)
		u.str = ft_strjoin_free(u.str, s + u.i);
	*str = ft_strjoin_free(*str, u.str);
}

static void	simple_trim(char **str, char c)
{
	char	*new_str;
	char	**temp;
	int		i;
	int		n_dolars;
	t_utils	utils;

	utils.size = 0;
	utils.i = -1;
	utils.str = ft_strdup("");
	n_dolars = ft_count_c_in_str(*str, DOLAR);
	i = -1;
	temp = ft_split(*str, c);
	new_str = ft_strdup("");
	while (temp[++i])
	{
		if (!ft_strchr(temp[i], DOLAR) && c == D_QUOTE)
			new_str = ft_strjoin_free(new_str, temp[i]);
		else if (c == D_QUOTE)
			handle_dquote_dolars(&new_str, temp[i], n_dolars, utils);
		else
			new_str = ft_strjoin_free(new_str, temp[i]);
	}
	ft_free_array(temp);
	free(*str);
	*str = new_str;
}

void	expand(t_tokens **t)
{
	char	*new_str;

	if ((*t)->token == S_QUOTE
		|| ft_c_first_than_in_str((*t)->str, S_QUOTE, D_QUOTE))
	{
		simple_trim(&(*t)->str, S_QUOTE);
		ft_str_swap_chr(&(*t)->str, SPACE, TEMP_SHILD);
	}
	else if ((*t)->token == D_QUOTE
		|| ft_c_first_than_in_str((*t)->str, D_QUOTE, S_QUOTE))
		simple_trim(&(*t)->str, D_QUOTE);
	else
	{
		if (ft_strchr((*t)->str, DOLAR))
		{
			new_str = simple_expander((*t)->str + 1);
			free((*t)->str);
			(*t)->str = new_str;
		}
		ft_str_swap_chr(&(*t)->str, SPACE, TEMP_SHILD);
	}
}

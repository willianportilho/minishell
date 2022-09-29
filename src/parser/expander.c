/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 18:06:25 by ralves-b          #+#    #+#             */
/*   Updated: 2022/09/29 16:54:35 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

char	*expand_query(char *rest)
{
	char	*expanded;

	expanded = ft_strjoin_double_free(ft_itoa(global()->exit), rest);
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
		return (free(expanded), free(variable), expand_query(rest));
	}
	variable = ft_strjoin_free(variable, "=");
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

static void	handle_dquote_dolars(char **str, char *s, int count, t_utils *u)
{
	while (count && s[++u->i])
	{
		if (s[u->i] == DOLAR)
		{
			count--;
			u->start = u->i;
			u->str = ft_strjoin_double_free(u->str, ft_substr(s + u->size, 0, \
			ft_strlen_til_chr(s + u->size, DOLAR)));
			u->i++;
			while (s[u->i] && s[u->i] != TEMP_DQUOT && s[u->i] != SPACE
				&& s[u->i] != DOLAR && s[u->i] != TEMP_SQUOT && s[u->i] != TEMP_VALUE)
				u->i++;
			u->tmp = ft_substr(s, u->start, u->i - u->start);
			u->aux = simple_expander(ft_strdup(u->tmp + 1));
			free(u->tmp);
			u->str = ft_strjoin_double_free(u->str, u->aux);
			u->size = u->i;
		}
		if (s[u->i] == DOLAR)
			u->i--;
	}
	if ((int)ft_strlen(s) > u->i)
		u->str = ft_strjoin_free(u->str, s + u->i);
	*str = ft_strjoin_free(*str, u->str);
}

static void	simple_trim(int i, char **str)
{
	char	*new_str;
	char	**temp;
	int		n_dolars;
	t_utils	utils;

	utils.size = 0;
	utils.i = -1;
	utils.str = ft_strdup("");
	n_dolars = ft_count_c_in_str(*str, DOLAR);
	temp = ft_split(*str, D_QUOTE);
	new_str = ft_strdup("");
	while (temp[++i])
	{
		if (ft_strchr(temp[i], DOLAR))
			handle_dquote_dolars(&new_str, temp[i], n_dolars, &utils);
		else
			new_str = ft_strjoin_free(new_str, temp[i]);
	}
	free(utils.str);
	ft_free_array(temp);
	free(*str);
	*str = new_str;
}

void	expand(t_tokens **t)
{
	int		i;

	i = -1;
	expand_2((*t)->str);
	simple_trim(i, &(*t)->str);
	ft_str_swap_chr(&(*t)->str, TEMP_DQUOT, D_QUOTE);
	ft_str_swap_chr(&(*t)->str, TEMP_DOLAR, DOLAR);
}

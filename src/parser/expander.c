/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 18:06:25 by ralves-b          #+#    #+#             */
/*   Updated: 2022/09/22 21:24:13 by ralves-b         ###   ########.fr       */
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

// Remove only the first and last charactere
static void	simple_trim(char **str)
{
	char	*new_str;

	new_str = ft_substr(*str, 1, (ft_strlen(*str) - 2));
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
		simple_trim(&(*t)->str);
		ft_str_swap_chr(&(*t)->str, SPACE, TEMP_SHILD);
	}
	if ((*t)->token == D_QUOTE)
	{
		if (!ft_strchr((*t)->str, DOLAR) && !ft_str_is_equal((*t)->str, "\""))
			simple_trim(&(*t)->str);
		else
		{
			free((*t)->str);
			(*t)->str = ft_strdup("");
			ft_lstfoward_free_t(t);
			(*t)->str = ft_substr((*t)->str, 0, ft_strlen((*t)->str) - 1);
			if (ft_strchr((*t)->str, DOLAR))
				expand_dolars(&(*t)->str);
		}
		ft_str_swap_chr(&(*t)->str, SPACE, TEMP_SHILD);
	}
	else
	{
		if (ft_strchr((*t)->str, DOLAR))
			expand_dolars(&(*t)->str);
		ft_str_swap_chr(&(*t)->str, SPACE, TEMP_SHILD);
	}
}

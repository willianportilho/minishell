/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_spaces.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 18:57:49 by ralves-b          #+#    #+#             */
/*   Updated: 2022/09/29 17:58:42 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/**
 * @brief Checar entrada triplicada
 */
static void	check_double(char **str, int *i, int type)
{
	int	index_beetween;

	index_beetween = 1;
	if (*i > 0)
	{
		if ((*str)[*i - index_beetween] != type)
		{
			*str = ft_str_insert_free(*str, SPACE, *i);
			index_beetween++;
		}
	}
	if ((*str)[*i + index_beetween] != type)
		*str = ft_str_insert_free(*str, SPACE, *i + index_beetween);
	else if (*i == 0)
		return ;
	*i = *i + 1;
}

void	add_space(char **str)
{
	int	i;
	int	quote_type;

	i = 0;
	while ((*str)[i])
	{
		if ((*str)[i] == D_QUOTE || (*str)[i] == S_QUOTE)
		{
			quote_type = (*str)[i];
			while ((*str)[i] && (*str)[i] != quote_type)
				i++;
		}
		if ((*str)[i] == PIPE)
		{
			*str = ft_str_insert_free(*str, SPACE, i);
			*str = ft_str_insert_free(*str, SPACE, i + 2);
			i += 2;
		}
		if ((*str)[i] == I_REDIRECT || (*str)[i] == O_REDIRECT)
			check_double(str, &i, (*str)[i]);
		i++;
	}
}

void	clean_space(char *str)
{
	size_t	i;
	int		value;

	i = 0;
	while (str[i])
	{
		while (str[i] != D_QUOTE && str[i] != S_QUOTE && str[i]
			&& str[i] != SPLIT_ME)
			i++;
		if (i == ft_strlen(str))
			return ;
		value = str[i];
		while (str[++i] != value)
		{
			if (str[i] == SPACE)
				str[i] = TEMP_VALUE;
			if (str[i] == I_REDIRECT)
				str[i] = I_REDIRECT_TEMP;
			if (str[i] == O_REDIRECT)
				str[i] = O_REDIRECT_TEMP;
			if (str[i] == PIPE)
				str[i] = TEMP_PIPE;
		}
		i++;
	}
}

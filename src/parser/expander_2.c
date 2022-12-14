/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 13:21:35 by ralves-b          #+#    #+#             */
/*   Updated: 2022/09/29 17:56:18 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	bring_temp_values_back(char **str)
{
	ft_str_swap_chr(str, TEMP_VALUE, SPACE);
	ft_str_swap_chr(str, TEMP_SHILD, SPACE);
	ft_str_swap_chr(str, TEMP_SQUOT, S_QUOTE);
	ft_str_swap_chr(str, I_REDIRECT_TEMP, I_REDIRECT);
	ft_str_swap_chr(str, O_REDIRECT_TEMP, O_REDIRECT);
	ft_str_swap_chr(str, TEMP_PIPE, PIPE);
	ft_str_swap_chr(str, TEMP_DOLAR, DOLAR);
}

void	protect_s_quotes(char *str, int *i)
{
	str[*i] = SPLIT_ME;
	*i += 1;
	while (str[*i] != S_QUOTE)
	{
		if (str[*i] == D_QUOTE)
			str[*i] = TEMP_DQUOT;
		else if (str[*i] == DOLAR)
			str[*i] = TEMP_DOLAR;
		*i += 1;
	}
	str[*i] = SPLIT_ME;
}

void	protect_d_quotes(char *str, int *i)
{
	*i += 1;
	while (str[*i] != D_QUOTE)
	{
		if (str[*i] == S_QUOTE)
			str[*i] = TEMP_SQUOT;
		else if (str[*i] == SPACE)
			str[*i] = TEMP_VALUE;
		else if (str[*i] == DOLAR)
		{
			if ((str[*i + 1] == SPACE || str[*i + 1] == D_QUOTE
					|| str[*i + 1] == DOLAR || !str[*i + 1]))
				str[*i] = TEMP_DOLAR;
		}
		*i += 1;
	}
}

void	expand_2(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == S_QUOTE)
		{
			protect_s_quotes(str, &i);
		}
		if (str[i] == D_QUOTE)
		{
			protect_d_quotes(str, &i);
		}
		i++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 13:21:35 by ralves-b          #+#    #+#             */
/*   Updated: 2022/09/29 15:06:33 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"
#include <stdio.h>

void	protect_s_quotes(char *str, int *i)
{
	*i += 1;
	while (str[*i] != S_QUOTE)
	{
		if (str[*i] == D_QUOTE)
			str[*i] = TEMP_DQUOT;
		else if (str[*i] == DOLAR)
			str[*i] = TEMP_DOLAR;
		*i += 1;
	}
}

void	protect_d_quotes(char *str, int *i)
{
	*i += 1;
	while (str[*i] != D_QUOTE)
	{
		if (str[*i] == S_QUOTE)
			str[*i] = TEMP_SQUOT;
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

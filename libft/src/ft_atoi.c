/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 00:10:24 by wportilh          #+#    #+#             */
/*   Updated: 2022/09/12 18:29:41 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

static	int	convert_atoi(char *str)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	while ((str[i] != '\0') && ((str[i] >= 48) && (str[i] <= 57)))
	{
		result = (result * 10) + (str[i] - 48);
		i++;
	}
	return (result);
}

int	ft_atoi(const char *nptr)
{
	int	result;
	int	signal;
	int	i;

	signal = 1;
	i = 0;
	while ((nptr[i] == ' ') || (nptr[i] == '\t') || (nptr[i] == '\n')
		|| (nptr[i] == '\r') || (nptr[i] == '\v') || (nptr[i] == '\f'))
	{
		i++;
	}
	if ((nptr[i] == '-') || (nptr[i] == '+'))
	{
		if (nptr[i] == '-')
		{
			signal = -1;
		}
		i++;
	}
	nptr = nptr + i;
	result = convert_atoi((char *)nptr);
	result = result * signal;
	return (result);
}

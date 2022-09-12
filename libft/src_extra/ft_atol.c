/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 00:10:24 by wportilh          #+#    #+#             */
/*   Updated: 2022/09/12 18:29:35 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

long	ft_atol(const char *nptr)
{
	long	result;
	int		signal;
	int		i;

	signal = 1;
	i = 0;
	while ((nptr[i] == ' ') || (nptr[i] == '\t') || (nptr[i] == '\n')
		|| (nptr[i] == '\r') || (nptr[i] == '\v') || (nptr[i] == '\f'))
		i++;
	if ((nptr[i] == '-') || (nptr[i] == '+'))
	{
		if (nptr[i] == '-')
			signal = -1;
		i++;
	}
	nptr = nptr + i;
	i = 0;
	result = 0;
	while ((nptr[i] != '\0') && ((nptr[i] >= 48) && (nptr[i] <= 57)))
	{
		result = (result * 10) + (nptr[i] - 48);
		i++;
	}
	result = result * signal;
	return (result);
}

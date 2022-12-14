/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtoupper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 17:56:20 by ralves-b          #+#    #+#             */
/*   Updated: 2022/09/12 21:01:07 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

char	*ft_strtoupper(char *s)
{
	int	index;

	index = 0;
	while (s[index])
	{
		if (ft_isalpha(s[index]))
			s[index] = ft_toupper(s[index]);
		index++;
	}
	return (s);
}

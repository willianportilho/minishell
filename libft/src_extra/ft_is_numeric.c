/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_numeric.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 19:42:07 by ralves-b          #+#    #+#             */
/*   Updated: 2022/09/29 19:51:09 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

int	ft_is_numeric(char *string)
{
	int	i;

	i = 0;
	while (string[++i])
	{
		if (!ft_isdigit(string[i]) && string[0] != '-' && string[0] != '+')
			return (0);
	}
	return (1);
}

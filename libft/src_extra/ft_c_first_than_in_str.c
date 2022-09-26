/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_c_first_than_in_str.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 15:27:41 by ralves-b          #+#    #+#             */
/*   Updated: 2022/09/26 15:55:08 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

int	ft_c_first_than_in_str(char *str, char c_1, char c_2)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c_1)
			return (1);
		else if (str[i] == c_2)
			return (0);
		i++;
	}
	return (0);
}

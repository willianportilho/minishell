/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_c_in_str.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 23:45:35 by ralves-b          #+#    #+#             */
/*   Updated: 2022/09/22 23:47:54 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

int	ft_count_c_in_str(char *str, char chr)
{
	int	counter;
	int	i;
	
	counter = 0;
	i = -1;
	if (!str)
		return (-1);
	while (str[++i])
	{
		if (str[i] == chr)
			counter++;
	}
	return (counter);
}

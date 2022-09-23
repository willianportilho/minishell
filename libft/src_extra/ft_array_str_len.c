/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_str_len.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 16:50:09 by ralves-b          #+#    #+#             */
/*   Updated: 2022/09/23 16:50:15 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

int	ft_array_str_len(char **array)
{
	int	i;
	int	len;

	if (!(**array))
		return (-1);
	i = -1;
	len = 0;
	while (array[++i])
		len++;
	return (len);
}

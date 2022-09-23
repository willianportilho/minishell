/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_str_len.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 17:01:14 by wportilh          #+#    #+#             */
/*   Updated: 2022/09/23 04:11:55 by wportilh         ###   ########.fr       */
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

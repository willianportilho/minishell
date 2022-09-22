/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_str_len.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 17:01:14 by wportilh          #+#    #+#             */
/*   Updated: 2022/09/22 17:01:36 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	ft_array_str_len(char **array)
{
	int	i;
	int	len;

	i = -1;
	len = 0;
	while (array[++i])
		len++;
	return (len);
}

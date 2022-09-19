/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_int_array.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 21:50:24 by wportilh          #+#    #+#             */
/*   Updated: 2022/09/19 22:48:41 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

void	ft_free_int_array(int ***array)
{
	int	i;

	i = 0;
	if (*array)
	{
		while ((*array)[i])
			free((*array)[i++]);
		free(*array);
	}
}

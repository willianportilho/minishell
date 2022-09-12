/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pre_x_lower.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 00:16:16 by wportilh          #+#    #+#             */
/*   Updated: 2022/09/12 18:30:55 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

void	ft_pre_x_lower(unsigned int n, int *i, int *len)
{
	unsigned int	cp;

	cp = n;
	*len = *len + 1;
	if (cp > 15)
	{
		while (cp > 15)
		{
			cp = cp / 16;
			*len = *len + 1;
		}
	}
	*i = *i + 2;
	ft_print_x_lower(n);
}

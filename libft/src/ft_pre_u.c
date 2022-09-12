/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pre_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 00:04:13 by wportilh          #+#    #+#             */
/*   Updated: 2022/09/12 18:30:52 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

void	ft_pre_u(unsigned int n, int *i, int *len)
{
	unsigned int	cp;

	cp = n;
	*len = *len + 1;
	while (cp > 9)
	{
		cp = cp / 10;
		*len = *len + 1;
	}
	*i = *i + 2;
	ft_print_u(n);
}

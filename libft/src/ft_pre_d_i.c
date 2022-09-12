/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pre_d_i.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 23:01:53 by wportilh          #+#    #+#             */
/*   Updated: 2022/09/12 18:30:45 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

void	ft_pre_d_i(int n, int *i, int *len)
{
	int	cp;

	cp = n;
	if (cp < 0)
		*len = *len + 1;
	*len = *len + 1;
	while ((cp > 9) || (cp < -9))
	{
		cp = cp / 10;
		*len = *len + 1;
	}
	*i = *i + 2;
	ft_print_d_i(n);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 21:45:47 by wportilh          #+#    #+#             */
/*   Updated: 2022/09/12 18:31:09 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

static void	ft_put_u_n(int n)
{
	n = n + '0';
	write(1, &n, 1);
}

void	ft_print_u(unsigned int n)
{
	if (n < 10)
		ft_put_u_n(n);
	if (n > 9)
	{
		ft_print_u(n / 10);
		ft_put_u_n(n % 10);
	}
}

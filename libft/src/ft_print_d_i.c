/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d_i.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 21:42:45 by wportilh          #+#    #+#             */
/*   Updated: 2022/09/12 18:31:03 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

static void	ft_put_n(int n)
{
	n = n + '0';
	write(1, &n, 1);
}

void	ft_print_d_i(int n)
{
	if (n == -2147483648)
	{
		ft_print_s("-2147483648");
		return ;
	}
	if (n < 0)
	{
		ft_print_c('-');
		n = n * -1;
	}
	if (n < 10)
		ft_put_n(n);
	if (n > 9)
	{
		ft_print_d_i(n / 10);
		ft_put_n(n % 10);
	}
}

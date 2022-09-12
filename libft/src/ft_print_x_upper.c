/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x_upper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 21:48:53 by wportilh          #+#    #+#             */
/*   Updated: 2022/09/12 18:31:14 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

static int	len_x_upper(unsigned int cp)
{
	int	size_memb;

	size_memb = 1;
	if (cp > 15)
	{
		while (cp > 15)
		{
			cp = cp / 16;
			size_memb++;
		}
	}
	return (size_memb);
}

void	ft_print_x_upper(unsigned int n)
{
	int		size_memb;
	char	*str;

	size_memb = len_x_upper(n);
	str = malloc(size_memb * sizeof(char) + 1);
	str[size_memb] = '\0';
	while (n > 15)
	{
		if ((n % 16) > 9)
			str[--size_memb] = (n % 16) + 55;
		else
			str[--size_memb] = (n % 16) + 48;
		n = n / 16;
	}
	if (n > 9)
		str[--size_memb] = n + 55;
	else
		str[--size_memb] = n + 48;
	ft_print_s(str);
	free (str);
}

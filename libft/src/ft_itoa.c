/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 22:24:23 by wportilh          #+#    #+#             */
/*   Updated: 2022/09/12 18:30:00 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

static void	put_value(char *str, int index, int n)
{
	int	index2;

	index2 = index;
	if (n == 0)
		str[0] = 0 + 48;
	if (n < 0)
	{
		if (n == -2147483648)
		{
			n = (n / 10);
			str[(index - 1)] = 8 + 48;
			index--;
		}
		str[0] = '-';
		n = n * -1;
	}
	str[index2] = '\0';
	index--;
	while (n != 0)
	{
		str[index] = (n % 10) + 48;
		n = n / 10;
		index--;
	}
}

char	*ft_itoa(int n)
{
	char	*str;
	int		index;
	int		cp_n;

	index = 1;
	cp_n = n;
	while ((cp_n / 10) != 0)
	{
		cp_n = cp_n / 10;
		index++;
	}
	if (n < 0)
		index++;
	str = (char *)malloc((index + 1) * sizeof(char));
	if (!str)
		return (NULL);
	put_value(str, index, n);
	return (str);
}

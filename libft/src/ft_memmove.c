/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 23:01:23 by wportilh          #+#    #+#             */
/*   Updated: 2022/09/12 18:30:37 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*ptr;
	char	*ptr2;

	i = 0;
	ptr = (char *)src;
	ptr2 = (char *)dest;
	if (ptr < ptr2)
	{
		while (n > 0)
		{
			ptr2[n - 1] = ptr[n - 1];
			n--;
		}
	}
	else
	{
		while (i < n)
		{
			ptr2[i] = ptr[i];
			i++;
		}
	}
	return (dest);
}

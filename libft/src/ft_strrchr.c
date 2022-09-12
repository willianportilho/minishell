/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 04:25:40 by wportilh          #+#    #+#             */
/*   Updated: 2022/09/12 18:31:56 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	int		j;
	char	*ptr;

	i = 0;
	j = 0;
	ptr = (char *)s;
	while (ptr[i] != '\0')
	{
		i++;
	}
	while (i >= j)
	{
		if ((unsigned char)ptr[i] == (unsigned char)c)
		{
			ptr = (ptr + i);
			return (ptr);
		}
		i--;
	}
	return (NULL);
}

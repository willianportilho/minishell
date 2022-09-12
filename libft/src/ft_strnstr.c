/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 17:11:13 by wportilh          #+#    #+#             */
/*   Updated: 2022/09/12 18:31:54 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	i;
	size_t	i2;
	size_t	i3;

	i = 0;
	i2 = 0;
	i3 = 0;
	if (ft_strlen((char *)s2) == 0)
		return ((char *)s1);
	while ((s1[i]) && (i < len))
	{
		i3 = i;
		while ((s1[i3] == s2[i2]) && (i3 < len))
		{
			i3++;
			i2++;
		}
		if (s2[i2] == '\0')
		{
			return ((char *)s1 + i);
		}
		i++;
		i2 = 0;
	}
	return (NULL);
}

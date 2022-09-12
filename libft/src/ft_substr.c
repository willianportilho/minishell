/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 20:02:59 by wportilh          #+#    #+#             */
/*   Updated: 2022/09/12 18:32:00 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	len_s;
	char	*ptr;

	i = 0;
	len_s = ft_strlen((char *)s);
	if ((len_s - start) < len)
	{
		len = (ft_strlen((char *)s) - start);
	}
	if (start > len_s)
	{
		len = 0;
	}
	ptr = (char *)malloc(len + 1);
	if (!ptr)
		return (NULL);
	while ((i < len) && (s[start != '\0']))
	{
		ptr[i] = s[start];
		i++;
		start++;
	}
	ptr[i] = '\0';
	return (ptr);
}

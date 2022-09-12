/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 04:48:52 by wportilh          #+#    #+#             */
/*   Updated: 2022/09/12 18:31:52 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*ptr_s1;
	unsigned char	*ptr_s2;

	i = 0;
	ptr_s1 = (unsigned char *)s1;
	ptr_s2 = (unsigned char *)s2;
	while (((ptr_s1[i] || ptr_s2[i]) != '\0') && i < n)
	{
		if ((ptr_s1[i] - ptr_s2[i]) < 0)
		{
			return (ptr_s1[i] - ptr_s2[i]);
		}
		else if ((ptr_s1[i] - ptr_s2[i]) > 0)
		{
			return (ptr_s1[i] - ptr_s2[i]);
		}
		i++;
	}
	return (0);
}

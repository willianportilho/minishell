/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 18:29:39 by wportilh          #+#    #+#             */
/*   Updated: 2022/09/12 18:31:58 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

static	int	ft_strcmp_alt(const char s1, const char *s2)
{
	int	i;

	i = 0;
	if ((s1 - s2[i]) == 0)
		return (0);
	while (s2[i])
	{
		if ((s1 - s2[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

static int	size_malloc(char const *s1, char const *set, int len, int invert)
{
	int	i;
	int	result;

	i = 0;
	while (s1[i])
	{
		result = ft_strcmp_alt(s1[i], set);
		if (result == 0)
			len--;
		else
		{
			while (s1[invert] > 0)
			{
				result = ft_strcmp_alt(s1[invert], set);
				if (result == 0)
					len--;
				else
					return (len);
				invert--;
			}
		}
		i++;
	}
	return (len);
}

static char	*put_value(char const *s1, char const *set, char *ptr, int len)
{
	int		j;
	int		i;
	int		result;

	j = 0;
	i = 0;
	while (s1[j])
	{
		result = ft_strcmp_alt(s1[j], set);
		if (result != 0)
		{
			while (len > 0)
			{
				ptr[i] = s1[j];
				i++;
				j++;
				len--;
			}
			ptr[i] = '\0';
			return (ptr);
		}
		j++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		invert;
	int		len_s1;
	int		len_malloc;
	char	*ptr;

	len_s1 = 0;
	while (s1[len_s1])
		len_s1++;
	invert = len_s1 - 1;
	len_malloc = size_malloc(s1, set, len_s1, invert);
	ptr = malloc(len_malloc + 1);
	if (!ptr)
		return (NULL);
	put_value(s1, set, ptr, len_malloc);
	return (ptr);
}

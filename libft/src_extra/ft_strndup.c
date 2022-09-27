/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 04:26:29 by wportilh          #+#    #+#             */
/*   Updated: 2022/09/24 04:26:32 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

char	*ft_strndup(const char *s, int size)
{
	int		i;
	char	*new_str;

	i = 0;
	if (s == NULL)
		return (NULL);
	else if (size < 1)
	{
		new_str = (char *)malloc((i + 1));
		new_str[i] = '\0';
		return (new_str);
	}
	while ((s[i]) && (i < size))
		i++;
	new_str = (char *)malloc((i + 1));
	if (!new_str)
		return (NULL);
	i = -1;
	while ((s[++i]) && (i < size))
		new_str[i] = s[i];
	new_str[i] = '\0';
	return (new_str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 22:07:01 by wportilh          #+#    #+#             */
/*   Updated: 2022/09/12 18:32:09 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

int	check_break(char *actual)
{
	int	i;

	i = 0;
	while (actual[i])
	{
		if (actual[i] == '\n')
			return (0);
		i++;
	}
	return (1);
}

char	*ft_strjoin_alt(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*ptr;

	i = 0;
	j = 0;
	if (s1 != NULL)
		i = ft_strlen(s1);
	ptr = (char *)malloc(i + ft_strlen(s2) + 1);
	if (!ptr)
		return (NULL);
	i = 0;
	if (s1 != NULL)
	{
		while (s1[i])
		{
			ptr[i] = s1[i];
			i++;
		}
	}
	while (s2[j])
		ptr[i++] = s2[j++];
	ptr[i] = '\0';
	free (s1);
	return (ptr);
}

char	*cut_act(char *actual)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	j = 0;
	if (check_break(actual) == 0)
	{
		while (actual[i] != '\n')
			i++;
		if (!(actual[i + 1] == '\0'))
		{
			temp = (char *)malloc(ft_strlen(actual) - i);
			if (!temp)
				return (NULL);
			i++;
			while (actual[i])
				temp[j++] = actual[i++];
			temp[j] = '\0';
			free (actual);
			return (temp);
		}
	}
	free (actual);
	return (NULL);
}

char	*line_to_send(char *actual)
{
	int		i;
	char	*line;

	i = -1;
	if (check_break(actual) == 0)
	{
		while (actual[i + 1] != '\n')
			i++;
		line = (char *)malloc(++i + 2);
		if (!line)
			return (NULL);
		i = -1;
		while (actual[++i] != '\n')
			line[i] = actual[i];
		line[i] = '\n';
		line[i + 1] = '\0';
		return (line);
	}
	line = (char *)malloc(ft_strlen(actual) + 1);
	if (!line)
		return (NULL);
	while (actual[++i])
		line[i] = actual[i];
	line[i] = '\0';
	return (line);
}

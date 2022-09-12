/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 20:13:58 by wportilh          #+#    #+#             */
/*   Updated: 2022/09/12 18:32:10 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

static char	*new_line(int *acess, char **actual, char **line, char **buffer)
{
	if (!(acess[1] > 0))
	{
		if (*actual)
		{
			*line = line_to_send(*actual);
			*actual = cut_act(*actual);
		}
		free (*buffer);
		return (*line);
	}
	(*buffer)[acess[1]] = '\0';
	*actual = ft_strjoin_alt(*actual, *buffer);
	while ((check_break(*buffer) == 1) && (acess[1] > 0))
	{
		free (*buffer);
		*buffer = malloc(BUFFER_SIZE + 1);
		acess[1] = read(acess[0], *buffer, BUFFER_SIZE);
		(*buffer)[acess[1]] = '\0';
		if (acess[1] > 0)
			*actual = ft_strjoin_alt(*actual, *buffer);
	}
	free (*buffer);
	*line = line_to_send(*actual);
	*actual = cut_act(*actual);
	return (*line);
}

char	*get_next_line(int fd)
{
	int			acess[2];
	char		*buffer;
	char		*line;
	static char	*actual = NULL;

	if ((BUFFER_SIZE < 1) || (fd < 0) || (fd > 1024))
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
	{
		free (buffer);
		return (NULL);
	}
	acess[0] = fd;
	acess[1] = read(fd, buffer, BUFFER_SIZE);
	line = NULL;
	return (new_line(acess, &actual, &line, &buffer));
}

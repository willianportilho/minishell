/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_free.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 22:08:21 by ralves-b          #+#    #+#             */
/*   Updated: 2022/09/20 13:12:52 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

static void	put_value(char const *s, char c, char **matrix)
{
	int	i2;
	int	i3;

	i2 = 0;
	i3 = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		while ((*s != c) && (*s))
		{
			matrix[i2][i3] = *s;
			s++;
			i3++;
			if ((*s == c) || (*s == '\0'))
				matrix[i2][i3] = '\0';
		}
		i2++;
		i3 = 0;
	}
}

static int	malloc_col(char const *s, char c, char **matrix)
{
	int	n_col;

	n_col = 0;
	while (*s)
	{
		while ((*s != c) && (*s))
		{
			n_col++;
			s++;
		}
		if (n_col > 0)
		{
			*matrix = (char *)malloc((n_col + 1) * sizeof(char));
			if (!*matrix)
				return (0);
			matrix++;
		}
		n_col = 0;
		s++;
		if (*(s - 1) == '\0')
			s--;
	}
	*matrix = NULL;
	return (1);
}

static int	count_lines(char const *s, char c)
{
	int	n_lines;

	n_lines = 0;
	while (*s)
	{
		if ((*s != c) && (*s != '\0'))
		{
			n_lines++;
			while ((*s != c) && (*s))
				s++;
			if (*s == '\0')
				s--;
		}
		s++;
	}
	return (n_lines);
}

char	**ft_split_free(char *s, char c)
{
	int		n_lines;
	int		check_malloc;
	char	**matrix;

	n_lines = count_lines(s, c);
	matrix = (char **)malloc((n_lines + 1) * sizeof(char *));
	if (!matrix)
		return (NULL);
	check_malloc = malloc_col(s, c, matrix);
	if (check_malloc == 1)
		put_value(s, c, matrix);
	else
		return (NULL);
	free(s);
	return (matrix);
}

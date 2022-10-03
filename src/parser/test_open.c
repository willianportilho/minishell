/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_open.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 12:44:27 by ralves-b          #+#    #+#             */
/*   Updated: 2022/10/03 20:09:13 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static void	open_in(int fd, char **file, t_table **tab)
{
	(*tab)->in_red = TRUE;
	free((*tab)->in_file);
	(*tab)->in_file = *file;
	fd = open(*file, O_RDONLY);
	if (fd == -1)
		(*tab)->error = TRUE;
	else
		close(fd);
}

static void	open_out(int fd, char **file, t_table **tab)
{
	(*tab)->out_red = TRUE;
	free((*tab)->out_file);
	(*tab)->out_file = *file;
	fd = open((*tab)->out_file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
		(*tab)->error = TRUE;
	else
		close(fd);
}

static void	open_app(int fd, char **file, t_table **tab)
{
	(*tab)->out_append = TRUE;
	free((*tab)->out_file);
	(*tab)->out_file = *file;
	fd = open((*tab)->out_file, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (fd == -1)
		(*tab)->error = TRUE;
	else
		close(fd);
}

void	teste_open(int red, char **file, t_table **tab)
{
	int	fd;

	fd = -5;
	if ((*tab)->error)
		free(*file);
	else if (red == I_REDIRECT && !(*tab)->error)
	{
		open_in(fd, file, tab);
	}
	else if (red == O_REDIRECT && !(*tab)->error)
	{
		open_out(fd, file, tab);
	}
	else if (red == APP_O_REDIRECT && !(*tab)->error)
	{
		open_app(fd, file, tab);
	}
}

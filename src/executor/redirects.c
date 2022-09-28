/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirects.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 22:34:38 by wportilh          #+#    #+#             */
/*   Updated: 2022/09/28 20:09:36 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	check_infile(t_table **tab, t_exec *exec)
{
	if ((*tab)->in_red)
	{
		dup2((*tab)->infile_fd, STDIN_FILENO);
		close((*tab)->infile_fd);
		check_heredoc();
		if (((*tab)->out_red != TRUE) && (exec->amount_cmd > 1))
			dup2(exec->pipes[exec->i][1], STDOUT_FILENO);
		if ((*tab)->infile_fd == -1)
		{
			clean_alloc(exec);
			exit (EXIT_FAILURE);
		}
	}
}

void	check_outfile(t_table **tab, t_exec *exec)
{
	if ((*tab)->out_red || (*tab)->out_append)
	{
		if ((*tab)->outfile_fd == -1)
		{
			clean_alloc(exec);
			exit(EXIT_FAILURE);
		}
		if (((*tab)->in_red != TRUE) && (exec->amount_cmd > 1))
			dup2(exec->pipes[exec->i - 1][0], STDIN_FILENO);
		dup2((*tab)->outfile_fd, STDOUT_FILENO);
		close((*tab)->outfile_fd);
	}
}

void	initialize_files(t_table **tab)
{
	if ((*tab)->in_red)
	{
		(*tab)->infile_fd = open((*tab)->in_file, O_RDONLY);
		if ((*tab)->infile_fd == -1)
			perror_message((*tab)->in_file);
	}
	if ((*tab)->out_red)
	{
		(*tab)->outfile_fd = open((*tab)->out_file, \
		O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if ((*tab)->outfile_fd == -1)
			perror_message((*tab)->out_file);
	}
	if ((*tab)->out_append)
	{
		(*tab)->outfile_fd = open((*tab)->out_file, \
		O_WRONLY | O_CREAT | O_APPEND, 0644);
		if ((*tab)->outfile_fd == -1)
			perror_message((*tab)->out_file);
	}
}

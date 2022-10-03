/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirects.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 22:34:38 by wportilh          #+#    #+#             */
/*   Updated: 2022/10/03 15:31:05 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	check_infile(t_table **tab, t_exec *exec)
{
	if ((*tab)->in_red)
	{
		if ((*tab)->infile_fd != -1)
		{
			dup2((*tab)->infile_fd, STDIN_FILENO);
			close((*tab)->infile_fd);
		}
		check_heredoc();
		if (((*tab)->out_red != TRUE) && (exec->amount_cmd > 1))
			dup2(exec->pipes[exec->i][1], STDOUT_FILENO);
		if ((*tab)->infile_fd == -1)
		{
			global()->exit = 1;
			if ((exec->amount_cmd > 1) || (!built_in_cmd((*tab)->cmd_line[0])))
			{
				clean_alloc(exec);
				exit (global()->exit);
			}
		}
	}
}

void	check_outfile(t_table **tab, t_exec *exec)
{
	if ((*tab)->out_red || (*tab)->out_append)
	{
		if ((*tab)->outfile_fd == -1)
		{
			global()->exit = 1;
			if ((exec->amount_cmd > 1) || (!built_in_cmd((*tab)->cmd_line[0])))
			{
				clean_alloc(exec);
				exit (global()->exit);
			}
		}
		if (((*tab)->in_red != TRUE) && (exec->amount_cmd > 1) && exec->i)
			dup2(exec->pipes[exec->i - 1][0], STDIN_FILENO);
		if ((*tab)->outfile_fd != -1)
		{
			dup2((*tab)->outfile_fd, STDOUT_FILENO);
			close((*tab)->outfile_fd);
		}
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

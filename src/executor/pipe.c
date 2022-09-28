/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 22:32:30 by wportilh          #+#    #+#             */
/*   Updated: 2022/09/28 19:28:08 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	alloc_resources(t_exec *exec)
{
	exec->i = -1;
	exec->ind = -1;
	exec->pipes = malloc((exec->amount_cmd + 1) * sizeof(int *));
	if (!exec->pipes)
	{
		perror_message("malloc");
		exec->pipes = NULL;
	}
	while (++exec->ind < exec->amount_cmd)
	{
		exec->pipes[exec->ind] = malloc((exec->amount_cmd + 1) * sizeof(int));
		if (!exec->pipes[exec->ind])
		{
			perror_message("malloc");
			exec->pipes[exec->ind] = NULL;
		}
	}
	exec->pipes[exec->amount_cmd] = NULL;
	exec->pid = malloc((exec->amount_cmd + 1) * sizeof(int));
	if (!exec->pid)
	{
		perror_message("malloc");
		exec->pid = NULL;
	}
}

void	close_pipes(t_exec *exec)
{
	int	i;

	i = -1;
	while (++i < exec->amount_cmd - 1)
	{
		if (close(exec->pipes[i][0]))
			perror_message("close");
		if (close(exec->pipes[i][1]))
			perror_message("close");
	}
}

void	wait_processes(t_exec *exec)
{
	int	i;
	int	wstatus;

	i = -1;
	while (++i < exec->amount_cmd)
	{
		if (waitpid(exec->pid[i], &wstatus, 0) == -1)
			perror_message("waitpid");
		if (WIFEXITED(wstatus))
			global()->exit = WEXITSTATUS(wstatus);
	}
}

void	initialize_pipes(t_exec *exec)
{
	int	i;

	i = -1;
	while (++i < exec->amount_cmd)
	{
		if (pipe(exec->pipes[i]) == -1)
			perror_message("pipe");
	}
}

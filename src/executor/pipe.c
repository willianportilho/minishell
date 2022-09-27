/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 22:32:30 by wportilh          #+#    #+#             */
/*   Updated: 2022/09/27 13:12:47 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	alloc_resources(t_exec *exec)
{
	int	i;

	i = -1;
	exec->i = -1;
	exec->pipes = malloc((exec->amount_cmd + 1) * sizeof(int *));
	while (++i < exec->amount_cmd)
		exec->pipes[i] = malloc((\
		exec->amount_cmd + 1) * sizeof(int));
	exec->pid = malloc((exec->amount_cmd + 1) * sizeof(int));
	exec->pipes[exec->amount_cmd] = NULL;
}

void	close_pipes(t_exec *exec)
{
	int	i;

	i = -1;
	while (++i < exec->amount_cmd - 1)
	{
		close(exec->pipes[i][0]);
		close(exec->pipes[i][1]);
	}
}

void	wait_processes(t_exec *exec)
{
	int	i;
	int	wstatus;

	i = -1;
	while (++i < exec->amount_cmd)
	{
		waitpid(exec->pid[i], &wstatus, 0);
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
			ft_printf("pipe: colocar erro depois e limpar memória\n");
	}
}

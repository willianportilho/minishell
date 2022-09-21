/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 18:47:12 by wportilh          #+#    #+#             */
/*   Updated: 2022/09/22 01:25:02 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static void	validate_path(t_table **tab, t_exec *exec)
{
	exec->pos = -1;
	exec->check = TRUE;
	while ((*tab)->path[++exec->pos])
	{
		if (access((*tab)->path[exec->pos], F_OK) == 0)
			return ;
	}
	if (access((*tab)->cmd_line[0], F_OK) == 0)
	{
		exec->check = FALSE;
		return ;
	}
	exec->pos = -1;
}

static int	execute(t_table **tab, t_exec *exec)
{
	validate_path(tab, exec);
	if (exec->pos == -1)
	{
		ft_putstr_fd("Comando não encontrado\n", 2);
		clean_alloc(exec);
		exit(127);
	}
	if (exec->check == TRUE)
	{
		if (execve((*tab)->path[exec->pos], \
		(*tab)->cmd_line, (*tab)->envp) == -1)
			perror("exec: exec:");
	}
	else
	{
		if (execve((*tab)->cmd_line[0], (*tab)->cmd_line, (*tab)->envp) == -1)
			perror("exec: exec:");
	}
	clean_alloc(exec);
	exit(EXIT_FAILURE);
}

static void	child(t_table **tab, t_exec *exec)
{
	if ((exec->i < exec->amount_cmd - 1) && (exec->i != 0))
	{
		dup2(exec->pipes[exec->i - 1][0], STDIN_FILENO);
		dup2(exec->pipes[exec->i][1], STDOUT_FILENO);
	}
	check_infile(tab, exec);
	check_outfile(tab, exec);
	close_pipes(exec);
	execute(tab, exec);
}

static void	initialize_childs(t_table **tab, t_exec *exec)
{
	exec->i = -1;
	while (++exec->i < exec->amount_cmd)
	{
		exec->pid[exec->i] = fork();
		if (exec->pid[exec->i] == -1)
			ft_printf("fork: colocar erro depois e limpar memória\n");
		if (exec->pid[exec->i] == 0)
			child(tab, exec);
	}
}

void	executor(t_table **tab)
{
	t_exec	exec;

	exec.exit = 0;
	exec.amount_cmd = 1;
	initialize_files(tab);
	alloc_resources(&exec);
	initialize_pipes(&exec);
	initialize_childs(tab, &exec);
	close_pipes(&exec);
	wait_processes(&exec);
	clean_alloc(&exec);
	if ((*tab)->next)
	{
		*tab = (*tab)->next;
		executor(tab);
	}
}

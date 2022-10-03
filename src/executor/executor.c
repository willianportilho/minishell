/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 18:47:12 by wportilh          #+#    #+#             */
/*   Updated: 2022/10/03 18:58:45 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static void	validate_path(t_table **tab, t_exec *exec)
{
	struct stat	sb;

	if (!stat((*tab)->cmd_line[0], &sb) && ((sb.st_mode & S_IFMT) == S_IFDIR)
		&& ft_strchr((*tab)->cmd_line[0], '/'))
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd((*tab)->cmd_line[0], 2);
		ft_putstr_fd(": Is a directory\n", 2);
		exec->pos = -1;
		return ;
	}
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
	int	*p;

	p = &global()->exit;
	validate_path(tab, exec);
	if (exec->pos == -1)
	{
		cmd_error(tab, exec);
		rl_clear_history();
		exit(clean_exit(ft_strdup("cavalinho")));
	}
	if (exec->check == TRUE)
	{
		*p = execve((*tab)->path[exec->pos], \
		(*tab)->cmd_line, global()->envp);
		perror_message((*tab)->cmd_line[1]);
	}
	else
	{
		*p = (execve((*tab)->cmd_line[0], \
		(*tab)->cmd_line, global()->envp));
		perror_message((*tab)->cmd_line[1]);
	}
	clean_alloc(exec);
	exit(clean_exit(ft_strdup("cavalinho")));
}

static void	child(t_table **tab, t_exec *exec)
{
	if ((exec->i == 0) && (exec->amount_cmd > 1) && (((*tab)->out_red) == 0))
		dup2(exec->pipes[exec->i][1], STDOUT_FILENO);
	if ((exec->i < exec->amount_cmd - 1) && (exec->i != 0))
	{
		dup2(exec->pipes[exec->i - 1][0], STDIN_FILENO);
		dup2(exec->pipes[exec->i][1], STDOUT_FILENO);
	}
	else if ((exec->i == exec->amount_cmd - 1) && (exec->i != 0) && (!(*tab)->in_red))
		dup2(exec->pipes[exec->i - 1][0], STDIN_FILENO);
	check_infile(tab, exec);
	check_outfile(tab, exec);
	close_pipes(exec);
	if (!ft_strlen((*tab)->cmd_line[0]))
	{
		clean_alloc(exec);
		exit(clean_exit(ft_strdup("cavalinho")));
	}
	if (exec->amount_cmd > 1)
		is_built_in(tab, exec);
	execute(tab, exec);
}

static void	initialize_childs(t_table **tab, t_exec *exec)
{
	exec->pid[exec->i] = fork();
	if (exec->pid[exec->i] == -1)
		perror_message("fork");
	if (exec->pid[exec->i] == 0)
		child(tab, exec);
}

void	executor(t_table **tab)
{
	t_exec	exec;
	t_table	*aux;

	aux = *tab;
	initialize_variables(&exec, &aux);
	if ((exec.amount_cmd == 1) && !ft_strlen((aux)->cmd_line[0]))
		initialize_files(&aux);
	if ((exec.amount_cmd == 1) && ft_strlen((aux)->cmd_line[0]))
		is_built_in(&aux, &exec);
	if ((exec.amount_cmd > 1) || (!built_in_cmd((aux)->cmd_line[0]) \
	&& ft_strlen((aux)->cmd_line[0])))
	{
		alloc_resources(&exec);
		initialize_pipes(&exec);
		while (++exec.i < exec.amount_cmd)
		{
			initialize_files(&aux);
			initialize_childs(&aux, &exec);
			aux = aux->next;
		}
		close_pipes(&exec);
		wait_processes(&exec);
		pre_reset();
		clean_alloc_parent(&exec);
	}
}

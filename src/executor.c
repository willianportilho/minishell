/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 18:47:12 by wportilh          #+#    #+#             */
/*   Updated: 2022/09/20 17:48:20 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	clean_alloc(t_exec *exec)
{
	ft_free_int_array(&exec->pipes);
	ft_free_vector(&exec->pid);
}

static void	close_pipes(t_exec *exec)
{
	int	i;

	i = -1;
	while (++i < exec->amount_cmd - 1)
	{
		close(exec->pipes[i][0]);
		close(exec->pipes[i][1]);
	}
}

static int	validate_path(t_table **tab)
{
	int		i;

	i = -1;
	while ((*tab)->path[++i])
	{
		if (access((*tab)->path[i], F_OK) == 0)
			return (i);
	}
	return (-1);
}

static int	execute(t_table **tab, t_exec *exec)
{
	int	i;

	i = validate_path(tab);
	if (i == -1)
	{
		clean_alloc(exec);
		exit(127);
	}
	if (execve((*tab)->path[i], (*tab)->cmd_line, (*tab)->envp) == -1)
		perror("exec: exec:");
	clean_alloc(exec);
	exit(EXIT_FAILURE);
}

static void	check_infile(t_table **tab, t_exec *exec)
{
	if ((*tab)->in_red)
	{
		dup2((*tab)->infile_fd, STDIN_FILENO);
		close((*tab)->infile_fd);
		if (((*tab)->out_red != 0) && (exec->amount_cmd > 1))
			dup2(exec->pipes[exec->i][1], STDOUT_FILENO);
		if ((*tab)->infile_fd == -1)
		{
			clean_alloc(exec);
			exit (EXIT_FAILURE);
		}
	}
}

static void	check_outfile(t_table **tab, t_exec *exec)
{
	if ((*tab)->out_red)
	{
		if ((*tab)->outfile_fd == -1)
		{
			clean_alloc(exec);
			exit(EXIT_FAILURE);
		}
		if (((*tab)->in_red != 0) && (exec->amount_cmd > 1))
			dup2(exec->pipes[exec->i - 1][0], STDIN_FILENO);
		dup2((*tab)->outfile_fd, STDOUT_FILENO);
		close((*tab)->outfile_fd);
	}
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

static void	alloc_resources(t_exec *exec)
{
	int	i;

	i = -1;
	exec->pipes = malloc((exec->amount_cmd + 1) * sizeof(int *));
	while (++i < exec->amount_cmd)
		exec->pipes[i] = malloc((\
		exec->amount_cmd + 1) * sizeof(int));
	exec->pid = malloc((exec->amount_cmd + 1) * sizeof(int));
	exec->pipes[exec->amount_cmd] = NULL;
}

static void	initialize_vars(t_table **tab, t_exec *exec)
{
	exec->exit = 0;
	exec->tmpin = dup(STDIN_FILENO);
	exec->tmpout = dup(STDOUT_FILENO);
	exec->amount_cmd = 1;
	(*tab)->infile_fd = open((*tab)->in_file, O_RDONLY);
	if ((*tab)->infile_fd == -1)
		ft_printf("infile: colocar erro depois e limpar memória\n");
	(*tab)->outfile_fd = open((*tab)->out_file, \
	O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if ((*tab)->outfile_fd == -1)
		ft_printf("outfile: colocar erro depois e limpar memória\n");
	alloc_resources(exec);
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

static void	wait_process(t_exec *exec)
{
	int	i;
	int	wstatus;

	i = -1;
	while (++i < exec->amount_cmd)
	{
		waitpid(exec->pid[i], &wstatus, 0);
		if (WIFEXITED(wstatus))
			exec->exit = WEXITSTATUS(wstatus);
	}
}

void	executor(t_table **tab)
{
	t_exec	exec;

	initialize_vars(tab, &exec);
	initialize_pipes(&exec);
	initialize_childs(tab, &exec);
	close_pipes(&exec);
	wait_process(&exec);
	clean_alloc(&exec);
	if ((*tab)->next)
	{
		*tab = (*tab)->next;
		executor(tab);
	}
}

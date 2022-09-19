/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 18:47:12 by wportilh          #+#    #+#             */
/*   Updated: 2022/09/20 00:32:30 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	clean_alloc(t_pipex *pipex)
{
	ft_free_int_array(&pipex->pipes);
	ft_free_vector(&pipex->pid);
}

static void	close_pipes(t_pipex *pipex)
{
	int	j;

	j = -1;
	while (++j < pipex->amount_cmd - 1)
	{
		close(pipex->pipes[j][0]);
		close(pipex->pipes[j][1]);
	}
}

static int	execute(t_table **tab)
{
	//char	*cmd_path;
	//char	**cmd_arg;

	//cmd_arg = pipex_cmd_arg(argv[pipex.i + 2], data);
	//cmd_path = pipex_cmd_path(cmd_arg[0], envp);
	//if (!cmd_path)
	//{
	//	ft_printf("clean\n");
	//	process_clean(&cmd_path, &cmd_arg);
	//}
	int i = -1;
	while ((*tab)->path[++i])
	{
		if (execve((*tab)->path[i], (*tab)->cmd_line, (*tab)->envp) == -1)
			continue;
	}
	perror("pipex: exec:");
	//process_clean(&cmd_path, &cmd_arg);
	exit(EXIT_FAILURE);
}

static void	child(t_table **tab, t_pipex *pipex)
{
	if ((pipex->i < pipex->amount_cmd - 1) && (pipex->i != 0))
	{
		dup2(pipex->pipes[pipex->i - 1][0], STDIN_FILENO);
		dup2(pipex->pipes[pipex->i][1], STDOUT_FILENO);
	}
	if ((*tab)->in_red)
	{
		dup2((*tab)->infile_fd, STDIN_FILENO);
		close((*tab)->infile_fd);
		if (((*tab)->out_red != 0) && (pipex->amount_cmd > 1))
			dup2(pipex->pipes[pipex->i][1], STDOUT_FILENO);
		if ((*tab)->infile_fd == -1)
		{
			clean_alloc(pipex);
			exit (EXIT_FAILURE);
		}
	}
	if ((*tab)->out_red)
	{
		if ((*tab)->outfile_fd == -1)
		{
			clean_alloc(pipex);
			exit(EXIT_FAILURE);
		}
		if (((*tab)->in_red != 0) && (pipex->amount_cmd > 1))
			dup2(pipex->pipes[pipex->i - 1][0], STDIN_FILENO);
		dup2((*tab)->outfile_fd, STDOUT_FILENO);
		close((*tab)->outfile_fd);
	}
	close_pipes(pipex);
	execute(tab);
}

void	ft_pipex(t_table **tab, t_pipex *pipex)
{
	int	wstatus;

	while (++pipex->i < pipex->amount_cmd)
	{
		if (pipe(pipex->pipes[pipex->i]) == -1)
			ft_printf("pipe: colocar erro depois e limpar memória\n");
	}
	pipex->i = -1;
	while (++pipex->i < pipex->amount_cmd)
	{
		pipex->pid[pipex->i] = fork();
		if (pipex->pid[pipex->i] == -1)
			ft_printf("fork: colocar erro depois e limpar memória\n");
		if (pipex->pid[pipex->i] == 0)
			child(tab, pipex);
	}
	close_pipes(pipex);
	pipex->i = -1;
	while (++pipex->i < pipex->amount_cmd)
	{
		waitpid(pipex->pid[pipex->i], &wstatus, 0);
		if (WIFEXITED(wstatus))
			pipex->exit = WEXITSTATUS(wstatus);
	}
}

static void	alloc_resources(t_pipex *pipex)
{
	int	i;

	i = -1;
	pipex->pipes = malloc((pipex->amount_cmd + 1) * sizeof(int *));
	while (++i < pipex->amount_cmd)
		pipex->pipes[i] = malloc((\
		pipex->amount_cmd + 1) * sizeof(int));
	pipex->pid = malloc((pipex->amount_cmd + 1) * sizeof(int));
	pipex->pipes[pipex->amount_cmd] = NULL;
}

void	executor(t_table **tab)
{
	t_pipex	pipex;

	pipex.i = -1;
	pipex.exit = 0;
	pipex.amount_cmd = 1;
	(*tab)->infile_fd = open((*tab)->in_file, O_RDONLY);
	if ((*tab)->infile_fd == -1)
		ft_printf("infile: colocar erro depois e limpar memória\n");
	(*tab)->outfile_fd = open((*tab)->out_file, \
	O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if ((*tab)->outfile_fd == -1)
		ft_printf("outfile: colocar erro depois e limpar memória\n");
	alloc_resources(&pipex);
	ft_pipex(tab, &pipex);
	clean_alloc(&pipex);
}

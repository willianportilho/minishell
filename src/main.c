/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 17:11:39 by wportilh          #+#    #+#             */
/*   Updated: 2022/09/27 10:51:14 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	hard_init(char **envp)
{
	global()->test = 0;
	global()->heredoc = 0;
	global()->exit = 0;
	global()->envp = ft_array_dup(envp);
	global()->tabble = malloc(sizeof(t_table));
	global()->tabble->cmd = ft_strdup("");
	global()->tabble->cmd_line = ft_create_blank_array();
	global()->tabble->path = ft_create_blank_array();
	global()->tabble->envp = NULL;
	global()->tabble->envp = ft_create_blank_array();
	global()->tabble->next = NULL;
	global()->tabble->in_file = ft_strdup("");
	global()->tabble->out_file = ft_strdup("");
}

t_test	*global(void)
{
	static t_test	test;

	return (&test);
}

int	main(int argc, char **argv, char **envp)
{
	hard_init(envp);
	if (argv && argc > 1)
	{
		ft_putstr_fd("Error. No arguments are necessary", STDOUT_FILENO);
		return (EXIT_FAILURE);
	}
	minishell(&global()->tabble);
	return (global()->exit);
}

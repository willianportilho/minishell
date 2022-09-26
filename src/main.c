/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 17:11:39 by wportilh          #+#    #+#             */
/*   Updated: 2022/09/26 17:52:37 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

t_test	*global(void)
{
	static t_test	test;

	return (&test);
}

int	main(int argc, char **argv, char **envp)
{
	global()->exit = 0;
	global()->envp = ft_array_dup(envp);
	global()->tabble = malloc(sizeof(t_table));
	simple_init(global()->tabble);
	if (argv && argc > 1)
	{
		ft_putstr_fd("Error. No arguments are necessary", STDOUT_FILENO);
		return (EXIT_FAILURE);
	}
	minishell(&global()->tabble);
	return (global()->exit);
}

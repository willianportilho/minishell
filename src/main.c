/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 17:11:39 by wportilh          #+#    #+#             */
/*   Updated: 2022/09/22 17:43:59 by ralves-b         ###   ########.fr       */
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
	t_table	*tab;
	char	**my_envp;

	my_envp = ft_array_dup(envp);
	tab = malloc(sizeof(t_table));
	simple_init(tab);
	if (argv && argc > 1)
	{
		ft_putstr_fd("Error. No arguments are necessary", STDOUT_FILENO);
		return (EXIT_FAILURE);
	}
	minishell(&tab, my_envp);
	return (EXIT_SUCCESS);
}

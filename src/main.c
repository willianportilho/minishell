/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 17:11:39 by wportilh          #+#    #+#             */
/*   Updated: 2022/09/22 17:17:09 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

t_test	*global(void)
{
	static t_test	test;

	return (&test);
}

char	**ft_array_join_free(char **array, char *new_str)
{
	char	**new_array;
	int	i;

	i = -1;
	new_array = malloc(sizeof(array) + 1);
	while (array[++i])
	{
		new_array[i] = ft_strdup(array[i]);
	}
	new_array[i] = ft_strdup(new_str);
	new_array[i + 1] = NULL;
	return (new_array);
}

int	main(int argc, char **argv, char **envp)
{
	t_table	*tab;
	char	**my_envp;

	my_envp = ft_array_dup(envp);
	int i = 0;
	while (envp[i])
		i++;
	ft_printf("%s\n", envp[i - 1]);
	my_envp = ft_array_join_free(my_envp, "cavalinho=oi");
	ft_printf("%s\n", envp[i]);
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

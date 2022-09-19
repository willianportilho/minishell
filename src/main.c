/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 17:11:39 by wportilh          #+#    #+#             */
/*   Updated: 2022/09/19 14:49:53 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	get_path(char **envp, t_table **p, int i)
{
	char	**temp;

	temp = NULL;
	while (envp[i])
	{
		if (ft_strnstr(envp[i], "PATH=", 5))
		{
			temp = ft_split(envp[i] + 5, ':');
			break ;
		}
		i++;
	}
	if (temp == NULL)
		ft_msg_er("PATH not found", 0, 2);
	i = 0;
	while (temp[i])
		i++;
	(*p)->path = (char **)malloc((i + 1) * sizeof(*temp));
	(*p)->path[i] = NULL;
	while (i--)
	{
		(*p)->path[i] = ft_strjoin(temp[i], "/");
		free(temp[i]);
	}
	free(temp);
	(*p)->envp = envp;
}

int	main(int argc, char **argv, char **envp)
{
	t_table	*tab;

	tab = malloc(sizeof(t_table));
	signal_main();
	if (argv && argc > 1)
	{
		ft_putstr_fd("Error. No arguments are necessary", STDOUT_FILENO);
		return (EXIT_FAILURE);
	}
	get_path(envp, &tab, 0);
	minishell(&tab);
	return (EXIT_SUCCESS);
}

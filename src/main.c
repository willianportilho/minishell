/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 17:11:39 by wportilh          #+#    #+#             */
/*   Updated: 2022/09/13 22:03:17 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

static char	**pick_path(char **envp, int i)
{
	char	**temp;
	char	**paths;

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
		ft_putstr_fd("PATH not found", 1);
	i = 0;
	while (temp[i])
		i++;
	paths = (char **)malloc((i + 1) * sizeof(*temp));
	paths[i] = NULL;
	while (i--)
	{
		paths[i] = ft_strjoin(temp[i], "/");
		free(temp[i]);
	}
	free(temp);
	return (paths);
}

int	main(int argc, char **argv, char **envp)
{
	char	**paths;

	paths = pick_path(envp, 0);
	(void)paths;
	if (argv && argc > 1)
	{
		ft_putstr_fd("Error. No arguments are necessary", STDOUT_FILENO);
		return (EXIT_FAILURE);
	}
	minishell();
	return (EXIT_SUCCESS);
}

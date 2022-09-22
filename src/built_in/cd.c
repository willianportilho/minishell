/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 06:16:35 by wportilh          #+#    #+#             */
/*   Updated: 2022/09/22 18:33:40 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	cd(t_table **tab, char **envp)
{
	int 	i = 0;
	char	*home_expanded;

	while (envp[i])
    {
        if (ft_strnstr(envp[i], "HOME=", 5))
        {
            home_expanded = ft_strdup(envp[i] + 5);
            break ;
        }
        i++;
    }
	if (ft_str_is_equal((*tab)->cmd_line[0], "cd"))
	{
		if (ft_array_str_len((*tab)->cmd_line) > 2)
		{
			ft_putstr_fd("minishell: cd: too many arguments\n", 2);
			return ;
		}
		if ((*tab)->cmd_line[1])
			chdir((*tab)->cmd_line[1]);
		else
			chdir(home_expanded);
		free(home_expanded);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 17:55:36 by ralves-b          #+#    #+#             */
/*   Updated: 2022/11/18 09:18:11 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static void	test_exit_exception_2(char *str)
{
	long	num;

	num = ft_atol(str);
	if (str)
	{
		if ((((str[0] == '-') && (num > 0))) \
		|| ((str[0] != '-') && (num < 0)) || (ft_strlen(str) > 20))
		{
			ft_putstr_fd("minishell: exit: numeric argument required\n", 2);
			global()->exit = 2;
		}
	}
}

static int	test_exit_exception(char **ar)
{
	int	i;

	i = -1;
	while (ar[++i])
	{
		if (ft_is_numeric(ar[i]))
		{
			ft_putstr_fd("minishell: exit: too many arguments\n", 2);
			return (1);
		}
	}
	rl_clear_history();
	global()->exit = 2;
	exit(clean_exit(ft_strdup("cavalinho")));
}

int	exit_builtin(t_table **tab)
{
	if (ft_array_str_len((*tab)->cmd_line) > 2)
		return (test_exit_exception((*tab)->cmd_line));
	else if (ft_array_str_len((*tab)->cmd_line) == 2)
	{
		rl_clear_history();
		if (ft_is_numeric((*tab)->cmd_line[1]))
		{
			global()->exit = ft_atoi((*tab)->cmd_line[1]);
			test_exit_exception_2((*tab)->cmd_line[1]);
			exit (clean_exit(ft_strdup("cavalinho")));
		}
		else
		{
			global()->exit = 2;
			ft_putstr_fd(" numeric argument required\n", 2);
			exit (clean_exit(ft_strdup("cavalinho")));
		}
		clean_exit(ft_strdup("cavalinho"));
		exit (global()->exit);
	}
	else
	{
		rl_clear_history();
		exit (clean_exit(ft_strdup("cavalinho")));
	}
}

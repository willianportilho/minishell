/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exportation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 22:48:23 by wportilh          #+#    #+#             */
/*   Updated: 2022/09/28 17:00:24 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static void	print_with_no_args(char **array)
{
	int		i;
	char	*tmp;
	char	*tmp2;
	char	*str;

	i = -1;
	while (array && array[++i])
	{
		if (ft_strlen_til_chr(array[i], '=') != -1)
		{
			tmp = ft_strdup(array[i] + (ft_strlen_til_chr(array[i], '=') + 1));
			tmp2 = ft_add_char_start_end(tmp, '"');
			free(tmp);
			tmp = ft_strndup(array[i], ft_strlen_til_chr(array[i], '=') + 1);
			tmp = ft_strjoin_free(tmp, tmp2);
			str = ft_strjoin("declare -x ", tmp);
			ft_printf("%s\n", str);
			free(tmp);
			free(tmp2);
			free(str);
		}
		else
			ft_printf("declare -x %s\n", array[i]);
	}
}

static int	check_dup(char *arg, int i, int i2)
{
	if ((!global()->envp[i][i2]) || (global()->envp[i][i2] == '='))
	{
		if (!arg[i2])
			return (0);
		global()->envp = array_remove_export(i);
	}
	return (1);
}

static int	check_env_dup(char *arg)
{
	int		i;
	int		i2;
	int		check;
	char	*tmp;

	i = -1;
	i2 = 0;
	check = 1;
	while (arg[i2] && (arg[i2] != '='))
		i2++;
	tmp = ft_strndup(arg, i2);
	while (global()->envp[++i])
	{
		if (!strncmp(tmp, global()->envp[i], i2))
			check = check_dup(arg, i, i2);
		if (!global()->envp[i])
			i--;
	}
	free(tmp);
	return (check);
}

static void	export_variable(char *cmd)
{
	char	***p;

	p = &global()->envp;
	if (check_characters(cmd))
	{
		if (check_env_dup(cmd))
			*p = ft_array_join_free(global()->envp, \
			cmd);
	}
	else
		global()->exit = 1;
}

int	exportation(t_table **tab)
{
	int		i;

	i = 0;
	global()->exit = 0;
	if (global()->envp)
	{
		if (ft_array_str_len((*tab)->cmd_line) == 1)
			print_with_no_args(global()->envp);
		else
		{
			while ((*tab)->cmd_line[++i])
				export_variable((*tab)->cmd_line[i]);
		}
	}
	return (global()->exit);
}

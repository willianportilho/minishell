/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exportation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 22:48:23 by wportilh          #+#    #+#             */
/*   Updated: 2022/09/26 17:19:01 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static char	**array_remove_str(int i)
{
	char	**new_array;
	int		size;
	int		i_na;
	int		i_a;

	i_a = 0;
	i_na = 0;
	size = ft_array_str_len(global()->envp);
	new_array = (char **)malloc(size * sizeof(char *));
	while (i_a < size)
	{
		if (i_a == i)
			i_a++;
		new_array[i_na] = ft_strdup(global()->envp[i_a]);
		i_a++;
		i_na++;
	}
	new_array[i_na - 1] = NULL;
	ft_free_array(global()->envp);
	return (new_array);
}

static void	print_with_no_args(char **array)
{
	int		i;
	char	*tmp;
	char	*tmp2;
	char	*tmp3;
	char	*tmp4;
	char	*str;

	i = -1;
	if (!array || !*array)
		return ;
	while (array[++i])
	{
		tmp = ft_strdup(array[i] + (ft_strlen_til_chr(array[i], '=') + 1));
		tmp2 = ft_add_char_start_end(tmp, '"');
		tmp3 = ft_strndup(array[i], ft_strlen_til_chr(array[i], '=') + 1);
		tmp4 = ft_strjoin(tmp3, tmp2);
		str = ft_strjoin("declare -x ", tmp4);
		if (ft_count_c_in_str(array[i], '='))
			ft_printf("%s\n", str);
		else
			ft_printf("declare -x %s\n", tmp);
		free(tmp);
		free(tmp2);
		free(tmp3);
		free(tmp4);
		free(str);
	}
}

static int	check_env_dup(char *arg, char **array)
{
	int		i;
	int		i2;
	char	*tmp;
	char	**tmp_array;

	i = -1;
	i2 = 0;
	while (arg[i2] && (arg[i2] != '='))
		i2++;
	tmp = ft_strndup(arg, i2);
	while (array[++i])
	{
		if (!strncmp(tmp, array[i], i2))
		{
			if ((!array[i][i2]) || (array[i][i2] == '='))
			{
				if (!arg[i2])
				{
					//ft_printf("print\n");
					free(tmp);
					return (0);
				}
				tmp_array = array_remove_str(i);
				//ft_array_print(tmp_array);
				global()->envp = tmp_array;
				if (i == ft_array_str_len(global()->envp))
					i--;
			}
		}
	}
	free(tmp);
	return (1);
}

void	exportation(t_table **tab, t_exec *exec)
{
	int		i;
	char	***p;

	i = 0;
	if (global()->envp)
	{
		p = &global()->envp;
		if (ft_array_str_len((*tab)->cmd_line) == 1)
			print_with_no_args(global()->envp);
		else
		{
			while ((*tab)->cmd_line[++i])
			{
				if (check_env_dup((*tab)->cmd_line[i], global()->envp))
					*p = ft_array_join_free(global()->envp, (*tab)->cmd_line[i]);
			}
		}
	}
	if (exec->amount_cmd > 1)
		exit(0);
}

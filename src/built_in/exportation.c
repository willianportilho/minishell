/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exportation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 22:48:23 by wportilh          #+#    #+#             */
/*   Updated: 2022/09/24 04:30:15 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static char	*add_quotes(char *old_str)
{
	int		equal_sign;
	char	*tmp;
	char	*tmp2;
	char	*tmp3;
	char	*new_str;

	equal_sign = 0;
	equal_sign = ft_strlen_til_chr(old_str, '=');
	tmp = ft_strdup(old_str + (equal_sign + 1));
	tmp2 = ft_add_char_start_end(tmp, '"');
	tmp3 = ft_strndup(old_str, ft_strlen_til_chr(old_str, '=') + 1);
	new_str = ft_strjoin(tmp3, tmp2);
	free(tmp);
	free(tmp2);
	free(tmp3);
	return (new_str);
}

static void	print_with_no_args(char **array)
{
	int		i;
	char	*str;
	char	*tmp;

	i = -1;
	if (!array || !(*array))
		return ;
	while (array[++i])
	{
		tmp = add_quotes(array[i]);
		str = ft_strjoin("declare -x ", tmp);
		ft_printf("%s\n", str);
		free(tmp);
		free(str);
	}
}

void	exportation(t_table **tab, t_exec *exec)
{
	int	i;

	i = 0;
	if (exec)
		;
	if (ft_array_str_len((*tab)->cmd_line) == 1)
		print_with_no_args(global()->envp);
}

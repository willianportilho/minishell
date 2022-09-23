/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 21:27:56 by wportilh          #+#    #+#             */
/*   Updated: 2022/09/22 21:28:48 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	built_in_cd_error(t_table **tab)
{
	char	*str;

	str = ft_strjoin("minishell: cd: ", (*tab)->cmd_line[1]);
	perror(str);
	free(str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 17:55:36 by ralves-b          #+#    #+#             */
/*   Updated: 2022/09/26 18:51:49 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	exit_builtin(t_table **tab)
{
	if (ft_atoi((*tab)->cmd + 5))
		exit (ft_atoi((*tab)->cmd + 5));
	exit (global()->exit);
}

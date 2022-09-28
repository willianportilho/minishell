/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_clean.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 22:39:09 by wportilh          #+#    #+#             */
/*   Updated: 2022/09/28 02:55:45 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	clean_alloc_parent(t_exec *exec)
{
	ft_free_int_array(&exec->pipes);
	ft_free_vector(&exec->pid);
}

void	clean_alloc(t_exec *exec)
{
	rl_clear_history();
	ft_free_int_array(&exec->pipes);
	ft_free_vector(&exec->pid);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_minishell.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 14:00:34 by ralves-b          #+#    #+#             */
/*   Updated: 2022/09/27 11:27:10 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	clean_exit(char *free_me)
{
	free(free_me);
	ft_free_array(global()->envp);
	free(global()->tabble->cmd);
	ft_free_array(global()->tabble->cmd_line);
	ft_free_array(global()->tabble->path);
	ft_free_array(global()->tabble->envp);
	free(global()->tabble->in_file);
	free(global()->tabble->out_file);
	ft_lstclear_t(&global()->tabble);
	rl_clear_history();
	return (global()->exit);
}

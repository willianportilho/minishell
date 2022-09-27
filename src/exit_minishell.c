/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_minishell.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 14:00:34 by ralves-b          #+#    #+#             */
/*   Updated: 2022/09/27 15:07:57 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	clear_tokens_lst(t_tokens **lst)
{
	t_tokens	*aux;
	t_tokens	*temp;

	aux = *lst;
	while (aux)
	{
		temp = aux->next;
		free(aux->str);
		free(aux);
		aux = temp;
	}
}

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
	return (global()->exit);
}

void	free_tab(t_table *tab)
{
	free(tab->cmd);
	ft_free_array(tab->cmd_line);
	ft_free_array(tab->path);
	ft_free_array(tab->envp);
	free(tab->in_file);
	free(tab->out_file);
}

void	next_n_free_tab(t_table *tab)
{
	t_table	*temp;

	temp = tab->next;
	free_tab(tab);
	tab = temp;
}

int	msg_n_exit_function(char *msg, int (*f)(char *), char *fr)
{
	rl_clear_history();
	ft_putstr_fd(msg, STDOUT_FILENO);
	return (f(fr));
}

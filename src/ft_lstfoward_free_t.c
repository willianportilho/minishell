/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfoward_free_t.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 21:49:50 by ralves-b          #+#    #+#             */
/*   Updated: 2022/09/20 13:14:19 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	ft_lstfoward_free_t(t_tokens **lst)
{
	t_tokens	*temp;

	if (!(*lst))
		return ;
	temp = (*lst)->next;
	free((*lst)->str);
	free (*lst);
	*lst = temp;
}

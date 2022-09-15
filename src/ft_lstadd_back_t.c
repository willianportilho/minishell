/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_t.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 14:41:20 by ralves-b          #+#    #+#             */
/*   Updated: 2022/09/15 14:43:19 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

static t_tokens	*ft_lstlast_t(t_tokens *lst)
{
	t_tokens	*aux_lst;

	aux_lst = lst;
	if (!lst)
		return (lst);
	while (aux_lst->next)
		aux_lst = aux_lst->next;
	return (aux_lst);
}

void	ft_lstadd_back_t(t_tokens **lst, t_tokens *new)
{
	t_tokens	*aux;

	if (!new)
		return ;
	if (*lst == NULL)
		(*lst) = new;
	else
	{
		aux = ft_lstlast_t(*lst);
		aux->next = new;
	}
}

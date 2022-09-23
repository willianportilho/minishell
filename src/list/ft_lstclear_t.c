/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_t.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 13:58:26 by ralves-b          #+#    #+#             */
/*   Updated: 2022/09/23 19:43:39 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	ft_lstclear_t(t_table **tab)
{
	t_table	*aux;
	t_table	*temp;

	if (tab == NULL || (*tab) == NULL)
		return ;
	aux = *tab;
	while (aux)
	{
		temp = aux;
		aux = aux->next;
		free(temp);
	}
	tab = NULL;
}

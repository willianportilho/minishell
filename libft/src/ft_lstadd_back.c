/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 04:36:51 by wportilh          #+#    #+#             */
/*   Updated: 2022/09/12 18:30:02 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	temp = *lst;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	else if (temp->next == NULL)
	{
		temp->next = new;
		return ;
	}
	while (temp->next != NULL)
	{
		temp = temp->next;
		if (temp->next == NULL)
		{
			temp->next = new;
			return ;
		}
	}
}

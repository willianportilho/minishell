/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 04:00:55 by wportilh          #+#    #+#             */
/*   Updated: 2022/09/12 18:30:09 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*temp;

	temp = *lst;
	if (temp == NULL)
		return ;
	while (*lst)
	{
		*lst = (*lst)->next;
		del(temp->content);
		free(temp);
		temp = *lst;
	}
	*lst = NULL;
}

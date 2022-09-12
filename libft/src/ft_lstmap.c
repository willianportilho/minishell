/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 05:55:42 by wportilh          #+#    #+#             */
/*   Updated: 2022/09/12 18:30:23 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*tmp_new;
	t_list	*new;

	if (!lst)
		return (NULL);
	new = ft_lstnew(f(lst->content));
	if (!new)
	{
		ft_lstclear(&new, del);
		return (NULL);
	}
	tmp_new = new;
	while (lst->next)
	{
		lst = lst->next;
		tmp_new->next = ft_lstnew(f(lst->content));
		if (!tmp_new)
		{
			ft_lstclear(&tmp_new, del);
			return (NULL);
		}
		tmp_new = tmp_new->next;
	}
	return (new);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 01:45:59 by wportilh          #+#    #+#             */
/*   Updated: 2022/09/23 21:52:07 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	ft_lstsize_tab(t_table *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		ft_printf("%p\n", lst);
		ft_printf("%s\n", lst->next);
		lst = lst->next;
		i++;
	}
	ft_printf("%d\n", i);
	return (i);
}

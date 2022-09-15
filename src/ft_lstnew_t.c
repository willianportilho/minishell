/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_t.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 14:41:34 by ralves-b          #+#    #+#             */
/*   Updated: 2022/09/15 14:41:35 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

t_tokens	*ft_lstnew_t(char *str)
{
	t_tokens	*n;

	n = malloc(sizeof(t_tokens));
	if (n == NULL)
		return (NULL);
	(*n).str = str;
	n->next = NULL;
	return (n);
}

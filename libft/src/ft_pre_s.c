/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pre_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 22:49:47 by wportilh          #+#    #+#             */
/*   Updated: 2022/09/12 18:30:50 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

void	ft_pre_s(char *s, int *i, int *len)
{
	int	len_s;

	len_s = 0;
	*i = *i + 2;
	if (!s)
	{
		ft_print_s("(null)");
		*len = *len + 6;
		return ;
	}
	while (s[len_s])
		len_s++;
	*len = *len + len_s;
	ft_print_s(s);
}

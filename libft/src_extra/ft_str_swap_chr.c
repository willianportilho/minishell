/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_swap_chr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 20:08:18 by ralves-b          #+#    #+#             */
/*   Updated: 2022/09/20 22:55:46 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

void	ft_str_swap_chr(char **str, char old, char new)
{
	int	i;

	i = 0;
	while ((*str)[i])
	{
		if ((*str)[i] == old)
			(*str)[i] = new;
		i++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 23:07:42 by ralves-b          #+#    #+#             */
/*   Updated: 2022/09/23 23:10:22 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"
#include "../../inc/ft_printf.h"

void	ft_array_print(char **array)
{
	int	i;

	i = -1;
	if (!array || !(*array))
		return ;
	while (array[++i])
		ft_printf("%s\n", array[i]);
}

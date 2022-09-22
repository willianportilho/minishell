/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_til_chr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 16:41:35 by ralves-b          #+#    #+#             */
/*   Updated: 2022/09/22 21:25:39 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

int	ft_strlen_til_chr(char *str, char chr)
{
	int	counter;

	counter = 0;
	if (!str)
		return (-1);
	while (str[counter] && str[counter] != chr)
		counter++;
	if (!str[counter] && chr)
		return (-1);
	return (counter);
}

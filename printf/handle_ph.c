/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_ph.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 19:59:17 by ralves-b          #+#    #+#             */
/*   Updated: 2022/09/12 21:00:46 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

t_str	handle_ph(int *count)
{
	t_str	str;

	str.s = ft_strdup("%");
	str.size = 1;
	*count += str.size;
	return (str);
}

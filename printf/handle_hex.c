/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 20:53:11 by ralves-b          #+#    #+#             */
/*   Updated: 2022/09/12 21:00:54 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

t_str	handle_hex(va_list args, int *count, t_flags *flags)
{
	t_str	str;
	int		temp;

	temp = va_arg(args, int);
	str.s = ft_itohex(temp);
	str.size = ft_strlen(str.s);
	*count += str.size;
	if (flags->spcf == 'X')
		str.s = ft_strtoupper(str.s);
	if (str.size == 1 && str.s[0] == '0')
		flags->null = TRUE;
	return (str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 19:06:03 by ralves-b          #+#    #+#             */
/*   Updated: 2022/09/12 21:00:41 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

t_str	handle_str(va_list args, int *count, t_flags *flags)
{
	t_str	str;
	char	*temp;

	temp = va_arg(args, char *);
	if (temp == NULL)
	{
		str.s = ft_strdup("(null)");
		flags->null = TRUE;
	}
	else
		str.s = ft_strdup(temp);
	str.size = ft_strlen(str.s);
	*count += str.size;
	return (str);
}

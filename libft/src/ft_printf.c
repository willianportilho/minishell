/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 20:56:10 by wportilh          #+#    #+#             */
/*   Updated: 2022/09/12 18:31:16 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

static void	select_type(char *p, int *i, int *len, va_list ap)
{
	if ((p[*i] == '%') && (p[*i + 1] == 'c'))
		ft_pre_c(va_arg(ap, int), i, len);
	if ((p[*i] == '%') && (p[*i + 1] == 'd'))
		ft_pre_d_i(va_arg(ap, int), i, len);
	if ((p[*i] == '%') && (p[*i + 1] == 'i'))
		ft_pre_d_i(va_arg(ap, int), i, len);
	if ((p[*i] == '%') && (p[*i + 1] == 'u'))
		ft_pre_u(va_arg(ap, unsigned int), i, len);
	if ((p[*i] == '%') && (p[*i + 1] == 'x'))
		ft_pre_x_lower(va_arg(ap, unsigned int), i, len);
	if ((p[*i] == '%') && (p[*i + 1] == 'X'))
		ft_pre_x_upper(va_arg(ap, unsigned int), i, len);
	if ((p[*i] == '%') && (p[*i + 1] == 'p'))
		ft_pre_p(va_arg(ap, size_t), i, len);
	if ((p[*i] == '%') && (p[*i + 1] == 's'))
		ft_pre_s(va_arg(ap, char *), i, len);
}

static void	without_type(char c, int *i, int *len)
{
	ft_print_c(c);
		*i = *i + 1;
		*len = *len + 1;
}

int	ft_printf(const char *s, ...)
{
	va_list	ap;
	char	*p;
	int		len;
	int		i;

	p = (char *)s;
	len = 0;
	i = 0;
	va_start(ap, s);
	while (p[i])
	{
		if ((p[i] != '%') && (p[i]))
			without_type(p[i], &i, &len);
		if (((p[i] == '%') && (p[i + 1] == '%')) && (p[i]))
			without_type(p[++i], &i, &len);
		if (p[i])
			select_type(p, &i, &len, ap);
	}
	va_end(ap);
	return (len);
}

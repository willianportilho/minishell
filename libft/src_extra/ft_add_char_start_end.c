/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_char_start_end.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 03:22:27 by wportilh          #+#    #+#             */
/*   Updated: 2022/09/24 03:35:26 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

char	*ft_add_char_start_end(char *str, char c)
{
	int		i;
	int		i2;
	int		size;
	char	*new_str;

	i = 0;
	i2 = 0;
	if (str)
	{
		size = ft_strlen(str);
		new_str = (char *)malloc(size + 3 * sizeof(char));
		new_str[i] = c;
		while (str[i2])
			new_str[++i] = str[i2++];
		new_str[++i] = c;
		new_str[++i] = '\0';
		return (new_str);
	}
	return (NULL);
}

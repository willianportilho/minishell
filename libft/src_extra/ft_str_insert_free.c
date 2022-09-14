/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_insert_free.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 18:02:27 by ralves-b          #+#    #+#             */
/*   Updated: 2022/09/14 19:18:44 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

char	*ft_str_insert_free(char *str, char chr, int index)
{
	char	*new_str;
	int		i_ns;
	int		i_s;

	i_ns = 0;
	i_s = 0;
	if (index > (int)ft_strlen(str))
	{
		new_str = ft_strdup(str);
		return (free(str), new_str);
	}
	new_str = (char *)malloc((ft_strlen(str) + 2) * sizeof(char));
	while (i_ns < (int)ft_strlen(str) + 1)
	{
		if (i_ns == index)
			new_str[i_ns] = chr;
		else
        {
			new_str[i_ns] = str[i_s];
            i_s++;
        }
		i_ns++;
	}
    new_str[i_ns] = '\0';
    return (free(str), new_str);
}

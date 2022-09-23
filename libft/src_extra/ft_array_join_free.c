/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_join_free.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 17:44:22 by ralves-b          #+#    #+#             */
/*   Updated: 2022/09/23 20:07:18 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

char	**ft_array_join_free(char **a, char *new_str)
{
	char	**new_array;
	int		i;

	new_array = (char **)malloc((ft_array_str_len(a) + 2) * sizeof(char *));
	i = 0;
	while (a[i])
	{
		new_array[i] = ft_strdup(a[i]);
		i++;
	}
	new_array[i] = ft_strdup(new_str);
	new_array[i + 1] = NULL;
	ft_free_array(a);
	return (new_array);
}

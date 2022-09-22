/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_join_free.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 17:44:22 by ralves-b          #+#    #+#             */
/*   Updated: 2022/09/22 17:44:33 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

char	**ft_array_join_free(char **array, char *new_str)
{
	char	**new_array;
	int		i;

	i = 0;
	while (array[i])
		i++;
	new_array = (char **)malloc((i + 2) * sizeof(char *));
	i = 0;
	while (array[i])
	{
		new_array[i] = ft_strdup(array[i]);
		i++;
	}
	new_array[i] = ft_strdup(new_str);
	
	new_array[i + 1] = NULL;
	return (new_array);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_dup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 16:19:40 by ralves-b          #+#    #+#             */
/*   Updated: 2022/09/22 21:25:10 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

char	**ft_array_dup(char **array)
{
	char	**new_array;
	int		i;

	if (!(**array))
		return (NULL);
	i = 0;
	while (array[i])
		i++;
	new_array = (char **)malloc((i + 1) * sizeof(char *));
	i = -1;
	while (array[++i])
		new_array[i] = ft_strdup(array[i]);
	new_array[i] = NULL;
	return (new_array);
}

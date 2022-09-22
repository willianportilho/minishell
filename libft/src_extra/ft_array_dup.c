/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_dup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 16:19:40 by ralves-b          #+#    #+#             */
/*   Updated: 2022/09/22 16:23:17 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

char    **ft_array_dup(char **array)
{
    char    **new_array;
    int     i;

    if (!(**array))
        return (NULL);
    i = -1;
    new_array = malloc(sizeof(array));
    while (array[++i])
        new_array[i] = ft_strdup(array[i]);
    new_array[i] = NULL;
    return (new_array);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_blank_array.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 00:14:21 by ralves-b          #+#    #+#             */
/*   Updated: 2022/09/29 17:21:12 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

char	**ft_create_blank_array(void)
{
	char	**array;

	array = (char **)malloc(2 * sizeof(char *));
	array[0] = ft_strdup("");
	array[1] = NULL;
	return (array);
}

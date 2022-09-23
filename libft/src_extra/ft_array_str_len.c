/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_str_len.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 17:46:20 by ralves-b          #+#    #+#             */
/*   Updated: 2022/09/22 17:46:21 by ralves-b         ###   ########.fr       */
=======
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 17:01:14 by wportilh          #+#    #+#             */
/*   Updated: 2022/09/22 17:40:23 by wportilh         ###   ########.fr       */
>>>>>>> cd
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

int	ft_array_str_len(char **array)
{
	int	i;
	int	len;

	if (!(**array))
		return (-1);
	i = -1;
	len = 0;
	while (array[++i])
		len++;
	return (len);
}

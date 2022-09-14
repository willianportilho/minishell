/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_swap_chr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 20:08:18 by ralves-b          #+#    #+#             */
/*   Updated: 2022/09/14 20:10:08 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void    ft_str_swap_chr(char **str, char old, char new)
{
    int i;

    i = 0;
    while ((*str)[i])
    {
        if ((*str)[i] == old)
            (*str)[i] = new;
        i++;
    }
}

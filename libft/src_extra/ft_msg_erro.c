/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_msg_erro.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 18:53:57 by ralves-b          #+#    #+#             */
/*   Updated: 2022/09/26 19:01:45 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"
#include "../../inc/ft_printf.h"
#include "../../inc/minishell.h"

int	ft_msg_er(char *msg, int erro, int fd)
{
	ft_putstr_fd(msg, fd);
	global()->exit = erro;
	return (erro);
}

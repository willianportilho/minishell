/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 20:56:35 by ralves-b          #+#    #+#             */
/*   Updated: 2022/09/28 21:00:03 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	redirect_tkn_error(t_tokens **tks)
{
	char	*msg_erro;

	msg_erro = ft_strdup("newline");
	if (*tks)
	{
		free(msg_erro);
		msg_erro = ft_strdup((*tks)->str);
		while (*tks)
			ft_lstfoward_free_t(tks);
	}
	ft_putstr_fd(SYNTXERR, 2);
	ft_putstr_fd(msg_erro, 2);
	ft_putstr_fd("'\n", 2);
	free(msg_erro);
	global()->control = FALSE;
	global()->exit = 2;
}

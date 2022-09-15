/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 19:39:58 by wportilh          #+#    #+#             */
/*   Updated: 2022/09/15 21:23:37 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

static void	handle_sigint(int sig)
{
	(void)sig;
	ft_putchar_fd('\n', 2);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

void	signal_main(void)
{
	signal(SIGINT, &handle_sigint);
	signal(SIGQUIT, SIG_IGN);
}

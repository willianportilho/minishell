/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <rodrigoab123@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 19:39:58 by wportilh          #+#    #+#             */
/*   Updated: 2022/10/05 00:26:22 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	handle_sigint(int sig)
{
	(void)sig;
	if (global()->heredoc)
	{
		global()->heredoc = FALSE;
		global()->test = FALSE;
	}
	else if (global()->test)
	{
		global()->exit = 130;
		ft_putchar_fd('\n', STDOUT_FILENO);
		global()->test = FALSE;
	}
	else
	{
		ft_putchar_fd('\n', STDOUT_FILENO);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

void	signal_main(void)
{
	signal(SIGINT, &handle_sigint);
	signal(SIGQUIT, SIG_IGN);
}

void	ctrlc_child_handler(int sig)
{
	(void) sig;
	global()->exit = 130;
	ft_putchar_fd('\n', STDOUT_FILENO);
	rl_replace_line("", 0);
	rl_on_new_line();
}

void	ctrlc_here_doc_handler(int sig)
{
	(void) sig;
	global()->exit = 130;
	ft_putchar_fd('\n', STDOUT_FILENO);
	rl_replace_line("", 0);
	rl_clear_history();
	pre_reset();
	reset_tab(ft_strdup("cavalinho"));
	clean_exit(ft_strdup("cavalinho"));
	exit(global()->exit);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 19:39:58 by wportilh          #+#    #+#             */
/*   Updated: 2022/10/04 21:35:54 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	handle_sigint(int sig)
{
	(void)sig;
	if (global()->test)
	{
		ft_putchar_fd('\n', STDOUT_FILENO);
		rl_replace_line("", 0);
		rl_clear_history();
		pre_reset();
		reset_tab(ft_strdup("cavalinho"));
		clean_exit(ft_strdup("cavalinho"));
		exit(-1);
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
	struct sigaction sa;
	struct sigaction sb;

	sa.sa_handler = &handle_sigint;
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGINT);
	sb.sa_handler = SIG_IGN;
	sb.sa_flags = 0;
	sigemptyset(&sb.sa_mask);
	sigaddset(&sb.sa_mask, SIGQUIT);
	sigaction(SIGINT, &sa, NULL);
	sigaction(SIGQUIT, &sb, NULL);
}

void	signal_executor(int pid)
{
	struct sigaction sa;
	struct sigaction sb;
	
	if (!pid)
	{
		sa.sa_handler = SIG_DFL;
		sb.sa_handler = SIG_DFL;
	}
	else
	{
		sa.sa_handler = SIG_IGN;
		sb.sa_handler = SIG_IGN;
	}
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);
	//sigaddset(&sa.sa_mask, SIGINT);
	sb.sa_flags = 0;
	sigemptyset(&sb.sa_mask);
	//sigaddset(&sb.sa_mask, SIGQUIT);
	sigaction(SIGINT, &sa, NULL);
	sigaction(SIGQUIT, &sb, NULL);
}

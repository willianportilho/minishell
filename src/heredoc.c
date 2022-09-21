/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 17:47:42 by ralves-b          #+#    #+#             */
/*   Updated: 2022/09/21 21:08:38 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	heredoc(t_tokens **tks, t_table **tab)
{
	char	*buf;

	(*tab)->in_delimiter = TRUE;
	(*tab)->infile_fd = open(".heredoc", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	ft_lstfoward_free_t(tks);
	while ((*tab)->in_delimiter)
	{
		buf = readline(">");
		if (ft_str_is_equal(buf, (*tks)->str))
		{
			(*tab)->in_delimiter = FALSE;
			break ;
		}
		write((*tab)->infile_fd, buf, ft_strlen(buf));
		ft_putstr_fd("\n", (*tab)->infile_fd);
	}
	close((*tab)->infile_fd);
	(*tab)->in_file = ft_strdup(".heredoc");
	ft_lstfoward_free_t(tks);
	(*tab)->in_red = TRUE;
}

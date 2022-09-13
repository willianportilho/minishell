#include "../inc/minishell.h"

int	ft_msg_er(char *msg, int erro, int fd)
{
	ft_putstr_fd(msg, fd);
	return (erro);
}

static int	check_semicolon_and_backslash(char *buff)
{
	int		i;
	t_bool	btwn_s_quotes;
	t_bool	btwn_d_quotes;

	btwn_s_quotes = FALSE;
	btwn_d_quotes = FALSE;
	i = -1;
	while (buff[++i])
	{
		if (buff[i] == D_QUOTE && !btwn_d_quotes && !btwn_s_quotes)
			btwn_d_quotes = TRUE;
		else if (buff[i] == D_QUOTE && btwn_d_quotes)
			btwn_d_quotes = FALSE;
		else if (buff[i] == S_QUOTE && !btwn_s_quotes && !btwn_d_quotes)
			btwn_s_quotes = TRUE;
		else if (buff[i] == S_QUOTE && btwn_s_quotes)
			btwn_s_quotes = FALSE;
		if ((buff[i] == SEMICOLON || buff[i] == BACKSLASH)
			&& !btwn_d_quotes && !btwn_s_quotes)
			return (ft_msg_er("invalid ; or \\\n", EXIT_FAILURE, STDOUT_FILENO));
	}
	if (btwn_d_quotes || btwn_s_quotes)
		return (ft_msg_er("unclosed quotes\n", EXIT_FAILURE, STDOUT_FILENO));
	return (EXIT_SUCCESS);
}

static void    check(char *msg, int expected)
{
    if (check_semicolon_and_backslash(msg) == expected)
        ft_printf("teste com = %s  :  OK\n", msg);
    else
        ft_printf("teste com = %s  :  FAIL\n", msg);
}

int main(void)
{
    check("\"\"", 0);
    check("\";\"", 0);
    check("\"\\;\"", 0);
    check("\"\\;'\"", 0);
    check("\'\\;\"\'", 0);
    check("\"''';\\\"\\", 1);
    check("\'\"\';\"", 1);
    check("\'\";\"", 1);
    check("\'\";\\\"\\\'", 0);
    check("\'\\\";\\\"\\\'", 0);
}
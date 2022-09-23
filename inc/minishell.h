/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 23:11:52 by wportilh          #+#    #+#             */
/*   Updated: 2022/09/23 04:24:34 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "./libft.h"
# include "./ft_printf.h"
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include <sys/wait.h>
# include <fcntl.h>

# define TEMP_VALUE	1
# define HDERRO	"bash: warning: here-document delimited by end-of-file"

typedef struct s_st
{
	t_bool	test;
	t_bool	heredoc;
	int		fd_global;
}			t_test;

typedef struct s_exec
{
	int				amount_cmd;
	int				**pipes;
	int				*pid;
	int				exit;
	int				check;
	int				pos;
	int				i;
}					t_exec;

typedef struct s_envp
{
	char			*key;
	char			*value;
	struct s_envp	*next;
}					t_envp;

typedef struct s_tokens
{
	char			*str;
	int				token;
	t_bool			error;
	struct s_tokens	*next;
}					t_tokens;

typedef struct s_table
{
	char			*cmd;
	char			**cmd_line;
	char			**path;
	char			**envp;
	t_bool			heredoc_error;
	t_bool			path_done;
	t_bool			pipe;
	t_bool			in_red;
	t_bool			out_red;
	t_bool			in_delimiter;
	t_bool			out_append;
	char			*in_file;
	int				infile_fd;
	char			*out_file;
	int				outfile_fd;
	struct s_table	*next;
}					t_table;

/**
 * @brief List of tokens to help lexer and parser
 * 
 * @param B_SLASH \
 * @param COMMAND ls -a (example)
 * @param S_QUOTE '
 * @param D_QUOTE "
 * @param S_COLON ;
 * @param PIPE |
 * @param I_REDIRECT <
 * @param O_REDIRECT >
 * @param APP_O_REDIRECT >>
 * @param DELIMITER <<
 * @param EXPANDABLE "$hi" (example)
 * @param NOT_EXPANDABLE '$hi' (example)
 */
enum e_tokens
{
	D_QUOTE = 34,
	DOLAR = 36,
	S_QUOTE = 39,
	S_COLON = 59,
	I_REDIRECT = 60,
	O_REDIRECT = 62,
	B_SLASH = 92,
	PIPE = 124,
	COMMAND = 666,
	APP_O_REDIRECT = 667,
	DELIMITER = 668,
	NOT_EXPANDABLE = 669,
	EXPANDABLE = 670,
};

t_test		*global(void);

/**
 * @brief manipulate signals (ctrl c, ctrl \) in main function
 * 
 */
void		signal_main(void);

/**
 * @brief start the prompt and REPL
 * 
 */
void		minishell(t_table **tab, char **envp);

/**
 * @brief Under construction at lexer.c
 * 
 * @param tks 
 * @param str 
 */
void		lexer(t_tokens **tks, char **str, t_table **tab, char **envp);

/**
 * @brief under construction at parser.c
 * 
 * @param tks 
 * @param tab 
 */
void		parser(t_tokens **tks, t_table *tab, char **envp);

/**
 * @brief init variables next and envp of the table node
 * 
 * @param tab t table struct to be initialized
 */
void		simple_init(t_table *tab);

void		check_heredoc(void);

/* ---------------------------------------------------------------------*\
|	handle_spaces.c														 |
\* ---------------------------------------------------------------------*/
void		clean_space(char *str);
void		add_space(char **str);
void		get_path(char **envp, t_table *p, int i);

/* ---------------------------------------------------------------------*\
|	handle lists														 |
\* ---------------------------------------------------------------------*/
void		ft_lstfoward_free_t(t_tokens **lst);
void		ft_lstadd_back_t(t_tokens **lst, t_tokens *new);
t_tokens	*ft_lstnew_t(char *str);
void		ft_lstclear_t(t_table **tab);

/* ---------------------------------------------------------------------*\
|	t_table lists														 |
\* ---------------------------------------------------------------------*/
int			ft_lstsize_tab(t_table *lst);

/* ---------------------------------------------------------------------*\
|	executor														 |
\* ---------------------------------------------------------------------*/
void		wait_processes(t_exec *exec);
void		initialize_pipes(t_exec *exec);
void		alloc_resources(t_exec *exec);
void		initialize_files(t_table **tab);
void		close_pipes(t_exec *exec);
void		clean_alloc(t_exec *exec);
void		check_infile(t_table **tab, t_exec *exec);
void		check_outfile(t_table **tab, t_exec *exec);
void		executor(t_table **tab, char **envp);

void		handle_sigint(int sig);
void		handle_sigint_heredoc(int sing);

void		heredoc_caller(t_tokens **tks, t_table **tab, char **envp);
/* ---------------------------------------------------------------------*\
|	builtin														 |
\* ---------------------------------------------------------------------*/
void		is_built_in(t_table **tab, t_exec *exec, char **envp);
void		echo(t_table **tab, t_exec *exec);
void		cd(t_table **tab, t_exec *exec, char **envp);
void		pwd(t_table **tab, t_exec *exec);
void		built_in_error(t_exec *exec, char *cmd);

#endif
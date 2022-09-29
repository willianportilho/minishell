/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 23:11:52 by wportilh          #+#    #+#             */
/*   Updated: 2022/09/29 18:28:21 by wportilh         ###   ########.fr       */
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
# define TEMP_SHILD 2
# define TEMP_QUOT	3
# define HDERRO	"bash: warning: here-document delimited by end-of-file"
# define SYNTXERR "bash: syntax error near unexpected token `"

typedef struct s_utils
{
	char	*str;
	char	*tmp;
	char	*aux;
	int		i;
	int		size;
	int		start;
}			t_utils;

typedef struct s_exec
{
	int				cpin;
	int				cpout;
	int				amount_cmd;
	int				amount_cmd_cp;
	int				**pipes;
	int				*pid;
	int				exit;
	int				check;
	int				pos;
	int				i;
	int				ind;
	int				*p;
}					t_exec;

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

typedef struct s_st
{
	t_bool	test;
	t_bool	heredoc;
	t_bool	control;
	int		fd_global;
	char	**envp;
	int		exit;
	t_table	*tabble;
}			t_test;

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
 * @param QUERY ?
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
	QUERY = 63,
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
void		minishell(t_table **tab);

/**
 * @brief Under construction at lexer.c
 * 
 * @param tks 
 * @param str 
 */
void		lexer(t_tokens **tks, char **str, t_table **tab);

/**
 * @brief under construction at parser.c
 * 
 * @param tks 
 * @param tab 
 */
void		parser(t_tokens **tks, t_table *tab);

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
void		get_path(t_table *p, int i);

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
void		initialize_variables(t_exec *exec, t_table **aux);
void		initialize_pipes(t_exec *exec);
void		alloc_resources(t_exec *exec);
void		initialize_files(t_table **tab);
void		close_pipes(t_exec *exec);
void		clean_alloc(t_exec *exec);
void		clean_alloc_parent(t_exec *exec);
void		check_infile(t_table **tab, t_exec *exec);
void		check_outfile(t_table **tab, t_exec *exec);
void		cmd_error(t_table **tab, t_exec *exec);
void		executor(t_table **tab);

void		handle_sigint(int sig);
void		handle_sigint_heredoc(int sing);

void		heredoc_caller(t_tokens **tks, t_table **tab);

/* ---------------------------------------------------------------------*\
|	builtin														 |
\* ---------------------------------------------------------------------*/
void		is_built_in(t_table **tab, t_exec *exec);
int			built_in_cmd(char *cmd);
int			check_characters(char *cmd);
char		**array_remove_export(int i);
int			echo(t_table **tab);
int			cd(t_table **tab, t_exec *exec);
int			pwd(t_table **tab, t_exec *exec);
int			exportation(t_table **tab);
int			unset(t_table **tab);
int			env(t_table **tab);
int			exit_builtin(t_table **tab);
int			built_in_cd_error(t_table **tab, t_exec *exec);
int			built_in_pwd_error(t_exec *exec);
int			built_in_identifier_error(char *cmd_name, char *cmd);
void		perror_message(char *msg);

int			clean_exit(char *free_me);
void		expand(t_tokens **tks);
char		*simple_expander(char *variable);
void		hard_init(char **envp);
void		init_new_tab(t_table *tab);
int			msg_n_exit_function(char *msg, int (*f)(char *), char *fr);
void		free_tab(t_table *tab);
void		next_n_free_tab(t_table *tab);
t_test		*global(void);
void		clear_tokens_lst(t_tokens **lst);
void		pre_reset(void);
void		tkn_error(t_tokens **tks);

#endif
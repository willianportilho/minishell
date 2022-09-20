/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wportilh <wportilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 00:38:56 by wportilh          #+#    #+#             */
/*   Updated: 2022/09/20 22:56:50 by wportilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# define BUFFER_SIZE 1024

int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_isprint(int c);
size_t		ft_strlen(const char *s);
void		*ft_memset(void *s, int c, size_t n);
void		ft_bzero(void *s, size_t n);
void		*ft_memcpy(void *dest, const void *src, size_t n);
void		*ft_memmove(void *dest, const void *src, size_t n);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
size_t		ft_strlcat(char *dst, const char *src, size_t size);
int			ft_toupper(int c);
int			ft_tolower(int c);
char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *s, int c);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_strcmp(char *s1, char *s2);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
char		*ft_strnstr(const char *s1, const char *s2, size_t len);
int			ft_atoi(const char *nptr);
long		ft_atol(const char *nptr);
void		*ft_calloc(size_t nmemb, size_t size);
char		*ft_strdup(const char *s);

char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strtrim(char const *s1, char const *set);
char		**ft_split(char const *s, char c);
char		*ft_itoa(int n);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void		ft_striteri(char *s, void (*f)(unsigned int, char*));
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

t_list		*ft_lstlast(t_list *lst);
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_list		*ft_lstnew(void *content);
int			ft_lstsize(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstadd_front(t_list **lst, t_list *new);
void		ft_lstclear(t_list **lst, void (*del)(void*));
void		ft_lstdelone(t_list *lst, void (*del)(void*));
void		ft_lstiter(t_list *lst, void (*f)(void *));

char		*get_next_line(int fd);
char		*cut_act(char *actual);
char		*line_to_send(char *actual);
char		*ft_strjoin_alt(char *s1, char *s2);
int			check_break(char *actual);

/**
 * @brief create a new string wich is the copy of the given str
 * but insert a new char in the defined index. Before the return,
 * this function will free the str pointer.
 * 
 * @param str str to be copied
 * @param chr new char to be added
 * @param index index to insert the new char
 * @return char* the new string
 */
char		*ft_str_insert_free(char *str, char chr, int index);

/**
 * @brief Check if the str_1 and str_2 have the same content and size.
 * 
 * @param str_1 first string
 * @param str_2 string to compare with the first one
 * @return int 1 if equals, 0 if different.
 */
int			ft_str_is_equal(char *str_1, char *str_2);

/**
<<<<<<< HEAD
 * @brief Cleans an interger array
 * 
 * @param array address of the integer array
 */
void		ft_free_int_array(int ***array);

/**
 * @brief Cleans an interger array
 * 
 * @param array address of the vector
 */
void		ft_free_vector(int **array);

/**
 * @brief strjoin that frees the first argment (s1)
 * 
 * @param s1 argment that will be freed
 * @param s2 
 * @return char* new string result of concat of s1 n s2
 */
char		*ft_strjoin_free(char *s1, char const *s2);

/**
 * @brief Free an entire array (index and base)
 * 
 * @param array array to be freed
 */
void		ft_free_array(char **array);

/**
 * @brief same as ft_split but frees the s param
 * 
 * @param s param to be freed
 * @param c 
 * @return char** 
 */
char		**ft_split_free(char *s, char c);

/**
 * @brief same as ft_strtrim but frees the s param
 * 
 * @param s1 param to be freed
 * @param set 
 * @return char* 
 */
char		*ft_strtrim_free(char *s1, char const *set);

/**
 * @brief Iterates through some string address and swap the
 * indicated old character by the new one
 * 
 * @param str pointer to a string
 * @param old character of the string to be switched
 * @param new character to be added
 */
void		ft_str_swap_chr(char **str, char old, char new);

/**
 * @brief Print an msg to a given fd and give an erro return
 * 
 * @param msg Msg to be printed
 * @param erro Erro to be returned
 * @param fd FD where msg will be printed
 * @return int the return can be used as exit_status, as boolean,
 * signal trigger and others
 */
int			ft_msg_er(char *msg, int erro, int fd);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trkapous <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 11:55:11 by trkapous          #+#    #+#             */
/*   Updated: 2018/03/20 23:33:14 by tris             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
 #define LIBFT_H

#include <stdio.h>
#include <unistd.h>
#include <strings.h>
#include <stdlib.h>
#include <string.h>

#ifndef S_LIST
# define S_LIST
typedef struct		s_lst
{
	void			*content;
	size_t			content_size;
	struct s_lst	*next;
}					t_lst;
#endif


/*
 * optionnelles : affichier tableau
 */
int		get_next_line(int const fd, char **line);

t_lst	*ft_lstnew(void const *content, size_t content_size);
void	ft_lstdel(t_lst **alst, void (*del)(void *, size_t));
void	ft_lstdelone(t_lst **alst, void (*del)(void *, size_t));
void	ft_lstiter(t_lst *lst, void (*f)(t_lst *elem));
void	ft_lstadd(t_lst **alst, t_lst *link);
void	ft_lstaddlink(t_lst **start, void *content, size_t content_size);
t_lst	*ft_lstmap(t_lst *lst, t_lst * (*f)(t_lst *elem));

void	ft_putstrtab(char **str);
void	ft_putstrtab_delim(char **str, char delim);
int		ft_intlen(int n);

void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_putnbr(int nb);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *str, int fd);
void	ft_putnbr_fd(int nb, int fd);
void	ft_putendl(char const *s);
void	ft_putendl_fd(char const *s, int fd);

int		ft_isdigit(int c);
int 	ft_isalpha(int c);
int		ft_isascii(int n);
int		ft_isalnum(int c);
int		ft_isprint (int c);
int		ft_isblank (int c);
int		ft_isallblank (int c);

size_t	ft_strlen(const char *str);
int		ft_strcmp(const char *s1, const char *s2);

int		ft_tolower(int c);
int		ft_toupper(int c);

char    *ft_strnew(size_t size);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strcpy(char *dest, const char *src);
char	*ft_strncpy(char *dest, const char *src, size_t n);
char	*ft_strccpy(char *dst, const char *src, char c);
char	*ft_strdup(const char *s);
char	*ft_strcdup(const char *s, char c);
char	*ft_strndup(const char *s, size_t n);
char	*ft_strstr(const char *s1, const char *s2);
char	*ft_strnstr(const char *s1, const char *s2, size_t n);
char	*ft_strcat(char *dest, const char *src);
size_t	ft_strlcat(char *s1, const char *s2, size_t n);
char	*ft_strncat(char *dest, const char *src, size_t n);
char	*ft_strchr(const char *s, int c);
int		ft_strchr_pos(const char *s, char c);
char 	*ft_strrchr(const char *s, int c);
char	*ft_strtrim(char const *s);
char	*ft_strlinetrim(char const *s);
int		ft_strequ(char const *s1, char const *s2);
int		ft_strnequ(char const *s1, char const *s2, size_t n);
char	*ft_strmap(char const *s, char (*f)(char));
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strnjoin(char const *s1, char const *s2, int n);
char	*ft_strnjoin_free(char const *s1, char const *s2, int n);
void	ft_striter(char *s, void (*f)(char *));
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
void	ft_strdel(char **as);
void	ft_strclr(char *s);

void	ft_bzero(void *s, size_t n);

char	*ft_strsub(char const *s, unsigned int start, size_t len);
char	**ft_strsplit(char const *s, char c);

char	*ft_itoa(int n);
int		ft_atoi(const char *str);

char	**ft_tabrealloc(char **tab, size_t n, size_t m);
void	*ft_memset(void *s, int c, size_t n);
void	*ft_memalloc(size_t size);
void	*ft_zeromemalloc(size_t size);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memccpy(void *dest, const void *src, int c, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	ft_memdel(void **ap);
void	ft_swap(int *a, int *b);

int		ft_sqrt(int n);
void	ft_x_title(char *str);

#endif

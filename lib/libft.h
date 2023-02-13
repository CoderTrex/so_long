/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunjeong <eunjeong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 19:07:30 by marvin            #+#    #+#             */
/*   Updated: 2022/07/27 11:29:32 by eunjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

#ifdef _WIN32
    #include <io.h>
#else
    #include <unistd.h>
#endif
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

t_list				*ft_lstnew(void *content);
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *), \
						void (*del)(void *));
t_list				*ft_lstlast(t_list *lst);

size_t				ft_strlcat(char *dst, const char *src, size_t size);
size_t				ft_strlcpy(char *dest, const char *src, size_t size);
size_t				ft_strlen(const char *str);

int					ft_atoi(const char *the_char);
void				ft_bzero(void *s, size_t n);
void				*ft_calloc(size_t cnt, size_t size);
int					ft_isalnum(int c);
int					ft_isalpha(int a);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *base1, const void *base2, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memset(void *s, int c, size_t n);
char				**ft_split(const char *str, char charset);
char				*ft_strchr(const char *str, int c);
char				*ft_strdup(const char *src);
char				*ft_strjoin(char const *s1, char const *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strrchr(const char *str, int c);
char				*ft_strtrim(const char *s1, const char *set);
char				*ft_substr(char const *s, unsigned int start, size_t len);
int					ft_tolower(int c);
int					ft_toupper(int c);
char				*ft_itoa(int num);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
char				*ft_strnstr(const char *str, const char \
						*to_find, size_t len);
void				ft_lstadd_front(t_list **lst, t_list *new);
void				ft_lstadd_back(t_list **lst, t_list *new);
int					ft_lstsize(t_list *lst);
void				ft_lstdelone(t_list *lst, void (*del)(void*));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
int					ft_printf(const char *format, ...);
int					ft_percent_pf(const char format, va_list info);

/*Get Next Line*/
size_t				ft_gnl_strlen(const char *s);
char				*ft_gnl_strchr(const char *str, int c);
char				*ft_gnl_substr(char const *s, unsigned int base, size_t len);
char				*ft_gnl_strjoin(char *buf, char *s);
char				*ft_gnl_update_str(char *buf);
char				*ft_gnl_return_str(char *buf);
char				*ft_gnl_read_str(int fd, char *buf);
char				*get_next_line(int fd);
/*ft_printf*/
int					ft_pointer_pf(void *p);
int					ft_putptr_pf(size_t nbr);
int					ft_puthex_pf(unsigned int nbr, char *b);
int					ft_putstring_pf(char *info);
int					ft_putchar_pf(int c);
int					ft_putint_pf(long long n);
size_t				ft_strlen_pf(const char *s);

#endif
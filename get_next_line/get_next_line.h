/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eunjeong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 11:55:22 by eunjeong          #+#    #+#             */
/*   Updated: 2022/11/19 11:55:24 by eunjeong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *str, int c);
char	*ft_substr(char const *s, unsigned int base, size_t len);
char	*ft_strjoin(char *buf, char *s);

char	*ft_update_str(char *buf);
char	*ft_return_str(char *buf);
char	*ft_read_str(int fd, char *buf);
char	*get_next_line(int fd);

#endif

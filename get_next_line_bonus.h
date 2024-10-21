/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swenn <swenn@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 20:46:20 by swenn             #+#    #+#             */
/*   Updated: 2024/10/21 10:52:57 by stetrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>

void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memset(void *ptr, unsigned char c, int len);
size_t	ft_strlen(char *str);
char	*ft_strnjoin(char *s1, char *s2, int len);
char	*ft_strchr(char *str, char c);
char	*ft_loop(int fd, int bytes_read, char *backslash, char *str);
char	*get_next_line(int fd);

#endif

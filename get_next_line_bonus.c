/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swenn <swenn@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 20:44:42 by swenn             #+#    #+#             */
/*   Updated: 2024/10/21 11:07:23 by stetrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strnjoin(char *s1, char *s2, int len)
{
	char	*str;
	int		index;

	str = malloc(sizeof(char) * ft_strlen(s1) + len + 1);
	index = 0;
	if (s1)
	{
		while (s1[index])
		{
			str[index] = s1[index];
			index++;
		}
	}
	while (*s2 && len--)
	{
		str[index] = *s2++;
		index++;
	}
	str[index] = '\0';
	free(s1);
	return (str);
}

char	*ft_strchr(char *str, char c)
{
	if (c == '\0')
		return (str + ft_strlen(str));
	while (*str && *str != c)
		str++;
	if (*str == c)
		return (str);
	return (NULL);
}

char	*ft_loop(int fd, int bytes_read, char *backslash, char *str)
{
	static char	buffer[1024][BUFFER_SIZE] = {0};

	bytes_read = 1;
	str = NULL;
	while (1)
	{
		if (!*buffer[fd])
			bytes_read = read(fd, buffer[fd], BUFFER_SIZE);
		if (bytes_read <= 0)
			break ;
		backslash = ft_strchr(buffer[fd], '\n');
		if (!backslash)
		{
			str = ft_strnjoin(str, buffer[fd], BUFFER_SIZE);
			ft_memset(buffer[fd], 0, BUFFER_SIZE);
			continue ;
		}
		str = ft_strnjoin(str, buffer[fd], backslash - buffer[fd] + 1);
		ft_memmove(buffer[fd], backslash + 1, BUFFER_SIZE);
		break ;
	}
	if (bytes_read == -1)
		ft_memset(buffer[fd], 0, BUFFER_SIZE);
	return (str);
}

char	*get_next_line(int fd)
{
	char	*str;
	int		bytes_read;
	char	*backslash;

	bytes_read = 0;
	backslash = NULL;
	str = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = ft_loop(fd, bytes_read, backslash, str);
	return (str);
}

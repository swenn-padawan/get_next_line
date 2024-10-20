/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swenn <swenn@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 20:44:42 by swenn             #+#    #+#             */
/*   Updated: 2024/10/21 01:44:30 by swenn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memset(void *ptr, unsigned char c, int len)
{
	unsigned char	*p;

	p = (unsigned char *)ptr;
	while (len--)
		*p++ = c;
	return (ptr);
}

size_t	ft_strlen(char *str)
{
	char	*s;

	if (!str)
		return (0);
	s = str;
	while (*s)
		s++;
	return (s - str);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*d;
	const char	*s;

	s = src;
	d = dest;
	if (d == s)
		return (d);
	if (d < s)
	{
		while (n--)
			*d++ = *s++;
	}
	else
	{
		while (n--)
			d[n] = s[n];
	}
	return (dest);
}

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

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE] = {0};
	char		*backslash;
	int			bytes_read;
	char		*str;

	str = NULL;
	while (1)
	{
		if (!*buffer)
			bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
			break;
		backslash = ft_strchr(buffer, '\n');
		if (!backslash)
		{
			str = ft_strnjoin(str, buffer, BUFFER_SIZE);
			ft_memset(buffer, 0, BUFFER_SIZE);
			continue ;
		}
		str = ft_strnjoin(str, buffer, backslash - buffer + 1);
		ft_memmove(buffer, backslash + 1, BUFFER_SIZE);
		break ;
	}
	if (bytes_read == -1)
	{
		free(str);
		return (NULL);
	}
	return (str);
}

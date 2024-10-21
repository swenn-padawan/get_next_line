/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swenn <swenn@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 15:26:12 by swenn             #+#    #+#             */
/*   Updated: 2024/10/21 10:51:37 by stetrel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
		while (n-- && *d)
			*d++ = *s++;
	}
	else
	{
		while (n--)
			d[n] = s[n];
	}
	return (dest);
}

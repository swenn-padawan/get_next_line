/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swenn <swenn@42angouleme.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 00:52:40 by swenn             #+#    #+#             */
/*   Updated: 2024/10/21 00:56:17 by swenn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int main()
{
	int fd = open("test.txt", O_RDONLY);
	char *str = get_next_line(fd);
	 printf("%s", str);
	 free(str);
	 str = get_next_line(fd);
	 printf("%s", str);
	 free(str);
	 str = get_next_line(fd);
	 printf("%s", str);
	 free(str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 09:38:45 by aruckenb          #+#    #+#             */
/*   Updated: 2024/04/26 09:44:43 by aruckenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_getc(int fd)
{
	static char	*buf;
	static int	position;
	static int	count;
	int			ch;

	count = 1;
	position = 0;
	buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (buf == NULL)
		return (0);
	if (position >= count)
	{
		count = read(fd, buf, BUFFER_SIZE);
		if (count == -1)
		{
			free(buf);
			buf = NULL;
			return (0);
		}
		position = 0;
	}
	return (count);
}

int	line_count(int fd, char *line)
{
	int		count;
	int		ch;

	count = 1;
	ch = ft_getc(fd);
	/*
	while (ch != '\n')
	{
		write(1, "1", 1);
		if (ch == '\0')
			return (NULL);
		line[count] = ch;
		count++;
		if (count >= BUFFER_SIZE)
			return (0);
	}
	ch = 0;
	line[count++] = '\n';*/
	return (ch);
}

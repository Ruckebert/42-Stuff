/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 10:48:51 by aruckenb          #+#    #+#             */
/*   Updated: 2024/07/24 10:48:52 by aruckenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include "libft/libft.h"
#include "libft/get_next_line.h"

int	get_map()
{
	int		fd;
    int     count = 0;
	char	*line;

    line = NULL;
	fd = open("Map.ber", O_RDWR);
	if (fd == -1)
		return (-1);

	while ((line = get_next_line(fd)) != NULL)
	{
		printf("[%s]\n", line);
        count++;
		free(line);
	}
	close(fd);

    return (count);
}*/
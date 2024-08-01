/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_chec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <aruckenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 14:32:31 by aruckenb          #+#    #+#             */
/*   Updated: 2024/08/01 14:54:48 by aruckenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_map(char *str, t_vars *vars)
{
	int		fd;
	int	 count;
	char	*line;

	count = 0;
	line = NULL;
	if (ft_strnstr(str, "ber", ft_strlen(str)) == NULL)
		exit(write(2, "Error:File not ber\n", 19));
	fd = open(str, O_RDWR);
	if (fd == -1)
		return (-1);
	line = get_next_line(fd, vars);
	if (!line)
		return (close(fd), -1);
	while (line)
	{
		count++;
		free(line);
		line = get_next_line(fd, vars);
		if (!line && vars->error == 1)
			return (printf("HERE"), free(line), close(fd), -1);
	}
	close(fd);
	return (count);
}

void map_checker(t_vars *vars)
{   
	int j;
	size_t i;

	j = 0;
	while (j < vars->map_size - 1)
	{
		i = 0;
		if (j == 0 || j == vars->map_size - 1)
		{
			while (vars->map[j][i++])
			{   
				if (i == ft_strlen(vars->map[j]) - 1)
					break ;
				if (vars->map[j][i] != '1')
					exit_fail(vars);
			}
		}
		else
		{
			if (vars->map[j][0] != '1' || vars->map[j][ft_strlen(vars->map[j]) - 2] != '1')
				exit_fail(vars);
		}
		j++;
	}
} 

void map_checker2(t_vars *vars)
{   
	int j;
	size_t len;

	j = 0;
	len = ft_strlen(vars->map[0]);
	while (j < vars->map_size - 2)
	{
		if (len == ft_strlen(vars->map[j]))
			j++;
		else
			exit_fail(vars);
	}
} 

void map_checker3(t_vars *vars)
{   
	int j;
	int i;
	int player;
	int esc;

	j = 0;
	i = 0;
	player = 0;
	esc = 0;
	while (j++ < vars->map_size - 2)
	{
		i = 0;
		while (vars->map[j][i])
		{
			if (vars->map[j][i] == 'P')
			{
				player++;
				vars->cur_pos1 = j;
				vars->cur_pos2 = i;
			}
			else if (vars->map[j][i] == 'C')
				vars->max_con++;
			else if (vars->map[j][i] == 'E')
				esc++;
			i++;
		}
	}
	if (player != 1 || vars->max_con < 1 || esc != 1)
		exit_fail(vars);
}

void	map_fullchecker(t_vars *vars)
{
	map_checker(vars);
	map_checker2(vars);
	map_checker3(vars);
}

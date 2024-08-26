/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_fun.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <aruckenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 13:38:30 by aruckenb          #+#    #+#             */
/*   Updated: 2024/08/26 16:24:09 by aruckenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_map_char_len_loop(char *line, char **map, int fd, t_vars *vars)
{
	int	i;

	i = 0;
	while (line)
	{
		map[i] = ft_calloc(sizeof(char), ft_strlen(line) + 1);
		if (!map[i])
		{
			while (--i >= 0)
				free(map[i]);
			return (free(map), free(line), get_next_line(-1, NULL),
				close(fd), 0);
		}
		ft_strcpy(map[i], line);
		i++;
		free(line);
		line = get_next_line(fd, vars);
		if (!line && vars->error == 1)
			return (free_array(map), close(fd), 0);
	}
	return (1);
}

char	**get_map_char_len(int map_size, char *str, t_vars *vars)
{
	int		fd;
	char	*line;
	char	**map;

	map = ft_calloc(sizeof(char *), map_size);
	if (!map)
		return (NULL);
	fd = open(str, O_RDWR);
	if (fd == -1)
		return (free(map), NULL);
	line = get_next_line(fd, vars);
	if (!line)
		return (free(map), close(fd), NULL);
	get_map_char_len_loop(line, map, fd, vars);
	free(line);
	close(fd);
	return (map);
}

int	print_map(char **map, t_vars vars)
{
	int	i;
	int	layer;
	int	j;
	int	position;

	j = 0;
	layer = 0;
	while (map[j])
	{
		if (j == vars.map_size)
			break ;
		i = 0;
		position = 0;
		while (map[j][i])
		{
			if (map[j][i] == '1')
				mlx_put_image_to_window(vars.mlx, vars.win,
					vars.images, position, layer);
			position += 36;
			i++;
		}
		j++;
		layer += 36;
	}
	return (0);
}

void	print_character_loop(char **map, int j, int layer, t_vars *vars)
{
	int	position;
	int	i;

	i = 0;
	position = 0;
	while (map[j][i])
	{
		if (map[j][i] == 'P')
		{
			mlx_put_image_to_window(vars->mlx, vars->win, vars->images,
				position, layer);
			vars->chara_x = position;
			vars->chara_y = layer;
			vars->position_1 = j;
			vars->position_2 = i;
		}
		position += 36;
		i++;
	}
}

int	print_character(char **map, t_vars *vars)
{
	int	layer;
	int	j;

	j = 0;
	layer = 0;
	while (map[j])
	{
		if (j == vars->map_size)
			break ;
		print_character_loop(map, j, layer, vars);
		j++;
		layer += 36;
	}
	return (0);
}

int	print_consumable(char **map, t_vars *vars)
{
	int	i;
	int	layer;
	int	j;
	int	position;

	j = 0;
	layer = 0;
	while (map[j])
	{
		if (j == vars->map_size)
			break ;
		i = 0;
		position = 0;
		while (map[j][i])
		{
			if (map[j][i] == 'C')
				mlx_put_image_to_window(vars->mlx, vars->win,
					vars->images, position, layer);
			position += 36;
			i++;
		}
		j++;
		layer += 36;
	}
	return (0);
}

int	print_exit(char **map, t_vars vars)
{
	int	i;
	int	layer;
	int	j;
	int	position;

	j = 0;
	layer = 0;
	while (map[j])
	{
		if (j == vars.map_size)
			break ;
		i = 0;
		position = 0;
		while (map[j][i])
		{
			if (map[j][i] == 'E')
				mlx_put_image_to_window(vars.mlx, vars.win,
					vars.images, position, layer);
			position += 36;
			i++;
		}
		j++;
		layer += 36;
	}
	return (0);
}

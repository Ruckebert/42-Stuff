/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_fun.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 13:38:30 by aruckenb          #+#    #+#             */
/*   Updated: 2024/07/24 13:38:34 by aruckenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char    **get_map_char_len(int map_size)
{
	int		fd;
    int     i;
	char	*line;
    char    **map;

    i = 0;
    map = ft_calloc(sizeof(char *), map_size);
    if (!map)
        return (NULL);
	fd = open("Map.ber", O_RDWR);
	if (fd == -1)
		return (free(map), NULL);
    line = get_next_line(fd);
	while (line)
	{
		map[i] = ft_calloc(sizeof(char), ft_strlen(line) + 1);
        if (!map[i])
        {
            while (i >= 0)
            {
                free(map[i]);
                i--;
            }
            return (close(fd), free(map), NULL);
        }
        ft_strcpy(map[i], line);
        i++;
		free(line);
        line = get_next_line(fd);
	}
	close(fd);
    return (map);
}
int print_map(char **map, t_vars vars)
{
    int i;
    int layer;
    int j;
    int position;

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
                mlx_put_image_to_window(vars.mlx, vars.win, vars.images, position, layer);
            position += 36;
            i++;
        }
        j++;
        layer += 36;
    }
    return (0);
}

int print_character(char **map, t_vars *vars)
{
    int i;
    int layer;
    int j;
    int position;

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
            if (map[j][i] == 'P')
			{
                mlx_put_image_to_window(vars->mlx, vars->win, vars->images, position, layer);
				vars->chara_x = position;
   				vars->chara_y = layer;
                vars->position_1 = j;
                vars->position_2 = i;
			}
			position += 36;
            i++;
        }
        j++;
        layer += 36;
    }
    return (0);
}

int print_consumable(char **map, t_vars *vars)
{
    int i;
    int layer;
    int j;
    int position;

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
            {
                mlx_put_image_to_window(vars->mlx, vars->win, vars->images, position, layer);
                vars->max_con++;
            }
            position += 36;
            i++;
        }
        j++;
        layer += 36;
    }
    return (0);
}

int print_exit(char **map, t_vars vars)
{
    int i;
    int layer;
    int j;
    int position;

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
                mlx_put_image_to_window(vars.mlx, vars.win, vars.images, position, layer);
            position += 36;
            i++;
        }
        j++;
        layer += 36;
    }
    return (0);
}
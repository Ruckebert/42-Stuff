/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill_con.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <aruckenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 14:51:20 by aruckenb          #+#    #+#             */
/*   Updated: 2024/08/01 14:52:12 by aruckenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void consumable(t_vars *vars)
{
    int num;

	num = 0;
    if (vars->map[vars->position_1][vars->position_2] == 'C')
    {
        vars->count++;
        vars->map[vars->position_1][vars->position_2] = '0';
    }
}


void floodfill(t_vars *vars, char **map, int x, int y, int rows, int cols)
{
    if (x < 0 || x >= rows || y < 0 || y >= cols || map[x][y] == '1' || map[x][y] == 'F')
        return ;
    if (map[x][y] == 'C')
        vars->count++;
    else if (map[x][y] == 'E')
    {
        if (vars->count == vars->max_con)
            vars->exit_reachable = 1;
        return ;
    }
    map[x][y] = 'F';
    floodfill(vars, map, x + 1, y, rows, cols);
    floodfill(vars, map, x - 1, y, rows, cols);
    floodfill(vars, map, x, y + 1, rows, cols);
    floodfill(vars, map, x, y - 1, rows, cols);
}

int floodfill_algor(t_vars vars)
{
    char **flood_map;
    int i;
    flood_map = ft_calloc(vars.map_size, sizeof(char *));
    if (!flood_map)
        return (free_array(vars.map), 1);
    i = 0;
    while (i < vars.map_size - 2)
    {
        flood_map[i] = ft_strdup(vars.map[i]);
        if (!flood_map[i])
        {
            while (--i >= 0)
            {
                free(flood_map[i]);
            }
            free(flood_map);
            return (free_array(vars.map), 1);
        }
        i++;
    }
    floodfill(&vars, flood_map, vars.cur_pos1, vars.cur_pos2, vars.map_size - 2, ft_strlen(flood_map[0]));
    if (vars.exit_reachable == 0)
        return (free_array(flood_map), free_array(vars.map), 1);
    free_array(flood_map);
    return (0);
}
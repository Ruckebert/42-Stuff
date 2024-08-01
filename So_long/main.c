/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <aruckenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 13:21:09 by aruckenb          #+#    #+#             */
/*   Updated: 2024/08/01 15:11:37 by aruckenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int player_movement_input(int keycode, t_vars *vars)
{
    consumable(vars);
    if (keycode == 65362 || keycode == 119)
		player_move_up(vars);
    else if (keycode == 65364 || keycode == 115)
		player_move_dowm(vars);
    else if (keycode == 65361 || keycode == 97)
		player_move_left(vars);
    else if (keycode == 65363 || keycode == 100)
		player_move_right(vars);
    return (0);
}

void image_error(t_vars *vars)
{
    mlx_destroy_window(vars->mlx, vars->win);
    free(vars->mlx);
    free_array(vars->map);
    write(2, "Images has failed\n", 18);
}

int image_creation(t_vars *vars)
{
    vars->win = mlx_new_window(vars->mlx, ((ft_strlen(vars->map[0]) - 1) * 36), ((vars->map_size - 1) * 36), "Hello Sperm World!");
    if (!vars->win)
        return (free(vars->mlx), 1);
    vars->images = mlx_xpm_file_to_image(vars->mlx, "Assets/Walls.xpm", &vars->img_width, &vars->img_height);
    if (!vars->images)
        return (image_error(vars), 1);
    print_map(vars->map, *vars);
    mlx_destroy_image(vars->mlx, vars->images);
    vars->images = mlx_xpm_file_to_image(vars->mlx, "Assets/Child.xpm", &vars->img_width, &vars->img_height);
    if (!vars->images)
        return (image_error(vars), 1);
    print_character(vars->map, vars);
    mlx_destroy_image(vars->mlx, vars->images);
    vars->images = mlx_xpm_file_to_image(vars->mlx, "Assets/Egg1.xpm", &vars->img_width, &vars->img_height);
    if (!vars->images)
        return (image_error(vars), 1);
    print_consumable(vars->map, vars);
    mlx_destroy_image(vars->mlx, vars->images);
    vars->images = mlx_xpm_file_to_image(vars->mlx, "Assets/Exit.xpm", &vars->img_width, &vars->img_height);
    if (!vars->images)
        return (image_error(vars), 1);
    print_exit(vars->map, *vars);
    mlx_destroy_image(vars->mlx, vars->images);
    return (0);
}

//Main
int main(int argc, char *argv[])
{
    t_vars  vars;

    ft_bzero(&vars, sizeof(vars));
    if (argc != 2 || argv[1] == NULL)
        return (1);
    vars.map_size = get_map(argv[1], &vars);
    if (vars.map_size == -1)
        return (1);
    vars.map_size++;
    vars.map = get_map_char_len(vars.map_size, argv[1], &vars);
	if (!vars.map)
		return (1);
	map_fullchecker(&vars);
	if (floodfill_algor(vars) == 1)
        return (write(1, "Map_Exit_is_Invaild\n", 20), 1);
    vars.mlx = mlx_init();
    if (!vars.mlx)
        return (1);
    if (image_creation(&vars) == 1)
        return (1);
    mlx_key_hook(vars.win, player_movement_input, &vars);
    mlx_hook(vars.win, 2, 1L<<0, close_win, &vars);
    mlx_hook(vars.win, 17, 0L, close_button, &vars);
    mlx_loop(vars.mlx);
    return (0);
}

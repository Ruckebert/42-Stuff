/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <aruckenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 14:25:33 by aruckenb          #+#    #+#             */
/*   Updated: 2024/08/26 13:57:01 by aruckenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	player_movement(t_vars *vars, int new_x, int new_y)
{
	vars->images = mlx_xpm_file_to_image(vars->mlx, "Assets/tiles.xpm",
			&vars->img_width, &vars->img_height);
	if (!vars->images)
		exit_fail(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->images,
		vars->chara_x, vars->chara_y);
	vars->chara_x = new_x;
	vars->chara_y = new_y;
	mlx_destroy_image(vars->mlx, vars->images);
	vars->images = mlx_xpm_file_to_image(vars->mlx, "Assets/Child.xpm",
			&vars->img_width, &vars->img_height);
	if (!vars->images)
		exit_fail(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->images, new_x, new_y);
	mlx_destroy_image(vars->mlx, vars->images);
	return (0);
}

void	player_move_up(t_vars *vars)
{
	if (vars->map[vars->position_1 - 1][vars->position_2] == 'E' &&
		vars->count != vars->max_con)
		return ;
	if (vars->map[vars->position_1 - 1][vars->position_2] != '1')
	{
		vars->position_1 -= 1;
		vars->move_con++;
		ft_printf("%d\n", vars->move_con);
		consumable(vars);
		player_movement(vars, vars->chara_x, vars->chara_y - 36);
		if (vars->map[vars->position_1][vars->position_2] == 'E' &&
			vars->count == vars->max_con)
			close_button(vars);
	}
}

void	player_move_dowm(t_vars *vars)
{
	if (vars->map[vars->position_1 + 1][vars->position_2] == 'E' &&
		vars->count != vars->max_con)
		return ;
	if (vars->map[vars->position_1 + 1][vars->position_2] != '1')
	{
		vars->position_1 += 1;
		vars->move_con++;
		ft_printf("%d\n", vars->move_con);
		consumable(vars);
		player_movement(vars, vars->chara_x, vars->chara_y + 36);
		if (vars->map[vars->position_1][vars->position_2] == 'E' &&
			vars->count == vars->max_con)
			close_button(vars);
	}
}

void	player_move_left(t_vars *vars)
{
	if (vars->map[vars->position_1][vars->position_2 - 1] == 'E' &&
		vars->count != vars->max_con)
		return ;
	if (vars->map[vars->position_1][vars->position_2 - 1] != '1')
	{
		vars->position_2 -= 1;
		vars->move_con++;
		ft_printf("%d\n", vars->move_con);
		consumable(vars);
		player_movement(vars, vars->chara_x - 36, vars->chara_y);
		if (vars->map[vars->position_1][vars->position_2] == 'E' &&
			vars->count == vars->max_con)
			close_button(vars);
	}
}

void	player_move_right(t_vars *vars)
{
	if (vars->map[vars->position_1][vars->position_2 + 1] == 'E' &&
		vars->count != vars->max_con)
		return ;
	if (vars->map[vars->position_1][vars->position_2 + 1] != '1')
	{
		vars->position_2 += 1;
		vars->move_con++;
		ft_printf("%d\n", vars->move_con);
		consumable(vars);
		player_movement(vars, vars->chara_x + 36, vars->chara_y);
		if (vars->map[vars->position_1][vars->position_2] == 'E' &&
			vars->count == vars->max_con)
			close_button(vars);
	}
}

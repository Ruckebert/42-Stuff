/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <aruckenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 10:48:51 by aruckenb          #+#    #+#             */
/*   Updated: 2024/08/01 15:28:09 by aruckenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_array(char **example)
{
	int	i;

	i = 0;
	if (example)
	{
		while (example[i])
		{
			free(example[i]);
			i++;
		}
		free(example);
	}
}

int close_win(int keycode, t_vars *vars)
{
    if (keycode == 65307)
    {
        mlx_destroy_window(vars->mlx, vars->win);
        free_array(vars->map);
		mlx_destroy_display(vars->mlx);
        free(vars->mlx);
        exit(0);
    }
    return (0);
}

int close_button(t_vars *vars)
{   
    mlx_destroy_window(vars->mlx, vars->win);
    free_array(vars->map);
	mlx_destroy_display(vars->mlx);
    free(vars->mlx);
    exit (0);
}

char	*ft_strcpy(char *dest, char *src)
{
	char	*start;

	start = dest;
	while (*src != '\0')
	{
		*dest = *src;
		src++;
		dest++;
	}
	*dest = *src;
	return (start);
}

void    exit_fail(t_vars *vars)
{
    free_array(vars->map);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	write(2, "Error\n", 6);
    exit(1);
}
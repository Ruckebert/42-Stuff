/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 13:21:09 by aruckenb          #+#    #+#             */
/*   Updated: 2024/06/18 13:21:11 by aruckenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//Utils Function
int close_win(int keycode, t_vars *vars)
{
    if (keycode == 65307)
        mlx_destroy_window(vars->mlx, vars->win);
    return (0);
}

int close_button(t_vars *vars)
{
    mlx_destroy_window(vars->mlx, vars->win);
    return (0);
}

char	*ft_strcpy(char *dest, char *src) //Add this to LIBFT
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


//Function floodfill to check to find each of these three (Player, Con ad exit)
//read maps
/*void map_chcker()
{
    if (y <= 0 || x <= 0) //If statement to check if their moves left
    tab[x, y] = 'F;
    map_checker() // Repeat this process 4 more times with x +- and y +-

    if (tab[x, y] == 'P')
        int player = 1;
    if (tab[x, y] == 'C')
        int consumable++;
    if (tab[x, y] == 'E')
        int exit = 1;
    if (exit = 1 && consumable = total && player = 1)
        return (valid);

    return (invalid);
}*/

//Consumable
void consumable(t_vars *vars)
{
    if (vars->map[vars->position_1][vars->position_2] == 'C')
    {
        vars->count++;
        vars->map[vars->position_1][vars->position_2] = '0';
    }
}

//Players movement will use the function mlx_hook and mlx_loop to update

int player_movement(t_vars *vars, int new_x, int new_y)
{
    vars->images = mlx_xpm_file_to_image(vars->mlx, "Assets/tiles.xpm", &vars->img_width, &vars->img_height);
    if (!vars->images)
        exit(write(2, "Image has Failed", 16));
    mlx_put_image_to_window(vars->mlx, vars->win, vars->images, vars->chara_x, vars->chara_y); 
    vars->chara_x = new_x;
    vars->chara_y = new_y;
    vars->images = mlx_xpm_file_to_image(vars->mlx, "Assets/Vagnia.xpm", &vars->img_width, &vars->img_height);
    if (!vars->images)
        return (printf("Images has failed"));
    mlx_put_image_to_window(vars->mlx, vars->win, vars->images, new_x, new_y); 
    return(0);
}

int player_movement_input(int keycode, t_vars *vars)// You can add the vars map if needed
{
    if(keycode == 65362 || keycode == 119)
    {
        if (vars->map[vars->position_1 - 1][vars->position_2] != '1')
        {
            vars->position_1 -= 1;
            consumable(vars);
            player_movement(vars, vars->chara_x, vars->chara_y - 36);
            if (vars->map[vars->position_1][vars->position_2] == 'E' && vars->count == vars->max_con)
                exit(0);
        }
    }
    else if (keycode == 65364 || keycode == 115)
    {
        if (vars->map[vars->position_1 + 1][vars->position_2] != '1')
        {
            vars->position_1 += 1;
            consumable(vars);
            player_movement(vars, vars->chara_x, vars->chara_y + 36);
            if (vars->map[vars->position_1][vars->position_2] == 'E' && vars->count == vars->max_con)
                exit(0);
        }
    }
    else if (keycode == 65361 || keycode == 97)
    {
        if (vars->map[vars->position_1][vars->position_2 - 1] != '1')
        {
            vars->position_2 -= 1;
            consumable(vars);
            player_movement(vars, vars->chara_x - 36, vars->chara_y);
            if (vars->map[vars->position_1][vars->position_2] == 'E' && vars->count == vars->max_con)
                exit(0);
        }
    }
    else if (keycode == 65363 || keycode == 100)
    {
        if (vars->map[vars->position_1][vars->position_2 + 1] != '1')
        {
            vars->position_2 += 1;
            consumable(vars);
            player_movement(vars, vars->chara_x + 36, vars->chara_y);
            if (vars->map[vars->position_1][vars->position_2] == 'E' && vars->count != vars->max_con)
                exit(0);
        }
    } 
    return (0);
}

//mlx put image to window function puts the xpm 
//mlx_destory_image frees up the image
//mlx_destroy_window
//mlx_destory_display

int	get_map()
{
	int		fd;
    int     count = 0;
	char	*line;

    line = NULL;
	fd = open("Map.ber", O_RDWR);
	if (fd == -1)
		return (-1);
    line = get_next_line(fd);
	while (line)
	{
		printf("[%s]\n", line);
        count++;
		free(line);
        line = get_next_line(fd);
	}
	close(fd);
    return (count);
}

//Main
int main(int argc, char *argv[])
{ //Need to add get_next_line

    t_vars  vars;

    vars.count = 0;
    vars.max_con = 0;

    if (argc != 2 || argv[1] == NULL)
        return (0);

    vars.map_size = get_map();
    vars.map = get_map_char_len(vars.map_size);
    

    vars.mlx = mlx_init();
    if (!vars.mlx)
        return (1);

    //Window Creation
    vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello world!");
    if (!vars.win)
        return (free(vars.mlx), 1);

    //Image Creation
    //Map
    vars.images = mlx_xpm_file_to_image(vars.mlx, "Assets/Walls.xpm", &vars.img_width, &vars.img_height);
    if (!vars.images)
        return (printf("Images has failed"));

    print_map(vars.map, vars);

    //Character
    vars.images = mlx_xpm_file_to_image(vars.mlx, "Assets/Vagnia.xpm", &vars.img_width, &vars.img_height);
    if (!vars.images)
        return (printf("Images has failed"));
    print_character(vars.map, &vars);
    print_exit(vars.map, vars);

    //Con
    vars.images = mlx_xpm_file_to_image(vars.mlx, "Assets/Mushroom.xpm", &vars.img_width, &vars.img_height);
    if (!vars.images)
        return (printf("Images has failed"));
    print_consumable(vars.map, &vars);

    //Hooks
    mlx_key_hook(vars.win, player_movement_input, &vars);
    mlx_hook(vars.win, 2, 1L<<0, close_win, &vars);
    mlx_hook(vars.win, 17, 0L, close_button, &vars);
    mlx_loop(vars.mlx);
    free(vars.mlx);
    return (0);
}

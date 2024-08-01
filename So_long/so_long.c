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
        exit(0);
    }
    return (0);
}

int close_button(t_vars *vars)
{
    mlx_destroy_window(vars->mlx, vars->win);
    free_array(vars->map);
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
    exit(write(2, "Error\n", 6));
}


//Consumable
void consumable(t_vars *vars)
{
    int num = 0;
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
        exit_fail(vars);
    mlx_put_image_to_window(vars->mlx, vars->win, vars->images, vars->chara_x, vars->chara_y); 
    vars->chara_x = new_x;
    vars->chara_y = new_y;
    vars->images = mlx_xpm_file_to_image(vars->mlx, "Assets/Child.xpm", &vars->img_width, &vars->img_height);
    if (!vars->images)
        exit_fail(vars);
    mlx_put_image_to_window(vars->mlx, vars->win, vars->images, new_x, new_y); 
    return(0);
}

int player_movement_input(int keycode, t_vars *vars)
{
    consumable(vars);
    if(keycode == 65362 || keycode == 119)
    {   
        if (vars->map[vars->position_1 - 1][vars->position_2] == 'E' && vars->count != vars->max_con)
            return (0);
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
        if (vars->map[vars->position_1 + 1][vars->position_2] == 'E' && vars->count != vars->max_con)
            return (0);
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
        if (vars->map[vars->position_1][vars->position_2 - 1] == 'E' && vars->count != vars->max_con)
            return (0);
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
        if (vars->map[vars->position_1][vars->position_2 + 1] == 'E' && vars->count != vars->max_con)
            return (0);
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

int	get_map(char *str, t_vars *vars)
{
	int		fd;
    int     count = 0;
	char	*line;

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
		printf("[%s]\n", line);
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
    int j = 0;
    int i = 0;
    while (j < vars->map_size - 1)
    {
        i = 0;
        if (j == 0 || j == vars->map_size - 1)
        {
            while (vars->map[j][i])
            {   
                if (i == ft_strlen(vars->map[j]) - 1)
                    break ;
                if (vars->map[j][i] != '1')
                    exit_fail(vars);
                i++;
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
    int j = 0;
    int len = ft_strlen(vars->map[0]);
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
    int j = 0;
    int i = 0;
    int player = 0;
    int esc = 0;
    while (j < vars->map_size - 2)
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
        j++; 
    }
    if (player != 1 || vars->max_con < 1 || esc != 1)
        exit_fail(vars);
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

//Main
int main(int argc, char *argv[])
{

    t_vars  vars;

    vars.count = 0;
    vars.max_con = 0;
    vars.error = 0;
    vars.exit_reachable = 0;

    if (argc != 2 || argv[1] == NULL)
        return (1);

    vars.map_size = get_map(argv[1], &vars);
    if (vars.map_size == -1)
        return (printf("HERE"), 1);
    vars.map_size++;
    vars.map = get_map_char_len(vars.map_size, argv[1], &vars);
    if (!vars.map)
        return (1);
    map_checker(&vars);
    map_checker2(&vars);
    map_checker3(&vars);

    //Flood_fill
    char **flood_map = ft_calloc(vars.map_size, sizeof(char *));
    if (!flood_map)
        return (free_array(vars.map), 1);

    int i = 0;
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
        return (free_array(flood_map), free_array(vars.map), write(1, "Map_Exit_is_Invaild\n", 20));
    
    free_array(flood_map);
    //Ends here

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
    {
        mlx_destroy_window(vars.mlx, vars.win);
        free(vars.mlx);
        free_array(vars.map);
        return (printf("Images has failed"));
    }
    print_map(vars.map, vars);

    //Character
    vars.images = mlx_xpm_file_to_image(vars.mlx, "Assets/Child.xpm", &vars.img_width, &vars.img_height);
    if (!vars.images)
    {
        mlx_destroy_window(vars.mlx, vars.win);
        free(vars.mlx);
        free_array(vars.map);
        return (printf("Images has failed"));
    }
    print_character(vars.map, &vars);

    //Con
    vars.images = mlx_xpm_file_to_image(vars.mlx, "Assets/Egg1.xpm", &vars.img_width, &vars.img_height);
    if (!vars.images)
    {
        mlx_destroy_window(vars.mlx, vars.win);
        free(vars.mlx);
        free_array(vars.map);
        return (printf("Images has failed"));
    }
    print_consumable(vars.map, &vars);

    //Exit
    vars.images = mlx_xpm_file_to_image(vars.mlx, "Assets/Exit.xpm", &vars.img_width, &vars.img_height);
    if (!vars.images)
    {
        mlx_destroy_window(vars.mlx, vars.win);
        free(vars.mlx);
        free_array(vars.map);
        return (printf("Images has failed"));
    }
    print_exit(vars.map, vars);

    //Hooks
    mlx_key_hook(vars.win, player_movement_input, &vars);
    mlx_hook(vars.win, 2, 1L<<0, close_win, &vars);
    mlx_hook(vars.win, 17, 0L, close_button, &vars);
    mlx_loop(vars.mlx);
    free(vars.mlx);
    // free_array(vars.map);
    return (0);
}

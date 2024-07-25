/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 13:39:55 by aruckenb          #+#    #+#             */
/*   Updated: 2024/07/24 13:39:56 by aruckenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include "libft/libft.h"
#include "libft/get_next_line.h"

//Key Inputs && MLX
#include <mlx.h>
#include <X11/X.h>
#include <X11/keysym.h>

//Structs
typedef struct s_vars 
{
    void *mlx; //MLX pointer
    void *win; //Window pointer

    //Images
    void *images;
    int  img_height;
    int  img_width;

    //Map
    int  map_size;
	char **map;
    
    //Character
    int  chara_x;
    int  chara_y; 
    int  position_1;
    int  position_2;
    int  count;
    int  max_con;

}   t_vars;

//Map Functions
char    **get_map_char_len(int map_size);
int		print_map(char **map, t_vars vars);
int		print_character(char **map, t_vars *vars);
int		print_consumable(char **map, t_vars *vars);
int		print_exit(char **map, t_vars vars);

//Utils
char	*ft_strcpy(char *dest, char *src);
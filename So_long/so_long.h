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

#ifndef  SO_LONG_H
# define SO_LONG_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include "libft/libft.h"

//Buffer for get next_line
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 20000000000
# endif

//Key Inputs && MLX
#include <mlx.h>
#include <X11/X.h>
#include <X11/keysym.h>

//Structs
typedef struct s_vars 
{
    void *mlx; //MLX pointer
    void *win; //Window pointer

    //Get_next_line
    int error;

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

    //Floodfill
    int cur_pos1;
    int cur_pos2;
    int exit_reachable;

}   t_vars;

//Map Functions
char    **get_map_char_len(int map_size, char *str, t_vars *vars);
int		print_map(char **map, t_vars vars);
int		print_character(char **map, t_vars *vars);
int		print_consumable(char **map, t_vars *vars);
int		print_exit(char **map, t_vars vars);

//Utils
char	*ft_strcpy(char *dest, char *src);
void	free_array(char **example);

//Get_next_line
char	*get_next_line(int fd, t_vars *vars);
size_t	ft_strlen1(const char *str);
char	*ft_strchr1(const char *str, int c);
char	*ft_strjoin1(char const *s1, char const *s2);
char	*ft_strdup1(const char *src);

#endif
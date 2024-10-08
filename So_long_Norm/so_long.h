/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <aruckenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 13:39:55 by aruckenb          #+#    #+#             */
/*   Updated: 2024/08/26 16:21:08 by aruckenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft/libft.h"

//Buffer for get next_line
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 20000000000
# endif

//Key Inputs && MLX
# include <mlx.h>
# include <X11/X.h>
# include <X11/keysym.h>

/*Structs*/
typedef struct s_vars
{
	void	*mlx; //MLX pointer
	void	*win; //Window pointer
	int		error;
	void	*images;
	int		img_height;
	int		img_width;
	int		map_size;
	char	**map;
	int		chara_x;
	int		chara_y;
	int		position_1;
	int		position_2;
	int		count;
	int		max_con;
	int		move_con;
	int		cur_pos1;
	int		cur_pos2;
	int		exit_reachable;
	int		player;
	int		esc;
}	t_vars;

/*Map Functions*/
void	map_fullchecker(t_vars *vars);
int		get_map(char *str, t_vars *vars);
char	**get_map_char_len(int map_size, char *str, t_vars *vars);
int		print_map(char **map, t_vars vars);
int		print_character(char **map, t_vars *vars);
int		print_consumable(char **map, t_vars *vars);
int		print_exit(char **map, t_vars vars);

/*Utils*/
char	*ft_strcpy(char *dest, char *src);
void	free_array(char **example);
int		close_win(int keycode, t_vars *vars);
int		close_button(t_vars *vars);
void	exit_fail(t_vars *vars);
int		floodfill_algor(t_vars vars);

/*Get_next_line*/
char	*get_next_line(int fd, t_vars *vars);
size_t	ft_strlen1(const char *str);
char	*ft_strchr1(const char *str, int c);
char	*ft_strjoin1(char const *s1, char const *s2);
char	*ft_strdup1(const char *src);

/*Player Movement*/
void	consumable(t_vars *vars);
void	player_move_up(t_vars *vars);
void	player_move_dowm(t_vars *vars);
void	player_move_left(t_vars *vars);
void	player_move_right(t_vars *vars);

#endif
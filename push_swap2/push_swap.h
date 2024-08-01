/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 15:39:45 by aruckenb          #+#    #+#             */
/*   Updated: 2024/05/22 15:39:48 by aruckenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

/*Functions for Arrays & Moves*/
char	*ft_strcpy(char *dest, char *src);
void	free_array(char **example);
int		length_2d(char **example);
void	swap_first(char **example);
void	swap_double(char **example, char **example2);
void	pa_b(char ***example, char ***example2);
void	ra_b(char ***example, char ***example2);
void	rr(char ***example, char ***example2);
void	rra_b(char ***example, char ***example2);
void	rrr(char ***example, char ***example2);

/*Sorting Functions*/
void	algorthim(char **number, char **stack_b);
void	sort_3(char ***number, char ***stack_b);
int		loop_forward(char **number, int chunk1, int chunk2);
int		loop_back(char **number, int chunk1, int chunk2);
void	first_position(char ***number, char ***stack_b, int placement, int num);
int		stack_organ(char **stack_b);
void	sort_placement(char ***stack_b, char ***number, int size);
void	checker_sort(char ***stack_b);

/*Utils Function*/
void	checker(char **array, char **stack_b);
void	dup_checker(char **argv, int i, int num);
void	argv_checker(char **argv, int num);
int		ft_last(char **str);
void	reverse_free(char **temp_array, int i);
void	top_to_bottom(char ***number, char ***stack_b, int i);
int		lowest_number(char **number);
void	swap(char ***number);

/*Write*/
void	push_write(char ***stack_b, char ***number, int i);

#endif
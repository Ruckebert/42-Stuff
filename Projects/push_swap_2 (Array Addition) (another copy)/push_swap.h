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

#include "libft/libft.h"

#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

//Link Lists should be here
typedef struct s_list
{
    void            *content;
    struct s_list   *next;
}   t_list;

//Link List functions
t_list  *ft_lstlast(t_list *lst);
void    ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
void    ft_lstclear(t_list **lst);
t_list  *ft_lstnew(void	*content);
int     ft_lstsize(t_list *lst);
void	ft_lstdelone(t_list *lst);

//Functions for Arrays
char    *ft_strcpy(char *dest, char *src);
void    free_array(char **example);
int     length_2D(char **example);
void    swap_first(char **example);
void    swap_double(char **example, char **example2);
void    pa_b(char ***example, char ***example2); 
void    ra_b(char ***example); 
void    rr(char ***example, char ***example2); 
void    rra_b(char ***example); //Fin no legs but some unknown errors 
void    rrr(char ***example, char ***example2); //Fin but also some unknown errors

//Sorting Functions
int     sort_3(char **number);
int     loop_forward(char **number, int chunk1, int chunk2);
int     loop_back(char **number, int chunk1, int chunk2);
void    first_position(char **number, int placement, char *temp);
int     stack_organ(char **stack_b);
void    sort_placement(int placement, char ***stack_b);

//Utils Function
int     checker(char **array);
int     ft_last(char **str);

#endif
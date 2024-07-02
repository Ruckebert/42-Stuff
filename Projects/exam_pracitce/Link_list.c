/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Link_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 13:51:58 by aruckenb          #+#    #+#             */
/*   Updated: 2024/06/17 15:10:23 by aruckenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdlib.h>
#include <stdio.h>
#include "ft_list.h"

int ascending(int a, int b)
{
	return (a <= b);
}

void print_list(t_list * head)
{
	t_list * current = head;
	while (current != NULL)
	{
		printf("%d\n", current->data);
		current = current->next;
	}
}

int ft_list_size(t_list *begin_list)
{
	int i = 0;
	
	while(begin_list)
	{
		begin_list = begin_list->next;
		i++;
	}
	return (i);
}

//4th level questions
/*void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	if (begin_list == NULL || *begin_list == NULL)
		return ;

	t_list *temp = *begin_list;	
	
	if ((*cmp)(temp->data,data_red) == 0)
	{
		*begin_list = temp->next;
		free(temp);
		ft_list_remove_if(begin_list, data_ref, cmp);
	}
	else
	{
		temp = *begin_list;
		ft_list_remove_if(&cur->next, data_ref, cmp);
	}
}*/

//Loops through all the elements and executes them with the function
void ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
	while (begin_list)
	{
		(*f)(begin_list->data);
		begin_list = begin_list->next;
	}
}

t_list *sort_list(t_list *lst, int (*cmp)(int, int))
{
	int swap;
	t_list *temp;

	temp = lst;
	while (lst)
	{
		if ((*cmp)(lst->data, lst->next->data) == 0)
		{
			swap = lst->data;
			lst->data = lst->next->data;
			lst->next->data = swap;
			lst = temp; //resets the list by going back to the first element
		}
		else
			lst = lst->next;
	}
	lst = temp;
	return (lst);
}

int main()
{

t_list *head = NULL;
t_list *one = NULL;
t_list *two = NULL;
t_list *three = NULL;

head = malloc(sizeof(t_list));
one = malloc(sizeof(t_list));
two = malloc(sizeof(t_list));
three = malloc(sizeof(t_list));

head->data = 0;
one->data = 5;
two->data = 6;
three->data = 7;

head->next = one;
one->next = two;
two->next = three;
three->next = NULL;

//t_list *val = sort_list(one, ascending);
//printf("1");
print_list(head);
int num  = ft_list_size(head);
printf("num=%d\n", num);

}

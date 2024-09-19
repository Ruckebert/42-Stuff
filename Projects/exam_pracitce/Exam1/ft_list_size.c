/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 16:29:27 by aruckenb          #+#    #+#             */
/*   Updated: 2024/06/10 08:55:03 by aruckenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_list_size(t_list *beign_list)
{
	int i = 0;

	while(begin_list->next)
	{
		begin_list = begin_list->next;
		i++;
	}
	return (i);
}



int ft_list_size(t_list *begin_list)
{
	int i = 0;

	while (begin_lsit->next)
	{
		begin_list = begin_lsit->next;
		i++;
	}
	return (i);
}

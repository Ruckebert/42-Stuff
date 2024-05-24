/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 15:58:30 by aruckenb          #+#    #+#             */
/*   Updated: 2024/04/12 14:23:43 by aruckenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len;
	char	*temp;
	char	*new_string;

	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	new_string = malloc(len * sizeof(char));
	if (new_string == NULL)
		return (0);
	len = 0;
	temp = (char *)s1;
	while (*temp != '\0')
	{
		new_string[len] = *temp;
		len++;
		temp++;
	}
	temp = (char *)s2;
	while (*temp != '\0')
	{
		new_string[len++] = *temp;
		temp++;
	}
	new_string[len] = '\0';
	return (new_string);
}

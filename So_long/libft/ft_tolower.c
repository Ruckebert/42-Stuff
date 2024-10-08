/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 13:07:20 by aruckenb          #+#    #+#             */
/*   Updated: 2024/04/08 12:59:04 by aruckenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int chara)
{
	if ((chara >= 'A') && (chara <= 'Z'))
	{
		chara = chara + 32;
		return (chara);
	}
	else
	{
		return (chara);
	}
}

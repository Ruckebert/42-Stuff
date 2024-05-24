/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 09:19:44 by aruckenb          #+#    #+#             */
/*   Updated: 2024/04/05 13:54:30 by aruckenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strtrim.c"
#include <bsd/string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

char uppercase(char c, unsigned int i)
{
    if (i % 2 == 0)
        return toupper(c);
    else
        return tolower(c);
}

int main()
{
	char *digit = "iieealbertii";
	char *source = "ie";	
	//size_t size = 4;
	//int num = -1201;
	char *a;
	//char *b;
	//char value = ',';

	//a = 0;
	//b = 0;

	a = ft_strtrim(digit, source);
	//b = strdup(digit);

	printf("%s", a);
	//printf("%s", b);

}

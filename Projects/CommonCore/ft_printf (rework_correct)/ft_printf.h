/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 09:24:46 by aruckenb          #+#    #+#             */
/*   Updated: 2024/04/23 14:38:18 by aruckenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>

int	ft_printf(const char *s, ...);
int	ft_pointadd(va_list nex_arg);
int	ft_putchar_print(char c);
int	ft_putnbr_count(long int nb);
int	ft_putnbr_hex(int num, int lower);
int	ft_putnbr_pointhex(intptr_t num);
int	ft_putnbr_unsigned(unsigned int nb);
int	ft_putstr_print(char *s);

#endif

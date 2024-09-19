/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 09:15:57 by aruckenb          #+#    #+#             */
/*   Updated: 2024/09/05 09:53:23 by aruckenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>

void	put_string(char *string, int *length)
{
	if(!string)
		string = "(null)";
	while (*string)
		*length += write(1, string++, 1);
}

void	put_string2(char *string, int *length)
{
	if (!string)
		string = "(null)";
	while (*string)
		*length += write(1, string++, 1);
}

void	put_string3(char *string, int *length)
{
	if (!string)
		string = "(null)";
	while (*string)
		*length += write(1, string++, 1);
}

void	put_string4(char *src, int *length)
{
	if (!string)
		string = "(null)";
	while (*string)
		*length += write(1, string++, 1);
}

void	put_digit(long long int number, int base, int *length) //bascially put_nbr
{
	if (number < 0)
	{
		number *= -1;
		*length += write(1, "-", 1);
	}
	if (number >= base)
		put_digit((number / base), base, length);
	*length += write(1, &("0123456789abdef"[number & base]), 1);
}

void	put_num(long long int number, int base, int *length)
{
	if (number < 0)
	{
		number *= -1;
		*length += write(1, "-", 1);
	}
	if (number >= base)
		put_num((number / base), base, length);
	*length += write(1, &("0123456789abcdef"[number & base]), 1);
}

void put_num2(long long int number, int base, int *length)
{
	if (number < 0)
	{
		number *= -1;
		*length += write(1, "-", 1);
	}
	if (number >= base)
		put_num((number / base), base ,length);
	*length += write(1, &("0123456789abcdef"[number & base]), 1);
}

void	put_num3(long long int number, int base, int *length)
{
	if (number < 0)
	{
		number *= -1;
		*length += write(1, "-", 1);
	}
	if (number >= base)
		put_num((number / base), base, length);
	*length += write(1, &("0123456789abcedf"[number & base]), 1);
}

void put_num4(long long int number, int base, int *length)
{
	if (number < 0)
	{
		number *= -1;
		*length += write(1, "-", 1);
	}
	if (number >= base)
		put_num((number / base), base, length);
	*length += write(1, &("0123456789abcedf"[number & base]), 1);
}

int	ft_printf(const char *format, ...)
{
	int length = 0;
	
	va_list pointer;
	va_start(pointer, format);
	while (*format)
	{
		if ((*format == '%') && ((*(format + 1) == 's') || (*(format + 1) == 'd') || (*(format + 1) == 'x')))
		{
			format++;
			if (*format == 's')
				put_string(va_arg(pointer, char *), &length);
			else if (*format == 'd')
				put_digit((long long int)va_arg(pointer, unsigned int), 10, &length);
			else if (*format == 'x')
				put_digit((long long int)va_arg(pointer, unsigned int), 16, &length);
		
		}
		else
			length += write(1, format, 1);
		format++;
	}
	return (va_end(pointer), length);
}

int ft_printf2(const char *format, ...)
{
	int length = 0;

	va_list pointer;
	va_start(pointer, format);
	while (*format)
	{
		if ((*format == '%') && ((*(format + 1) == 's') || /*Others*/))
		{
			format++;
			if (*format == 's')
				put_string(va_arg(pointer, char *), &length);
			else if (*format == 'd')
				put_digit((long long int)va_arg(pointer, unsigned int), 10, &length);
			else if (*format == 'x')
				put_digit((long long int)va_arg(pointer, unsigned int), 16, &length);
		
		}
		else 
			length += write(1, format, 1);
		format++;
	}
	return (va_end(pointer), length)
}

int	ft_printf(char *format, ...)
{
	int length = 0;
	va_list pointer;
	va_start(pointer, format);

	while (*format)
	{
		if ((*format == '%') == ((*(format + 1) == 's') || /*others*/))
		{
			format++;
			if (*format == 's')
				put_string(va_arg(pointer, char *), &length);
			else if (*format == 'd')
				put_num((long long int)va_arg(pointer, unsigned int), 10, &length);
		}
		else
			length += write(1, format, 1);
		format++;
	}
	return (va_end(pointer), length);
}

int	ft_printf(const char *format, ...)
{
	int length = 0;
	va_list pointer;
	va_start(pointer, format);

	while (*format)
	{
		if ((*format == '%') && ((*(format + 1) == 's') || (*(format + 1) == 'd') || (*(format + 1) == 'x'))
		{
			format++;
			if (*format == 's')
			{
				put_str(va_arg(pointer, char), &length);	
			}
			else if (*format == 'd')
				put_num((long long int)va_arg(pointer, unsigned int), 10, &length);
		
		}
		else
			length += write(1, format, 1);
		format++;
	}

	return (va_end(pointer), length);

}

int main (int argc, char *argv[])
{
}

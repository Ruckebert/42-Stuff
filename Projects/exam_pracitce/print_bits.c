/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruckenb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 09:45:51 by aruckenb          #+#    #+#             */
/*   Updated: 2024/06/13 09:34:07 by aruckenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void print_bits(unsigned char octet)
{
	int i = 8; // 8 because 1 byte is 8 bits
	unsigned char bit = 0;

	while (i--) //Going down each bit
	{
		bit = (octet >> i & 1) + 48; //Moves and checks whether they are the same if they are print it.
		write(1, &bit, 1);
	}
}

void print_bits2(unsigned char octet)
{
	int i = 8;
	unsigned char bit = 0;

	while (i--)
	{
		bit = (octet >> i & 1) + 48
		write(1, &bit, 1);
	}


}

void print_bits3(unsigned char octet)
{
	int i = 8;
	unsigned char bit = 0;
	while (i--)
	{
		bit = (octet >> i & 1) + 48;
		write(1, &bit, 1);
	}
}

unsigned char reverse_bits(unsigned char octet)
{
	int i = 8;// 1 byte for the 8 bits
	unsigned char res = 0;

	while (i--)
	{
		res = (res << 1) | (octet & 1);
		octet = octet >> 1;
	}
	return (res);
}

unsigned char reverse_bits2(unsigned char octet)
{
	int i = 8;
	unsigned char res = 0;
	while (i--)
	{
	
		res = (res << 1) | (octet & 1);
		octet = octet >> 1;
	}

	return (res);
}

unsigned char reverse_bits3(unsigned char octet)
{
	int i = 8;
	unsigned char res = 0;
	while (i--)
	{
		res = (res << 1) | (octet & 1);
		octet = octet >> 1;
	}
	return (res);
}

unsigned char swap_bits(unsigned char octet)
{
	return ((octet >> 4) | (octet << 4))
}

unsigned char swap_bits1(unsigned char octet)
{
	return ((octet >> 4) | (octet << 4))
}

int main()
{
	unsigned char octet = 3;
	print_bits(octet);
}

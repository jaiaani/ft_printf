/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaiane <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 19:45:15 by jaiane            #+#    #+#             */
/*   Updated: 2024/12/03 21:33:07 by jaiane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

int	print_c(int c)
{
	return (write(1, &c, 1));
}

int	print_s(char *str)
{
	int	count;

	count = 0;
	while (str[count])
		count++;
	return (write(1, str, count));
}

static	int	hex_nlen(unsigned long n)
{
	int	count;
	count = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 16;
		count++;
	}
	return (count);
}

int	print_p(void *p)
{
	unsigned long	addr;
	char	hex_char[16] = "0123456789abcdef";
	char	*buffer;
	int	i;
	int	nlen;

	addr = (unsigned long) p;
	nlen = hex_nlen(addr);
	buffer = malloc(sizeof(char) * (nlen + 1));
	if (!buffer)
		return (0);
	i = nlen;
	while (addr > 0)
	{
		buffer[i] = hex_char[addr % 16];
		addr /= 16;
		i--;
	}
	write(1, "0x", 2);
	write(1, buffer, 16);
	free(buffer);
	return (nlen + 2);
}

int	print_d(int d)
{
	
}

#include <stdio.h>

int	main(void)
{
	int	a;
	int	*b;
	int	count;

	a = 8;
	b = &a;
	count = printf("%p", b);
	printf("\noriginal: %d\n", count);
	count = print_p(b);
	printf("\nmine: %d\n", count);

	return (0);
}

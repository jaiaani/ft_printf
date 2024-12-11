/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaiane <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 00:34:32 by jaiane            #+#    #+#             */
/*   Updated: 2024/12/10 21:34:21 by jaiane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*str;

	str = (unsigned char *)s;
	while (n-- > 0)
		*str++ = '\0';
}

void	*ft_calloc(size_t nelem, size_t elsize)
{
	size_t	tsize;
	void	*space;

	if (nelem == 0 || elsize == 0)
		return (malloc(0));
	tsize = nelem * elsize;
	if (tsize / elsize != nelem)
		return (NULL);
	space = malloc(tsize);
	if (!space)
		return (NULL);
	ft_bzero(space, tsize);
	return (space);
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

int	print_pointer(void *p)
{
	char	*hex_chars;
	unsigned long	addr;
	char	*buffer;
	int	i;
	int	nlen;

	hex_chars = "0123456789abcdef";
	addr = (unsigned long) p;
	nlen = hex_nlen(addr);
	buffer = calloc(sizeof(char),  (nlen + 1));
	if (!buffer)
		return (0);
	i = nlen;
	while (addr > 0)
	{
		buffer[i] = hex_chars[addr % 16];
		addr /= 16;
		i--;
	}
	write(1, "0x", 2);
	write(1, buffer, nlen);
	free(buffer);
	return (nlen + 2);
}

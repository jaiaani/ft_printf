/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaiane <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 00:34:32 by jaiane            #+#    #+#             */
/*   Updated: 2025/01/03 20:01:06 by jados-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	print_ulong_hex(unsigned long long n)
{
	int		count;
	char	*hex_char;

	hex_char = "0123456789abcdef";
	if (n < 16)
		return (print_char(hex_char[n]));
	else
	{
		count = print_ulong_hex(n / 16);
		return (count + print_ulong_hex(n % 16));
	}
}

int	print_pointer(void *p)
{
	unsigned long long	addr;
	int					count;

	addr = (unsigned long long) p;
	if (addr == 0)
		return (write(1, "(nil)", 5));
	count = write(1, "0x", 2);
	count += print_ulong_hex(addr);
	return (count);
}

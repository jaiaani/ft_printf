/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaiane <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 22:40:05 by jaiane            #+#    #+#             */
/*   Updated: 2024/12/11 19:00:19 by jaiane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	print_number_base(long long n, int base, int upp)
{
	int	count;
	char	*hex_char;

	if (upp)
		hex_char = "0123456789ABCDEF";
	else
		hex_char = "0123456789abcdef";
	if (n < 0)
	{
		write(1, "-", 1);
		return print_number_base(-n, base, upp) + 1;
	}
	else if (n < base)
		return (print_char(hex_char[n]));
	else
	{
		count = print_number_base(n / base, base, upp);
		return count + print_number_base(n % base, base, upp);
	}
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jados-sa <jados-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 19:44:59 by jados-sa          #+#    #+#             */
/*   Updated: 2025/01/03 19:53:59 by jados-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	print_number_base(long n, int base, int upp)
{
	int		count;
	char	*hex_char;

	if (upp)
		hex_char = "0123456789ABCDEF";
	else
		hex_char = "0123456789abcdef";
	if (n < 0)
	{
		write(1, "-", 1);
		return (print_number_base(-n, base, upp) + 1);
	}
	else if (n < base)
		return (print_char(hex_char[n]));
	else
	{
		count = print_number_base(n / base, base, upp);
		return (count + print_number_base(n % base, base, upp));
	}
}

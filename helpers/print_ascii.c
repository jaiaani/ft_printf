/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ascii.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaiane <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 23:08:28 by jaiane            #+#    #+#             */
/*   Updated: 2024/12/10 21:28:28 by jaiane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	print_char(char c)
{
	return (write(1, &c, 1));
}

unsigned int	print_str(const char *str)
{
	unsigned int	count;

	count = 0;
	while (str[count])
		count++;
	return (write(1, str, count));
}


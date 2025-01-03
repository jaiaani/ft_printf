/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ascii.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jados-sa <jados-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 19:42:21 by jados-sa          #+#    #+#             */
/*   Updated: 2025/01/03 19:44:11 by jados-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	print_char(unsigned char c)
{
	return (write(1, &c, 1));
}

unsigned int	print_str(const char *str)
{
	unsigned int	count;

	if (!str)
		return (write(1, "(null)", 6));
	count = 0;
	while (str[count])
		count++;
	return (write(1, str, count));
}

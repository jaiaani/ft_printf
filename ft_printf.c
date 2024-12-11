/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaiane <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 23:15:31 by jaiane            #+#    #+#             */
/*   Updated: 2024/12/11 19:01:44 by jaiane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int     print_format(char type, va_list ap)
{
        int     count;

        count = 0;
        if (type == 'c')
                count += print_char(va_arg(ap, int));
	else if (type == 's')
		count += print_str(va_arg(ap, char *));
	else if (type == 'p')
		count += print_pointer(va_arg(ap, unsigned long long));
        else if (type == 'd' || type == 'i')
                count += print_number_base((long long)va_arg(ap, int), 10, 0);
	else if	(type == 'u')
		count += print_number_base((long long)va_arg(ap, unsigned int), 10, 0);
        else if (type == 'x')
                count += print_number_base((long long)va_arg(ap, unsigned int), 16, 0);
	else if (type == 'X')
		count += print_number_base((long long)va_arg(ap, unsigned int), 16, 1);
	else if (type == '%')
		count += write(1, "%", 1);
        else
                count += write(1, &type, 1);
        return (count);
}

int     ft_printf(const char *format, ...)
{
        va_list ap;
        int     count;

        va_start(ap, format);
        count = 0;
        while (*format)
        {
                if (*format == '%')
                        count += print_format(*(++format), ap);
                else
                        count += write(1, format, 1);
                ++format;
        }
        va_end(ap);
        return (count);
}


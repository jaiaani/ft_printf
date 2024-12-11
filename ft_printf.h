/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaiane <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 23:12:04 by jaiane            #+#    #+#             */
/*   Updated: 2024/12/05 01:36:43 by jaiane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int	print_char(char c);
unsigned int	print_str(const char *str);
int	print_number_base(long n, int base, int upp);
int	print_pointer(void *p);
int	ft_printf(const char *format, ...);

#endif //LIBFTPRINTF_H

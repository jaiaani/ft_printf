/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jados-sa <jados-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 19:27:01 by jados-sa          #+#    #+#             */
/*   Updated: 2025/01/03 19:40:09 by jados-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int				print_char(unsigned char c);
int				print_number_base(long n, int base, int upp);
int				print_pointer(void *p);
int				ft_printf(const char *format, ...);
unsigned int	print_str(const char *str);

#endif

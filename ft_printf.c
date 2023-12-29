/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbarron <qbarron@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 14:14:36 by qbarron           #+#    #+#             */
/*   Updated: 2023/11/01 14:14:36 by qbarron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <unistd.h>

int	ft_format_name(va_list args, const char *format)
{
	int	i;

	i = 0;
	if (*format == 'c')
		i += print_char(va_arg(args, int));
	else if (*format == 's')
		i += print_string(va_arg(args, char *));
	else if (*format == 'p')
		i += print_ptr((void *)va_arg(args, unsigned long long int));
	else if (*format == 'd' || *format == 'i')
		i += ft_printnbr(va_arg(args, int));
	else if (*format == 'u')
		i += print_unsigned(va_arg(args, unsigned int));
	else if (*format == 'x')
		i += print_hex(va_arg(args, unsigned int), false);
	else if (*format == 'X')
		i += print_hex(va_arg(args, unsigned int), true);
	else if (*format == '%')
		i += print_char('%');
	return (i);
}

int	ft_printf(char const *str, ...)
{
	int		i;
	int		print_length;
	va_list	args;

	i = 0;
	print_length = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			print_length += ft_format_name(args, &str[i + 1]);
			i++;
		}
		else
			print_length += print_char(str[i]);
		i++;
	}
	va_end(args);
	return (print_length);
}

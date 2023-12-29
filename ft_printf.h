/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbarron <qbarron@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 14:43:16 by qbarron           #+#    #+#             */
/*   Updated: 2023/12/04 14:43:16 by qbarron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <stdbool.h>
# include <stdlib.h>

int		ft_format_name(va_list args, const char *format);
int		ft_printf(char const *str, ...);
int		print_ptr(void *ptr);
int		print_unsigned(unsigned int nb);
int		print_char(int c);
int		print_hex(unsigned int nb, bool majuscules);
int		print_zero(unsigned int nb, bool majuscules);
int		ft_printnbr(int n);
int		print_string(char *str);

size_t	print_digit_ptr(unsigned long long nb);
size_t	print_digits_hexa(unsigned int nb);
void	put_ptr(unsigned long long ptr);

#endif

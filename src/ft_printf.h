/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbarron <qbarron@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 14:43:16 by qbarron           #+#    #+#             */
/*   Updated: 2023/12/29 10:48:26 by qbarron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_format_name(va_list args, const char *format);
int		ft_printf(char const *str, ...);
int		print_ptr(void *ptr);
int		print_unsigned(unsigned int nb);
int		print_char(int c);
int		print_hex(unsigned int nb, bool majuscules);
int		print_zero(unsigned int nb, bool majuscules);
int		ft_printnbr(int n);
int		print_string(char *str);
int		ft_strlen(const char *str);
int		digits(int n);

char	*ft_strdup(const char *str);
char	*ft_itoa(int n);

size_t	print_digit_ptr(unsigned long long nb);
size_t	print_digits_hexa(unsigned int nb);
void	put_ptr(unsigned long long ptr);
void	sign_and_convert(int n, int i, char *dup, int len);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbarron <qbarron@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:59:04 by qbarron           #+#    #+#             */
/*   Updated: 2023/12/29 09:36:05 by qbarron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stddef.h>

void	ft_putchar(char c);

size_t	print_digit_ptr(unsigned long long nb)
{
	size_t	digits;

	digits = 0;
	if (nb == 0)
		return (1);
	while (nb != 0)
	{
		digits += 1;
		nb /= 16;
	}
	return (digits);
}

void	put_ptr(unsigned long long ptr)
{
	char	*digits;

	digits = "0123456789abcdef";
	if (ptr >= 16)
		put_ptr(ptr / 16);
	ft_putchar(digits[ptr % 16]);
}

int	print_ptr(void *ptr)
{
	if (ptr == NULL)
		return (write(1, "(nil)", 5));
	write(1, "0x", 2);
	put_ptr((unsigned long long)ptr);
	return (print_digit_ptr((unsigned long long int)ptr) + 2);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

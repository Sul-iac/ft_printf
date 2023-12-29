/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbarron <qbarron@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 18:37:29 by qbarron           #+#    #+#             */
/*   Updated: 2023/12/29 10:48:40 by qbarron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	print_digits_hexa(unsigned int nb)
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

int	print_hex(unsigned int nb, bool majuscules)
{
	char	*upper_digits;
	char	*lower_digits;
	int		count;

	upper_digits = "0123456789ABCDEF";
	lower_digits = "0123456789abcdef";
	count = 0;
	if (nb >= 16)
		count += print_hex((nb / 16), majuscules);
	if (majuscules == true)
		write(1, &upper_digits[nb % 16], 1);
	else if (majuscules == false)
		write(1, &lower_digits[nb % 16], 1);
	return (count + 1);
}

int	print_zero(unsigned int nb, bool majuscules)
{
	if (nb == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	else
		return (print_hex(nb, majuscules));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbarron <qbarron@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 16:23:46 by qbarron           #+#    #+#             */
/*   Updated: 2023/12/28 16:23:46 by qbarron          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strdup(const char *str);
int		ft_strlen(const char *str);

int	digits(int n)
{
	size_t	i;

	i = 1;
	if (n < 0)
	{
		i++;
		n *= -1;
	}
	while (n > 9)
	{
		n /= 10;
		i++;
	}
	return (i);
}

void	sign_and_convert(int n, int i, char *dup, int len)
{
	if (n < 0)
	{
		n *= -1;
		dup[i++] = '-';
	}
	dup[len] = '\0';
	while (n)
	{
		dup[--len] = n % 10 + '0';
		n = n / 10;
	}
}

char	*ft_itoa(int n)
{
	int		i;
	int		len;
	char	*dup;

	i = 0;
	len = digits(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	dup = (char *)malloc(sizeof(char) * len + 1);
	if (dup == NULL)
		return (NULL);
	sign_and_convert(n, i, dup, len);
	return (dup);
}

char	*ft_strdup(const char *str)
{
	int		i;
	int		len;
	char	*dup;

	i = 0;
	len = ft_strlen(str);
	dup = (char *)malloc(sizeof(char) * len + 1);
	if (dup == NULL)
	{
		dup = (char *)malloc(1);
		if (dup == NULL)
			return (NULL);
		dup[0] = '\0';
		return (dup);
	}
	while (str[i] != '\0')
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

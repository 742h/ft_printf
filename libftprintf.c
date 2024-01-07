/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hassaleh <hassaleh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 21:14:09 by hassaleh          #+#    #+#             */
/*   Updated: 2024/01/07 21:55:27 by hassaleh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write (1, &c, 1));
}

int	ft_putnbr(long long n)
{
	int	counter;
	int	isneg;

	counter = 0;
	isneg = 0;
	if (n == -2147483648)
	{
		counter += ft_putchar ('-') + ft_putchar ('2');
		n = 147483648;
	}
	if (n < 0)
	{
		counter += ft_putchar ('-');
		n = n * -1;
		isneg = 1;
	}
	if (n < 10)
	{
		n = n + 48;
		counter += ft_putchar(n);
		return (1 + isneg);
	}
	counter += ft_putnbr (n / 10);
	counter += ft_putnbr (n % 10);
	return (counter);
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (ft_putstr("(null)"));
	while (s[i])
	{
		write (1, &s[i], 1);
		i++;
	}
	return (i);
}

unsigned int	put_udecimal(unsigned long n)
{
	unsigned long	counter;

	counter = 0;
	if (n > 9)
		counter += ft_putnbr (n / 10);
	counter += ft_putnbr (n % 10);
	return (counter);
}

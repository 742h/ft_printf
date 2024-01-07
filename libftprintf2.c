/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hassaleh <hassaleh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 21:13:50 by hassaleh          #+#    #+#             */
/*   Updated: 2024/01/04 19:23:03 by hassaleh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	hexdecimal(unsigned long long n)
{
	char				*base;
	unsigned long long	counter;

	base = "0123456789abcdef";
	counter = 0;
	if (n >= 16)
		counter += hexdecimal (n / 16);
	counter += ft_putchar (base[n % 16]);
	return (counter);
}

int	capital_hexdecimal(unsigned long long n)
{
	char				*base;
	unsigned long long	counter;

	base = "0123456789ABCDEF";
	counter = 0;
	if (n >= 16)
		counter += capital_hexdecimal (n / 16);
	counter += ft_putchar (base[n % 16]);
	return (counter);
}

int	pointer(unsigned long long int n)
{
	int	num;

	num = 0;
	num += ft_putstr("0x");
	num += hexdecimal(n);
	return (num);
}

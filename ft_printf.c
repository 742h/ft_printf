/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hassaleh <hassaleh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 20:16:11 by hassaleh          #+#    #+#             */
/*   Updated: 2024/01/07 21:55:25 by hassaleh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	identifier(char c, va_list arg)
{
	int	next;

	next = 0;
	if (c == 'c')
		next += ft_putchar(va_arg(arg, int));
	else if (c == 's')
		next += ft_putstr (va_arg(arg, char *));
	else if (c == 'd' || c == 'i')
		next += ft_putnbr(va_arg(arg, int));
	else if (c == '%')
		next += ft_putchar('%');
	else if (c == 'u')
		next += put_udecimal(va_arg(arg, unsigned int));
	else if (c == 'x')
		next += hexdecimal(va_arg(arg, unsigned int));
	else if (c == 'X')
		next += capital_hexdecimal(va_arg(arg, unsigned int));
	else if (c == 'p')
		next += pointer(va_arg(arg, unsigned long long int));
	return (next);
}

int	ft_printf(const char *c, ...)
{
	int		count;
	va_list	arg;

	va_start(arg, c);
	count = 0;
	while (*c)
	{
		if (*c == '%')
		{
			count += identifier(*(++c), arg);
		}
		else
			count += ft_putchar(*c);
		c++;
	}
	va_end(arg);
	return (count);
}

// int main()
// {
// 	int a;

// 	// ft_printf ("(d) %%% d ---> ", a);
// 	// printf ("% d\n", a);

// 	// // ft_printf ("(i) %i ---> ", NULL);
// 	// // printf ("%i\n", NULL);

// 	// ft_printf ("(x) %x ---> ", '\0');
// 	// printf ("%x\n", '\0');

// 	// ft_printf ("(X) %X ---> ", '\0');
// 	// printf ("%X\n", '\0');

// 	// ft_printf ("(s) %s ---> ", "\0a");
// 	// printf ("%s\n", "\0");

// 	// ft_printf ("(c) %c ---> ", '\0');
// 	// printf ("%c\n", '\0');

// 	// ft_printf ("(u) %u ---> ", '\0');
// 	// printf ("%u\n", '\0');

// 	// ft_printf ("(p) %p ---> ", &a);
// 	// printf ("%p\n", &a);

// 	// ft_printf ("() %% ---> ");
// 	// printf ("%%");
// 	return(a);
// }
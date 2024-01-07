/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hassaleh <hassaleh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 19:07:10 by hassaleh          #+#    #+#             */
/*   Updated: 2024/01/07 21:55:28 by hassaleh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include <limits.h>

int				ft_putchar(char c);
int				ft_putnbr(long long n);
int				ft_putstr(char *s);
int				ft_printf(const char *c, ...);
unsigned int	put_udecimal(unsigned long n);
int				hexdecimal(unsigned long long n);
int				capital_hexdecimal(unsigned long long n);
int				pointer(unsigned long long int n);

#endif
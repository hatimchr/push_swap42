/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchair <hchair@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:29:05 by hchair            #+#    #+#             */
/*   Updated: 2024/07/05 04:12:15 by hchair           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_putchar(char c)
{
	int	i;

	i = write(1, &c, 1);
	return (i);
}

int	ft_putstr(char *s)
{
	int	j;

	j = 0;
	if (!s)
	{
		j += ft_putstr("(null)");
		return (j);
	}
	while (s[j] != '\0')
	{
		j += ft_putchar(s[j]);
	}
	return (j);
}

int	ft_putnbr(int n)
{
	int	i;

	i = 0;
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		n *= -1;
		i += ft_putchar('-');
	}
	if (n <= 9)
	{
		i += ft_putchar(n + '0');
	}
	else
	{
		i += ft_putnbr(n / 10);
		i += ft_putnbr(n % 10);
	}
	return (i);
}

int	printer(char c, va_list ap)
{
	int	i;

	i = 0;
	if (c == 'c')
		i += ft_putchar(va_arg(ap, int));
	else if (c == 's')
		i += ft_putstr(va_arg(ap, char *));
	else if (c == 'd')
	{
		i += ft_putnbr(va_arg(ap, int));
	}
	else if (c == 'i')
		i += ft_putnbr(va_arg(ap, int));
	else
		i += ft_putchar(c);
	return (i);
}

int	ft_printf(const char *src, ...)
{
	va_list	ap;
	int		count;

	count = 0;
	va_start(ap, src);
	while (*src != '\0')
	{
		if (*src != '%')
			count += ft_putchar(*src);
		else
		{
			if ((!*(++src)))
				return (count);
			count += printer(*(src), ap);
		}
		src++;
	}
	return (count);
}

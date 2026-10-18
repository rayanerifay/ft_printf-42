/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aredouan <aredouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 22:01:07 by aredouan          #+#    #+#             */
/*   Updated: 2025/11/22 19:04:53 by aredouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print(char c, unsigned long long n)
{
	return (ft_pointeur_hexa(n, c));
}

static int	put_ptr(void *ptr)
{
	int	count;

	count = 0;
	if (ptr == NULL)
		count += ft_putstr("(nil)");
	else
	{
		count += ft_putstr("0x");
		if (count == -1)
			return (-1);
		count += ft_pointeur_hexa((unsigned long long)ptr, 'x');
		if (count == -1)
			return (-1);
	}
	return (count);
}

static int	cases_check(char c, va_list arg)
{
	char	*s;

	if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(arg, int)));
	else if (c == 'c')
		return (ft_putchar(va_arg(arg, int)));
	else if (c == 's')
	{
		s = va_arg(arg, char *);
		if (s == NULL)
			return (ft_putstr("(null)"));
		else
			return (ft_putstr(s));
	}
	else if (c == 'u')
		return (ft_unsigned_putnbr(va_arg(arg, unsigned int)));
	else if (c == 'x' || c == 'X')
		return (ft_print(c, (unsigned long long)va_arg(arg, unsigned int)));
	else if (c == 'p')
		return (put_ptr(va_arg(arg, void *)));
	else if (c == '%')
		return (ft_putchar('%'));
	else
		return (ft_putchar(c));
}

int	ft_printf(const char *str, ...)
{
	va_list	arg;
	int		count;
	int		tmp;

	if (!str || write(1, 0, 0) == -1)
		return (-1);
	va_start(arg, str);
	count = 0;
	while (*str)
	{
		if (*str != '%')
			tmp = ft_putchar(*str);
		else if (!*(++str))
			break ;
		else
			tmp = cases_check(*str, arg);
		if (tmp == -1)
			return (-1);
		count += tmp;
		str++;
	}
	va_end(arg);
	return (count);
}

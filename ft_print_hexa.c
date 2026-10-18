/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aredouan <aredouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 23:48:44 by aredouan          #+#    #+#             */
/*   Updated: 2025/11/15 20:25:54 by aredouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_pointeur_hexa(unsigned long long nbr, char c)
{
	char	*base;
	int		count;

	base = "0123456789abcdef";
	count = 0;
	if (c == 'X')
		base = "0123456789ABCDEF";
	if (nbr >= 16)
	{
		count += ft_pointeur_hexa(nbr / 16, c);
		if (count == -1)
			return (-1);
	}
	else
		count = 0;
	if (ft_putchar(base[nbr % 16]) == -1)
		return (-1);
	count ++;
	return (count);
}

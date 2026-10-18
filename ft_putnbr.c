/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aredouan <aredouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 22:52:15 by aredouan          #+#    #+#             */
/*   Updated: 2025/11/16 15:54:43 by aredouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	long	nb;
	char	c;
	int		count;
	int		fail;

	nb = n;
	count = 0;
	if (nb < 0)
	{
		if (write(1, "-", 1) == -1)
			return (-1);
		nb = -nb;
		count++;
	}
	if (nb >= 10)
	{
		fail = ft_putnbr(nb / 10);
		if (fail == -1)
			return (-1);
		count += fail;
	}
	c = (nb % 10) + '0';
	if (write(1, &c, 1) == -1)
		return (-1);
	return (count + 1);
}

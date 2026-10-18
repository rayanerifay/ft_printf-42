/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_putnbr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aredouan <aredouan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 22:52:15 by aredouan          #+#    #+#             */
/*   Updated: 2025/11/15 20:48:54 by aredouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_unsigned_putnbr(unsigned int n)
{
	char	c;
	int		i;

	if (n >= 10)
	{
		i = ft_unsigned_putnbr(n / 10);
		if (i == -1)
			return (-1);
	}
	else
		i = 0;
	c = (n % 10) + '0';
	if (write(1, &c, 1) == -1)
		return (-1);
	return (i + 1);
}

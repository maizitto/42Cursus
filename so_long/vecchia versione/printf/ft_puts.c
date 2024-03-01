/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puts.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasitto <mmasitto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 15:39:23 by mmasitto          #+#    #+#             */
/*   Updated: 2024/01/14 20:28:43 by mmasitto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	i;

	i = -1;
	if (!s)
		return (ft_putstr("(null)"));
	while (s[++i])
		ft_putchar(s[i]);
	return (i);
}

int	ft_putnbr(int n)
{
	char	*temp;

	temp = ft_itoa(n);
	ft_putstr(temp);
	free(temp);
	return (nlen(n));
}

static int	ft_x_put(long n, int i, char *base)
{
	unsigned int	x;

	x = (unsigned int)n;
	if (x >= 16)
	{
		i = ft_x_put(x / 16, i, base);
		i = ft_x_put(x % 16, i, base);
	}
	else
		i += ft_putchar(base[x]);
	return (i);
}

int	ft_putnbr_base(long n, int type)
{
	char	*base;
	int		count;

	count = 0;
	base = "0123456789abcdef";
	if (!n)
		return (ft_putchar(48));
	if (type == 2)
		base = "0123456789ABCDEF";
	count = ft_x_put(n, count, base);
	return (count);
}

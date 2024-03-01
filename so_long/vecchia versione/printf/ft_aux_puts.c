/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aux_puts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasitto <mmasitto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 13:07:52 by mmasitto          #+#    #+#             */
/*   Updated: 2024/01/15 10:19:58 by mmasitto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	nlen(long n)
{
	int	i;

	i = 0;
	if (n == 0)
		i++;
	if (n < 0)
		i++;
	while (n)
	{
		i++;
		n /= 10;
	}
	return (i);
}

char	*ft_itoa(long n)
{
	char	*ret;
	int		i;

	i = nlen(n);
	ret = ft_calloc(i + 1, sizeof(char));
	if (!ret)
		return (NULL);
	ret[i] = '\0';
	if (n < 0)
		ret[0] = '-';
	else if (n < 10 && n >= 0)
	{
		ret[0] = n + 48;
		return (ret);
	}
	while (--i >= 0 && n)
	{
		if (n < 0)
			ret[i] = (-(n % 10)) + 48;
		else
			ret[i] = (n % 10) + 48;
		n /= 10;
	}
	return (ret);
}

int	ft_u_putnbr(unsigned int n)
{
	char	*temp;

	temp = ft_itoa(n);
	ft_putstr(temp);
	free(temp);
	return (nlen(n));
}

int	ft_reverse_print(char *str)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (str[i])
		i++;
	while (--i > -1)
	{
		len += ft_putchar(str[i]);
	}
	return (len);
}

int	ft_p_putnbr(void *ptr, int i)
{
	unsigned char	*temp;
	int				x;
	int				len;
	uintptr_t		tpt;

	if (!ptr)
		return (ft_putchar('0'));
	tpt = (uintptr_t)ptr;
	x = sizeof(void *) * 2 + 1;
	temp = ft_calloc((x), sizeof(char));
	if (!temp)
		return (0);
	len = 0;
	while (tpt)
	{
		i = tpt & 0xF;
		temp[len] = ("0123456789abcdef")[i];
		tpt >>= 4;
		len++;
	}
	temp[len] = '\0';
	len = ft_reverse_print((char *)temp);
	free(temp);
	return (len);
}

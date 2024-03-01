/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasitto <mmasitto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 12:16:01 by mmasitto          #+#    #+#             */
/*   Updated: 2024/01/10 15:10:35 by mmasitto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	nlen(int n)
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

char	*ft_itoa(int n)
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
/*
int main()
{
	printf("%s\n", ft_itoa(2147483647));
}
*/
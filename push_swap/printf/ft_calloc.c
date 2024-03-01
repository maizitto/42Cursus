/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasitto <mmasitto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 12:46:38 by mmasitto          #+#    #+#             */
/*   Updated: 2024/01/12 18:00:34 by mmasitto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"
#include <stdint.h>
#include <stdio.h>

void	*ft_calloc(size_t count, size_t size)
{
	char			*str;
	size_t			i;
	unsigned long	len;

	str = NULL;
	len = (unsigned long)count * (unsigned long)size;
	if ((count >> 31) % 2 && size)
		return (0);
	if ((size >> 31) % 2 && count)
		return (0);
	if (len >= 1247483424)
		return (0);
	str = (char *) malloc (len);
	if (!str)
		return (NULL);
	i = 0;
	while (i < (len))
	{
		str[i] = 0;
		i++;
	}
	return ((void *)str);
}

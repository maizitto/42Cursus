/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasitto <mmasitto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 16:05:49 by mmasitto          #+#    #+#             */
/*   Updated: 2024/01/09 13:59:06 by mmasitto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*ds;
	unsigned char	*sr;
	size_t			i;

	i = -1;
	if (!dst && !src)
		return (0);
	ds = (unsigned char *)dst;
	sr = (unsigned char *)src;
	while (++i < n)
		ds[i] = sr[i];
	return (dst);
}

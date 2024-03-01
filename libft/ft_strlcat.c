/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasitto <mmasitto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 17:14:25 by mmasitto          #+#    #+#             */
/*   Updated: 2024/01/10 12:07:32 by mmasitto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_strlcat(char *dest, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	len_dst;

	i = 0;
	if (dstsize == 0)
		return ((unsigned int)(ft_strlen(src)));
	if (dstsize < ft_strlen(dest))
		return (dstsize + ft_strlen(src));
	len_dst = ft_strlen(dest);
	while (dstsize > len_dst + i + 1 && src[i])
	{
		dest[i + len_dst] = src[i];
		i++;
	}
	dest[i + len_dst] = '\0';
	return (len_dst + ft_strlen(src));
}

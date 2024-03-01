/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasitto <mmasitto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 15:56:04 by mmasitto          #+#    #+#             */
/*   Updated: 2024/01/11 11:01:16 by mmasitto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t n)
{
	char	*x;
	size_t	i;

	x = NULL;
	x = (char *) b;
	i = 0;
	while (i < n)
	{
		x[i] = c;
		i++;
	}
	return (b);
}

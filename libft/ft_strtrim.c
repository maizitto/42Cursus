/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasitto <mmasitto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 10:02:31 by mmasitto          #+#    #+#             */
/*   Updated: 2024/01/10 16:07:58 by mmasitto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	char_in_set(char val, const char *set)
{
	while (*set)
	{
		if (*set == val)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(const char *source, const char *set)
{
	char	*str;
	int		i;
	size_t	start;
	size_t	end;

	if (!source || !set)
		return (NULL);
	i = 0;
	start = 0;
	end = ft_strlen(source);
	while (source[start] && char_in_set(source[start], set))
		start++;
	while (end > start && char_in_set(source[end - 1], set))
		end--;
	str = (char *)malloc((end - start + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	while (start < end)
		str[i++] = source[start++];
	str[i] = '\0';
	return (str);
}
/*
#include <stdio.h>
int main()
{
        char *ptr;
        ptr = ft_strtrim("tettteeecitttee", "te");
        printf("%s", ptr);
}
*/
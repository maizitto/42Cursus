/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasitto <mmasitto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 21:20:42 by mmasitto          #+#    #+#             */
/*   Updated: 2024/07/12 23:02:13 by mmasitto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

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

static int	count_words(const char *str, char c)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (str[i])
	{
		if (str[i] != c && (str[i + 1] == c || str[i + 1] == '\0'))
			words++;
		i++;
	}
	return (words);
}

static void	new_string(const char *str, int start, int end, char *dest)
{
	int	i;

	i = 0;
	while (i < end)
	{
		dest[i] = str[start + i];
		i++;
	}
	dest[i] = '\0';
}

static void	aux(char **arr, const char *str, char c)
{
	int	i;
	int	j;
	int	z;

	i = 0;
	z = 0;
	while (str[i] && z <= count_words(str, c))
	{
		if (str[i] == c)
			i++;
		else
		{
			j = 0;
			while (str[i + j] != c && str[i + j])
				j++;
			arr[z] = (char *)malloc(sizeof(char) * (j + 1));
			if (!arr[z])
				return ;
			new_string(str, i, j, arr[z]);
			z++;
			i += j;
		}
	}
}

char	**ft_split(const char *str, char c)
{
	char	**arr;
	int		n_words;

	if (!str)
		return (NULL);
	n_words = count_words(str, c);
	arr = ft_calloc(n_words + 1, sizeof(char *));
	if (!arr)
		return (NULL);
	aux(arr, str, c);
	return (arr);
}

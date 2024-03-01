/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasitto <mmasitto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 19:51:10 by mmasitto          #+#    #+#             */
/*   Updated: 2024/03/01 09:50:03 by mmasitto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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

static int	skip_split(const char *str, int i)
{
	int	j;

	j = 0;
	if (str[i + j] == 39)
	{
		j++;
		while (str[i + j] != 39)
			j++;
		return (j);
	}
	else if (str[i + j] == 34)
	{
		j++;
		while (str[i + j] != 34)
			j++;
		return (j);
	}
	return (j);
}

static void	aux(char **arr, const char *str, char c, int i)
{
	int	j;
	int	z;

	z = 0;
	while (str[i])
	{
		if (str[i] == c)
			i++;
		else
		{
			j = 0;
			while (str[i + j] != c && str[i + j])
				j++;
			if (str[i] == 34 || str[i] == 39)
				j = skip_split(str, i) + 1;
			arr[z] = ft_calloc(j + 1, sizeof(char));
			if (!arr[z])
				return ;
			new_string(str, i, j, arr[z]);
			arr[z] = epur(arr[z]);
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
	aux(arr, str, c, 0);
	return (arr);
}

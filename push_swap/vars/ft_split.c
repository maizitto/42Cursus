/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maizitto <maizitto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 19:51:10 by mmasitto          #+#    #+#             */
/*   Updated: 2024/02/04 17:26:19 by maizitto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../push_swap.h"

int	count_words(const char *str, char c)
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
/*
int main()
{
	char *str = "francese";
	char charset = ' ';

	printf("%d\n", count_words(str, charset));

	char **arr = ft_split(str,charset);

	int i = 0;

	while (arr[i])
	{
		printf("%s\n", arr[i]);
		i++;
	}
	printf("%s\n", arr[1]);

	i = 0;
	while (arr[i])
	{
		printf("%s\n", arr[i]);
		free(arr[i]);
		i++;
	}
	//free(arr);
}
*/
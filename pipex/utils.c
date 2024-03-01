/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasitto <mmasitto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 19:02:48 by maizitto          #+#    #+#             */
/*   Updated: 2024/02/29 10:47:57 by mmasitto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_error(void)
{
	perror("Error");
	exit(0);
}

char	*path_finder(char **envp, char *cmd)
{
	char	*path;
	char	**diff_paths;
	int		i;

	i = 0;
	while (!ft_strnstr(envp[i], "PATH", 4))
		i++;
	diff_paths = ft_split(envp[i] + 5, ':');
	i = 0;
	while (diff_paths[i])
	{
		path = ft_strjoin(ft_strjoin(diff_paths[i], "/"), cmd);
		if (access(path, F_OK) == 0)
			return (path);
		free(path);
		i++;
	}
	i = -1;
	while (diff_paths[++i])
		free(diff_paths[i]);
	free(diff_paths);
	return (NULL);
}

void	ft_execute(char **envp, char *argv)
{
	char	**command;
	char	*path;
	int		i;

	i = -1;
	command = ft_split(argv, ' ');
	path = path_finder(envp, command[0]);
	if (!path)
	{
		while (command[++i])
			free(command[i]);
		free(command);
		ft_error();
	}
	if (execve(path, command, envp) == -1)
		ft_error();
}

char	*ft_strnstr(const char *s, const char *to_find, size_t len)
{
	size_t	j;

	if (!*to_find)
		return ((char *)s);
	if (!len || !*s)
		return (NULL);
	while (*s && len > 0)
	{
		if (*s == *to_find)
		{
			j = 0;
			while (j < len && to_find[j] && s[j] == to_find[j])
				j++;
			if (to_find[j] == '\0')
				return ((char *)s);
		}
		s++;
		len--;
	}
	return (0);
}

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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasitto <mmasitto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 20:03:33 by mmasitto          #+#    #+#             */
/*   Updated: 2024/08/04 12:17:35 by mmasitto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	init_elements(t_game *game)
{
	game->elements.collectibles = (t_sprite *)
		malloc(sizeof(t_sprite) * game->elements.c_count);
	if (!game->elements.collectibles)
		quit(MALLOC_ERR, 1);
	game->elements.doors = (t_sprite *)
		malloc(sizeof(t_sprite) * game->elements.d_count);
	if (!game->elements.doors)
		quit(MALLOC_ERR, 1);
	game->elements.enemies = (t_sprite *)
		malloc(sizeof(t_sprite) * game->elements.e_count);
	if (!game->elements.enemies)
		quit(MALLOC_ERR, 1);
}

bool	path_validator(char *path)
{
	int	i;

	i = ft_strlen(path) - 1;
	if (path[i] != 'b' || path[i - 1] != 'u' || path[i - 2] != 'c'
		|| path[i - 3] != '.')
		return (1);
	return (0);
}

static char	**aux_store_file(char *str, int fd, int i, char **file)
{
	char	*line;
	int		j;

	j = 0;
	line = NULL;
	fd = open(str, O_RDONLY);
	if (fd < 0)
		quit(OPEN_ERR, 1);
	file = malloc(sizeof(char *) * (i + 1));
	if (!file)
		quit(MALLOC_ERR, 1);
	while (j < i)
	{
		line = get_next_line(fd);
		file[j] = ft_strdup(line);
		if (!file[j])
			quit(MALLOC_ERR, 1);
		j++;
	}
	file[j] = NULL;
	close(fd);
	return (file);
}

char	**store_file(char *str)
{
	int		i;
	int		fd;
	char	**file;
	char	*line;

	fd = 0;
	i = 0;
	fd = open(str, O_RDONLY);
	if (fd < 0)
		quit(OPEN_ERR, 1);
	line = get_next_line(fd);
	while (line)
	{
		i++;
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	file = NULL;
	file = aux_store_file(str, 0, i, file);
	return (file);
}

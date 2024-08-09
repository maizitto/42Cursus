/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmasitto <mmasitto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 20:03:33 by mmasitto          #+#    #+#             */
/*   Updated: 2024/08/09 10:34:09 by mmasitto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

// void	init_elements(t_game *game)
// {
// 	game->elements.collectibles = (t_sprite *)
// 		malloc(sizeof(t_sprite) * game->elements.c_count);
// 	if (!game->elements.collectibles)
// 		quit(MALLOC_ERR, 1);
// 	game->elements.doors = (t_sprite *)
// 		malloc(sizeof(t_sprite) * game->elements.d_count);
// 	if (!game->elements.doors)
// 		quit(MALLOC_ERR, 1);
// 	game->elements.enemies = (t_sprite *)
// 		malloc(sizeof(t_sprite) * game->elements.e_count);
// 	if (!game->elements.enemies)
// 		quit(MALLOC_ERR, 1);
// }

void	init_elements(t_game *game)
{
	(void)game;
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

static void	aux_store_file(char *str, int fd, int i, t_game *game)
{
	char	*line;
	int		j;

	j = 0;
	line = NULL;
	fd = open(str, O_RDONLY);
	if (fd < 0)
		quit(NULL, OPEN_ERR, 1);
	game->file = malloc(sizeof(char *) * (i + 1));
	if (!game->file)
		quit(NULL, MALLOC_ERR, 1);
	while (j < i)
	{
		line = gnl(fd);
		game->file[j] = ft_strdup(line);
		free(line);
		if (!game->file[j])
			quit(NULL, MALLOC_ERR, 1);
		j++;
	}
	game->file[j] = NULL;
	gnl(-2);
	close(fd);
}

void	store_file(t_game *game, char *str)
{
	int		i;
	int		fd;
	char	*line;

	fd = 0;
	i = 0;
	fd = open(str, O_RDONLY);
	if (fd < 0)
		quit(NULL, OPEN_ERR, 1);
	line = gnl(fd);
	while (line != NULL)
	{
		free(line);
		i++;
		line = gnl(fd);
	}
	if (line)
		free(line);
	close(fd);
	aux_store_file(str, 0, i, game);
	gnl(-2);
}
